/**
 * Your name:       Michael Mesi
 * Your Z-ID:       z1910569
 * section number:  PE1
 * Assignment number: 3
 * Due date:        3/21/2021
 */

#include"assign3.h"
#include"process.h"

using std :: cerr;
using std :: cout;
using std :: endl;

std :: queue<process*> Entry;   //Acts as memory
std :: queue<process*> Ready;   //ready queue
std :: queue<process*> Input;   //Input Queue
std :: queue<process*> Output;  //output queue

process *Active = nullptr;      //active process pointer
process *IActive = nullptr;     //Active input process pointerr
process *OActive = nullptr;     //active output process pointer              
int terminated=0;               //number of terminated processes
int total_wait_time =0;
int main(int argc, char **argv)
{
    bool idleflag = false; //for printing the idle time message. if its true then its idling and won't continue to print the message
    char * chunk;       //keeps track of a chunk of the string. 
    std :: string filename(argv[1]);            //set command line argument as input filename
    std :: ifstream infile(filename, std::ios::in); //open the file as input
    int IDnum =100;         //set ID number to start at 100;
    if(infile)          //if it was opened correctly
    {   
        char line1[256];    //reads in first line
        char line2[256];    //reads in second line. 
        std :: string temp; //temporary string
        while(infile.getline(line1, 256))   //while getlin() isn't false
         {
            process *ptr = new process;     //create temp process pointer to push into queue
            
            chunk = strtok(line1, " ");     //get first token
            temp = chunk;                   //set temp string to new token to compare with "STOPHERE"
            if((temp  == "STOPHERE"))
            {
               break;   //if STOPHERE is found break loop
            }
            else{
                ptr->processName = chunk;   //else set process name to token

                chunk = strtok(nullptr, " ");   //get next token
                ptr->arrivalTime = atoi(chunk); //set arrival time to int version off token
                ptr->processID=IDnum;           //set IDnum
                memset(line1,'\0', 256);     //reset string
               
                //read the next input line 
                infile.getline(line2, 256); //get the next line
                chunk = strtok(line2, " "); //get first oken of that line
                
                for(int i =0; i < 10  && chunk !=NULL; i++){    //until the end of the string is reached
                    
                    ptr->history[i][0] = chunk[0];        //set value   of letter
                    chunk = strtok(nullptr, " ");          //get next token
                    ptr->history[i][1] = atoi(chunk);     //set value of value
                    chunk = strtok(nullptr, " ");           //get next token
                }
                ptr->Subscript = 0;                     //set subscript to 0
                Entry.push(ptr);                        //push into the entry queue

                 memset(line2,'\0', 256);     //reset string
            }   
            
            IDnum ++;   //increment IDNum
        }
    }
    else    //if file could not be opened print error and abort
    {
        cerr << "The file could not be opened\n";
        exit(1);
    }
    /*****************************************************
     * at this point the processes should be created and 
     * ready for use and we can start the main loop;
     * ***************************************************/
   

    infile.close(); //close file after input
    timer =0;   //initialize timer to 0
    do          //main loop
    {   
        //Now IN_PLAY should contain every possible active/ready to use process, and we can check if we need more
        while(!Entry.empty() && Entry.front()->arrivalTime <= timer && IN_USE > IN_PLAY)
        {
            cout << "\nProcess " << Entry.front()->processID << " Moved from Entry queue to Ready Queue at time " << timer << endl << endl;  
            Ready.push(Entry.front());  //push process from entry to ready
            Entry.pop();                //remove from entry
            IN_PLAY++;                  //incriment in play
            Ready.front()->startWait = timer;   //start the wait timer on that process
        
        }
        
        if(Active == nullptr)   //if active is idle
        {
            if(!Ready.empty() && IN_USE >= IN_PLAY) //look for a process in the ready queue
            {
                Active = Ready.front(); //set active
                Ready.pop();    //remove from readdy
                Active->WaitTime += timer- Active->startWait;   //calciulate wait timer
                Active->CPUTimer = Active->history[Active->Subscript][1];   //set CPUTimer
                IN_PLAY++;      //calculate in play
                idleflag = false;   //set idleflag to false to indicate that ACtive is no longer idle
            }
            else if(IN_USE > IN_PLAY)   //if ready is empty, look in entry
            {
                if(!Entry.empty())      //if entry is not empty, take from it
                {
                    Active = Entry.front(); //set active
                    Entry.pop();    //remove from entry
                    Active->WaitTime += timer- Active->startWait;   //set waitTime
                    Active->CPUTimer = Active->history[Active->Subscript][1];   //set CPUTimer
                    IN_PLAY++;      //incriment in play.
                    idleflag = false;   //set idleflag to false
                }
                else    //else increase idle timer
                {
                    if(idleflag)    //don't want to repetedly print message
                    {
                        idleTime++; 
                    }
                    else
                    {
                        cout << "\n\nActive is 0, so we have some idle time\n\n";   //print idle message
                        idleTime++;
                        idleflag = true;    
                        }
                }
            }

        }
        if(Active !=nullptr)    //if Active is set
        {
            //decriment cputimer and incriment cputotal 
            Active->CPUTimer--;
            Active->CPUTotal++;
            //check if cpu is done
            if(Active->CPUTimer==0){
                
                Active->CPUCount++;     //incriment cpu burst count
                Active->Subscript++;    //incriment subscript for the next type of burst
                switch(Active->history[Active->Subscript][0])   //check what that type of burst may be
                {
                    case 'I':           //if its and input burst, push it unto the input queue
                        Input.push(Active);
                        break;
                    case 'O':           //if it is an output burst, push it unto the output queue
                        Output.push(Active);
                        break;
                    default:    
                        EndProcess();   //if its any other case, the process must need to be terminated

                }

                Active->startWait = timer;  //set the start time for the process waiting in queue.
                Active =nullptr;            //set active to a nullptr
            }
        }
        //start of the IActive conditional statements
        if(IActive == nullptr && !Input.empty())
        {

            IActive = Input.front();    //set IActive
            Input.pop();                //remoce from queue
            IActive->WaitTime += timer- IActive->startWait; //increment waitime for IActive
            IActive->IOTimer = IActive->history[IActive->Subscript][1]; //set IOTimer from Histrory


        }
        else if(IActive !=nullptr)
        {
            //increment time variables.
            IActive->IOTimer--;
            IActive->ITotal++;

            if(IActive->IOTimer==0){    //if it us finished

                IActive->ICount++;   //add one to burst count
                IActive->Subscript++;   //add one to subscript count
                IActive->startWait = timer; //set wait timer
                Ready.push(IActive);    //push unto ready queue
                IActive=nullptr;        //set IActive to null
            }

        }
        //start  the OActive conditional statements
        if(OActive == nullptr && !Output.empty())
        {
            OActive = Output.front();   //set OACtive
            Output.pop();               //remove from queue
            OActive->WaitTime += timer- OActive->startWait; //set wait timer of Oactive
            OActive->IOTimer = OActive->history[OActive->Subscript][1]; //set teh IOtimer with History

        }
        else if(OActive !=nullptr)
        {
            //increment time variables.
            OActive->IOTimer--;
            OActive->OTotal++;

            if(OActive->IOTimer==0){    //if it us finished

                OActive->OCount++;   //add one to burst count
                OActive->Subscript++;   //add one to subscript count
                OActive->startWait = timer; //set wait timer
                Ready.push(OActive);    //push unto ready queue
                OActive=nullptr;        //set OActive to null
            }

        }

        if(timer % HOW_OFTEN ==0)   //if system state need to be printed do so.
        {
            sysState();
        }

        timer++;    //increment timer
        in_Play();  //set the amount of processes in play

    }while(!done());


    cout << endl << endl << "Total runtime of " << timer << endl;   //print total runtime
    cout <<"Processes in play: " << IN_PLAY << endl;                //print remaining processes in play
    cout << "Number of terminated processes: " << terminated << endl;   //print number of terminated processes
    cout << "Average waiting time for all terminated processes = " << total_wait_time  / terminated << endl; //print average waiting time for each terminated process
    sysState(); //print the system state

    return 0;
}

//function checks to see if all of the queues are empty and on that event it returns true 
bool done()
{
    //if there is nothing left to be done return true
    if(timer >= MAX_TIME || (Entry.empty() && Ready.empty()&& Input.empty() && Output.empty() &&  IN_PLAY==0 ))
    {
        return true;
    }
    else    //else return false   
        return false;
}

void in_Play()
{
        IN_PLAY = Ready.size() + Input.size() + Output.size();  //if there is anything in these queues they will be added to the In play count

        if(Active != nullptr)   //if there is an active process, add to in play count
            IN_PLAY++;
        if(IActive != nullptr)  //if there is an Iactive process, add to in play count
            IN_PLAY++;    
        if(OActive != nullptr)  //if there is an Oactive process, add to in play count
            IN_PLAY++;

}
//prints out necessary information upon the ending of a process
void EndProcess()
{
    cout << "\tProcess "<< Active->processID << " has ended \n";    //print ending process ID
    cout << "Name:\t" << Active->processName << endl;               //print ending process Name
        cout << "Process ended at time " << timer << endl;          //print time process ended

    cout << "Total CPU time = " << Active->CPUTotal << " in "       //print ending process cpu time
         <<Active->CPUCount << " CPU Bursts" << endl;               //print ending process cpu burst count

    cout << "Total input time = " << Active->ITotal << " in "       //print ending process input burst time
         <<Active->ICount << " input Bursts" << endl;               //print ending process input burst count

    cout << "Total output time = " << Active->OTotal << " in "      //print ending process output burst time
         <<Active->OCount << " Output Bursts" << endl;              //print ending process output burst count

    cout << "Time spent waiting: " << Active->WaitTime  << endl;    //print ending process wait time

    IN_PLAY--;  //decriment processes in play
    terminated++;   //incriment terminated process count
    total_wait_time += Active->WaitTime;    //add wait time to total wait time for ended processes

}
/*
*Prints out the state if the system and its relevent information
*/
void sysState()
{
    std :: deque<process*> temp; //for holding the constents of the queue to be printed

    //print out all the active process ID's
    cout << endl << "Status at time = "  << timer << endl;  //print out time
    if(Active!=nullptr)
    
        cout << "Active is: " << Active->processID << endl; //Active process
    else
        cout << " Active is: 0\n";
    if(IActive!=nullptr)
        cout << "IActive is: " << IActive->processID << endl;   //active input process
    else
        cout << "IActive is: 0\n";
    if(OActive!=nullptr)
        cout << "OActive is: " << OActive->processID << endl;   //active output process
    else
        cout << "OActive is: 0\n";

    //now print out the contents of all queues...

    //printing the Entry queue
    cout << "Contents of the Entry Queue: \n";  //print the contents of the entry queue
    if(Entry.empty())       //if empty print corresponding statement
    {
            cout << "{empty}\n";
    }
    else
    {
        while(!Entry.empty())   //until queue is empty, push unto temporary deque and pop to get next process 
        {
            cout << Entry.front()->processID << "\t";
            temp.push_back(Entry.front());
            Entry.pop();
        }
        cout << endl;
        while(!temp.empty())    //then push from  temp back unto the queue
        {
            Entry.push(temp.back());
            temp.pop_back();
        }
    }

    //printing ready queue
    cout << "Contents of the Ready Queue: \n";
    if(Ready.empty())   //if empty print corresponding statement
    {
        cout << "{empty}\n";
    }
    else{
        while(!Ready.empty())   //until queue is empty, push unto temporary queue and pop to get next process 
        {
            cout << Ready.front()->processID << "\t";
            temp.push_back(Ready.front());
            Ready.pop();
        }
        cout << endl;
        while(!temp.empty()) //then push from  temp back unto the queue
        {
            Ready.push(temp.back());
            temp.pop_back();
        }
    }
    //printing Input queue
    cout << "Contents of the Input Queue: \n";
    if(Input.empty())   //if empty print corresponding statement
    {
        cout << "{empty}\n";
    }
    else{
        while(!Input.empty())   //until queue is empty, push unto temporary queue and pop to get next process 
        {
            cout << Input.front()->processID << "\t";
            temp.push_back(Input.front());
            Input.pop();
        }
        cout << endl;
        while(!temp.empty())    //then push from  temp back unto the queue
        {
            Input.push(temp.back());
            temp.pop_back();
        }
    }
    //printing output queue
    cout << "Contents of the Output Queue: \n";
        if(Output.empty())  //if empty print corresponding statement
    {
            cout << "{empty}\n";
    }
    else{
        while(!Output.empty())  //until queue is empty, push unto temporary queue and pop to get next process 
        {
            cout << Output.front()->processID << "\t";
            temp.push_back(Output.front());
            Output.pop();
        }
        cout << endl;
        while(!temp.empty())    //then push from  temp back unto the queue
        {
            Output.push(temp.back());
            temp.pop_back();
        }

    }
    cout << endl;
}

