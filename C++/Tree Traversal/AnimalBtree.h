
#ifndef Q1_H_INCLUDED
#define Q1_H_INCLUDED

#include "node.h"       //Header file containg the template Node class
#include <iostream>
#include <string>


using namespace std;
class Btree{                            //Binary tree class that creates a Binary tree whose leaf nodes hold animal names, and the other nodes hold questions.

public:
 Btree();                               //constructor.
    void Insert(Node<string>* &ptr);    //function that is called on failure of finding an animal and inserts the animal, a question to differentiate the animal added and the animal closest to it, and its answer to that question.

    void Game();                        //asks the user if the questions in the tree until it hits the end, if the animal was not correct, calls insert to add the animal,
                                        //the specifying question, and the animals answer to the question

    bool isleaf(Node<string> *ptr);     //Checks if it is a leaf to see if it should ask if its the animal.

private:
Node<string>* root;                     //root of tree



};

#endif  //Q1_H_INCLUDED
