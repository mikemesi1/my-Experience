#include <openssl/evp.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {

	if(argc != 2){
		cout << "Usage: ./Message_Digest infile" << endl;
		exit(1);
	}

   // hash value
   unsigned char md_value[EVP_MAX_MD_SIZE];
   unsigned int md_len;

   // for the input file
   char * buffer = new char [4096];
   ifstream myfile (argv[1]);

	// for time
	int hashing = 0;
	struct timespec start, stop;
	srand (time(NULL));

   // setup and create context
   EVP_MD_CTX *mdctx;
   mdctx = EVP_MD_CTX_create();


   // initialize hash function
   EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
      //start the clock
   clock_gettime(CLOCK_REALTIME, &start);
   // Opening the file
   if(myfile.is_open())
   {
	   while(!myfile.eof())
	   {
		   myfile.read(buffer, 1);

		   // feed data to hash function
		   if(myfile.gcount() != 0){
			   EVP_DigestUpdate(mdctx, buffer, strlen(buffer));
		   }
	   }
	   myfile.close();
   }

   // get hash value
   EVP_DigestFinal_ex(mdctx, md_value, &md_len);

   //end the clock
   clock_gettime(CLOCK_REALTIME, &stop);

//print out the message digest
   cout << "Message digest is: ";
   for(unsigned int i = 0; i < md_len; i++)
  	  cout << hex << setfill('0') << setw(2) << (int) md_value[i];
   cout << endl;

   long start_time = start.tv_sec * 1000000000 + start.tv_nsec ;
   long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
   hashing += stop_time - start_time;

   cout << "Time used for hashing: " << dec << (hashing/1000) << " microseconds\n";

   // cleanup
   EVP_MD_CTX_destroy(mdctx);
   return 0;
}

