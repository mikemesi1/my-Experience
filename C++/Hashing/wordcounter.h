#ifndef WORDCOUNTER_H_INCLUDED
#define WORDCOUNTER_H_INCLUDED

#include<iostream>
#include<fstream>   //for input file.
#include<string>    //for use of stl string.
#include<vector>    //for stl vector.
#include<locale>    //for use of isalpha
#include<list>      //for use of stl list.

using namespace std;


int tblsize =3989;

struct wordcount        //struct to hold the amount of times a word was used in the file, and the word itself.
{
    int counter;        //counter for word usage.
    string word;        //the word in file.

    wordcount(const int &c=0, const string &w =""):counter(c), word(w){counter=c;word=w;}   //constructor
};





class HT
{
public:
    HT();   //constructor
    void processline(string &s);    //processes the string passed in and breaks it down into individual words while removing punctuation.
    void printtable();              //prints the entire hash table in an ordered fashion, displaying the words and their amount in the file.
    int hashfunc(string &s);        //function to generate the hash value.

private:
    vector<list<wordcount>> words;      //the hash table using open hashing and separate chaining to resolve collisions.
    vector<wordcount*> vp;
};



#endif // WORDCOUNTER_H_INCLUDED
