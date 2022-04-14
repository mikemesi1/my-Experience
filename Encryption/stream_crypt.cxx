#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

void handleErrors() {
  ERR_print_errors_fp(stderr);
  abort();
}

int main(int argc, char **argv) {

  char* filename = argv[2];	//input file name
  std :: ifstream infile;	//input file
  infile.open(filename);	//open input file
  // prepare key and IV
  unsigned char newkey[8];	//new key for its hex equivelent
  unsigned char *key = (unsigned char*)argv[1];	//key taken from input file
  //encrypt variables
  EVP_CIPHER_CTX *ctx;
  int len;
  int ciphertext_len;
  unsigned char iv[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
					     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };	
  char *buffer= new char[4096];
  unsigned char ciphertext[4096];
  struct timespec start, stop;
  srand(time(NULL));

  string fname = filename;	//set fname for making new file
  
  //converting key to hex value
for (int i = 0; i+1 < 16; i += 2)
{
    unsigned char c1 = (key[i]);
    unsigned char c2 = (key[i+1]);
    
    int hexval=0;
    //match char value to hex equivelent
    switch(c1){
		case 'a':
			hexval = 10 * 16;

			break;
		case 'b':
			hexval = 11 * 16;

			break;
		case 'c':
			hexval = 12 * 16;

			break;
		case 'd':
			hexval = 13 * 16;

			break;
		case 'e':
			hexval = 14 * 16;

			break;
		case 'f':
			hexval = 15 * 16;

			break;
		case '9':
			hexval = 9 * 16;

			break;
		case '8':
			hexval = 8 * 16;

			break;
		case '7':
			hexval = 7 * 16;

			break;
		case '6':
			hexval = 6 * 16;

			break;
		case '5':
			hexval = 5 * 16;

			break;
		case '4':
			hexval = 4 * 16;

			break;
		case '3':
			hexval = 3 * 16;

			break;
		case '2':
			hexval = 2 * 16;

			break;
		case '1':
			hexval = 1 * 16;

			break;																											
		default:
			hexval = 0;

    }
        switch(c2){
		case 'a':
			hexval += 10;

			break;
		case 'b':
			hexval += 11;
			break;
		case 'c':
			hexval += 12;

			break;
		case 'd':
			hexval += 13;

			break;
		case 'e':
			hexval += 14;

			break;
		case 'f':
			hexval += 15;
			break;
		case '9':
			hexval += 9;
			break;
		case '8':
			hexval += 8;
			break;
		case '7':
			hexval += 7;
			break;
		case '6':
			hexval += 6;
			break;
		case '5':
			hexval += 5;
			break;
		case '4':
			hexval += 4;
			break;
		case '3':
			hexval += 3;
			break;
		case '2':
			hexval += 2;
			break;
		case '1':
			hexval += 1;
			break;																											
		default:
			hexval += 0;		
			
    }

    newkey[i/2] = hexval;	//set newiv to iv hex equivelent
}			     
					 
    // Create and initialise the context 
  if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

  // Initialise the encryption operation. 
  if(1 != EVP_EncryptInit_ex(ctx, EVP_rc4(), NULL, newkey, iv)) handleErrors();

  if(!infile)
  {
	cerr << "File could not be opened\n";
	exit(-1);
  }
  
  std :: fstream outfile;	//create output file
  
  outfile.open(fname + ".crypt", ios :: out);	//set up the output file for printing.
  clock_gettime(CLOCK_REALTIME, &start);		//start timer
  
  // Message to be encrypted */
  while(!infile.eof())
  {
	  infile.read(buffer, 4096);
	  if(infile.gcount()!=0)
	  {
		  if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, (reinterpret_cast<unsigned char *>(buffer)), infile.gcount())) handleErrors();
				ciphertext_len = len;
				outfile << std :: hex << ciphertext;
	  }
  }

  // Finalise the encryption. Further ciphertext bytes may be written at this stage.
  if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
  ciphertext_len += len;
  
  clock_gettime(CLOCK_REALTIME, &stop);		//stop timer
  
  //calculate encryption time
  long all=0;
  long start_time = start.tv_sec * 1000000000 + start.tv_nsec ;
  long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
  all += stop_time - start_time;	
  //print encryption time
  cout << "Average time used for encrypting " << std :: dec << (all/1000) << " microseconds\n";
  outfile << std :: hex << ciphertext;
  /* Clean up */
  EVP_CIPHER_CTX_free(ctx);


  // Do something useful with the ciphertext here 

  return 0;
}

