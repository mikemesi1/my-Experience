#include "node.h"
#include<iostream>
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


class linkedList
{
public:
    linkedList(){header=NULL;};
    void Insert(Node* &p, const string &newkey, const int &newdata);            //helper function to simplify insertion where it can.
    void _Delete(Node* &ptr);                                                   //helper function to simplify deletion where it can.
    void Insert_Last(const string &newkey, const int &newdata);                 // Adds an element at the end of the list.
    void Insert_First(const string &newkey, const int &newdata);                // Adds an element at the start of the list
    void Delete_Last();                 // Deletes an element from the end of the list.
    void Delete_First();                // Deletes an element from the start of the list.
    void Insert_After(const string &kl,const string newkkey, const int newdata);                // Adds an element after an item of the list.
    void Delete( const string &kl);                      //− Deletes an element from the list using the key.
    void Display_forward();             // Displays the complete list in a forward manner.
    void Display_backward();            // Displays the complete list in a backward manner.

private:
    Node* header;                       //pointer to head of list.
};



#endif // LINKEDLIST_H_INCLUDED
