#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include<string>
//#include<iostream>
using namespace std;
class Node
{
    friend class linkedList;
public:
    Node();    //Constructor
private:

    int data;          //integer data
    string key;        //key to search for
    Node* prev;        //pointer to previous node
    Node* next;        //pointer to next node

};
Node ::Node()
{
    data =-999;
    key="";
    prev = nullptr;
    next=nullptr;
}
#endif // NODE_H_INCLUDED
