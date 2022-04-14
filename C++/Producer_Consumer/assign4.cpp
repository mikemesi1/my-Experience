#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <iomanip>

#define NUM_THREADS     4   //number of each type of thread allowed(producer/consumer)
#define BUFFER_SIZE     10  //the max size of the buffer
int cookie_count = 0;       //the count of "elements" in the buffer
pthread_mutex_t mutexBuffer;   //mutex
sem_t full;                     //full semaphore
sem_t empty;                    //empty semaphore

int insert_item(int threadid)   //inserts item into buffer
 {
    long tid;
    tid = (long)threadid;
    pthread_mutex_lock(&mutexBuffer);   //lock
    
    cookie_count++;                     //increment cookie count
    printf("Producer #%ld inserted a cookie.",tid );    //print tid and message
    printf("total: %ld\n", cookie_count);               //print cookie count

    pthread_mutex_unlock(&mutexBuffer); //unlock    

 }
 //removes items from buffer
int remove_item(int threadid)
 {
    long tid;   
    tid = (long)threadid;   //thread id
    pthread_mutex_lock(&mutexBuffer);   //lock

    cookie_count--;         //increment cookie count
    printf("Consumer #%ld removed a cookie.",tid ); //print consumer message and tid
    printf("total:  %ld\n", cookie_count);          //print cookie count

    pthread_mutex_unlock(&mutexBuffer);         //unlock

 } 

void *producer(void *param)//producer for buffer
{
    int i =0;
    long tid = (long)param; //set tid

    do {
        sem_wait(&empty);   //if full, wait
        
        insert_item(tid);   //insert into buffer

        sem_post(&full);    //increment full
    
        sleep(1);   //sleep for one secons
        i++;        //increment i
    } while (i < 5);
} 

void *consumer(void *param) //consumer for buffer
{
    long tid = (long)param; //set tid
    int i = 0;  
    do{
        sem_wait(&full);    //wait if theres nothing

        remove_item(tid);   //remove from buffer
        
        sem_post(&empty);   //increment empty
        
        sleep(1);           //sleep for one second
        i++;                //increment i
    } while (i < 5);
}

int main()
{
    pthread_t pthreads[NUM_THREADS];    //producer threads
    pthread_t cthreads[NUM_THREADS];    //consumer threads
    pthread_mutex_init(&mutexBuffer, NULL); //initialize mutex
    int rc; 
    sem_init(&empty, 0, BUFFER_SIZE);   //initialize empty semaphore
    sem_init(&full, 0, 0);              //initialize full semaphore

    long t;                         
    for(t=0; t<NUM_THREADS; t++){   //create threads and produce/consume
        rc = pthread_create(&pthreads[t], NULL, &producer, (void *)t);  //create producer
        if (rc){    //on error print message and exit
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
        rc = pthread_create(&cthreads[t], NULL, &consumer, (void *)t);  //create consumer 
        if (rc){    //on error print message and exit
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    int i = 0;
    while(i < NUM_THREADS){ //wait for all threads to be done
        pthread_join(cthreads[i], NULL);
        i++;
    }
    i=0;
    while(i < NUM_THREADS){ //wait for all threads to be done
        pthread_join(pthreads[i], NULL);
        i++;
    }
    std :: cout << "All threads are done\n";

    sem_destroy(&empty);    //destroy empty
    sem_destroy(&full);     //destroy full
    pthread_mutex_destroy(&mutexBuffer);    //destroy mutex
    pthread_exit(NULL);     //exit
    std :: cout << "All resources cleaned up\n";
    return 0;
}