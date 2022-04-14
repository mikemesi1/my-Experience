#include "linkedList.h"     //Header file containing the linked list class and other necessary files.


using namespace std;


int main()
{
    string key="";

    linkedList L;

    L.Insert_First("aaa",1 );       //Building list by inserting at the beginning.
    L.Insert_First("aab",2 );
    L.Insert_First("aba",3 );
    L.Insert_First("abb",4 );
    L.Insert_First("baa",5 );
    L.Insert_First("bab",6 );
    L.Insert_First("bba",7 );
    L.Insert_First("bbb",8 );
    L.Insert_First("aac",9 );
    L.Insert_First("aca",10);
    L.Insert_First("caa",11);

    L.Display_forward();        //displaying the list in a forward manner.

    cout<<"deleting the four numbers following the number with key 'aaa'\n\n";
    L.Delete("aab");
    L.Delete("aba");
    L.Delete("baa");
    L.Delete("bab");

    L.Display_forward();


    cout<<"\n\nInserting 100 with key 'kewl' after number with key 'bab'\n\n";
    L.Insert_After("bab","kewl", 100);                              //inserting after a specific
    cout<<"Inserting 17 with key 'last' at the end of list.\n\n";
    L.Insert_Last("last", 17);                                      //inserting at back of list.


    cout <<"inserting a bunch of keys and numbers at the back of the list.\n";
    L.Insert_Last("this", 13);
    L.Insert_Last("is", 14);
    L.Insert_Last("a", 15);
    L.Insert_Last("test", 16);
    L.Insert_Last("dri", 17);
    L.Insert_Last("ver", 18);
    L.Insert_Last("for", 19);
    L.Insert_Last("show", 20);
    L.Insert_Last("ing", 21);
    L.Insert_Last("it", 22);
    L.Insert_Last("works", 23);
    L.Insert_Last("", 24);
    L.Display_forward();
    cout<<"removing the last number with a blank key.\n\n";
    L.Delete_Last();
    L.Display_forward();

    cout <<"removing some numbers from the front\n\n";
    for(int i=0;i<13;i++)
        L.Delete_First();
    L.Display_forward();

    L.Display_backward();




    return 0;
}

void linkedList:: Insert(Node* &p, const string &newkey, const int &newdata)        //Inserts a node at following the node the passed in pointer is pointing to.
{
    if(header==NULL)                    //if list is empty.
    {
        header = new Node;
        header->next=NULL;
        header->prev =NULL;
        header->key=newkey;
        header->data=newdata;

    }

    else                            //if there exists at least one node in list.
    {
        Node* temp =new Node;
        temp->key =newkey;
        temp->data=newdata;

        temp->next=p->next;
        temp->prev=p;
        if(p->next!=NULL)       //if it is the last node in list don't try to access any data on the NULL.
            p->next->prev=temp;
        p->next=temp;
    }

}


void linkedList::Insert_Last(const string &newkey, const int &newdata)                 // Adds an element at the end of the list.
{
    Node* ptr=header;
    while(ptr->next!=NULL)
        ptr=ptr->next;

    Insert(ptr, newkey, newdata);
}
void linkedList::Insert_First(const string &newkey,const int &newdata )                // Adds an element at the start of the list
{
    if(header==NULL)            //if list is empty create a new node and point the header at it.
    {
        header = new Node;
        header->next=NULL;
        header->prev =NULL;
        header->key=newkey;
        header->data=newdata;

    }
    else        //otherwise put the new Node at the beginning off the existing list.
    {
    Node* temp =new Node;
        temp->key =newkey;
        temp->data=newdata;

        temp->next=header;
        temp->prev=NULL;
        header->prev=temp;
        header=temp;
    }
}


void linkedList::_Delete(Node* &ptr)        //takes a pointer and deletes the node it points to while preserving the integrity of the list.
{
    Node* p=ptr;

    if(header==p)                           //if the header was passed in
        header=header->next;
    else
        p->prev->next=p->next;

    if(p->next!=NULL)                   //if its NULL don't try to access data.
        p->next->prev=p->prev;
    p->next=NULL;
    p->prev=NULL;
    delete(p);
}


void linkedList::Delete_Last()                 // Deletes an element from the end of the list.
{

Node* ptr=header;
    while(ptr->next!=NULL)            //moves through list until it hits the last node of list.
        ptr=ptr->next;
    _Delete(ptr);                   //calls delete to delete the last node in list.
}


void linkedList::Delete_First()                // Deletes an element from the start of the list.
{
    _Delete(header);                            //passes header to _delete() to remove first node in list.
}


void linkedList::Insert_After(const string &kl,const string newkey, const int newdata)                // Adds an element after an item of the list.
{
        Node* ptr =header;
    if(header!=NULL)        //if list is not empty.
    {
        while(ptr!=NULL)    //until it hits the end, search for the key to insert after.
        {
            if(ptr->key ==kl)   //if found, insert and break loop.
            {
              Insert(ptr, newkey, newdata);
              break;
            }
            else                //otherwise keep looking.
            {
                if(ptr->next!=NULL)
                ptr=ptr->next;


            }
            if(ptr==NULL)           //if it reaches the end without finding the key.
                cout<<"Sorry, couldn't find that key.\n\n";

        }
    }
    else    //if list is empty create a new node and have the header point to it.
    {
            cout<<"The list is empty. creating node at start.\n";
            Insert(header, newkey, newdata);
    }
}


void linkedList::Delete(const string &kl)                      //Deletes an element from the list using the key.
{
        Node* ptr =header;
    if(header!=NULL)        //if list is not empty.
    {
        while(ptr!=NULL)         //until it hits the end, search for the key to delete.
        {
            if(ptr->key ==kl)
            {
              _Delete(ptr);             //if found, delete and break loop.
              break;
            }
            else         //otherwise keep looking.
            {
                if(ptr->next!=NULL)
                    ptr=ptr->next;


            }
            if(ptr==NULL)//if it reaches the end without finding the key.
                cout<<"Sorry couldn't find that key\n";
        }
    }
    else        //if the list is empty do nothing.
    {
            cout<<"The list is empty. Nothing to delete.\n";
    }
}


void linkedList::Display_forward()             //Displays the complete list in a forward manner.
{
    cout<<"------------Display List Forwards------------\n\n==============================================\n";
    Node* p=header;
    if(p!=NULL){
    while(p!=NULL)          //until it hits the end of the list. print the key, and its corresponding number
    {
        cout<< "\tKey:    "<< p->key << "\t holds the number " << p->data << endl;
        p=p->next;
    }
    cout<<"\n\n";
    }
    else
        cout<< "There is no list to print\n\n";
}


void linkedList::Display_backward()            //Displays the complete list in a backward manner.
{
    cout<<"------------Display List Backwards------------\n\n==============================================\n";
    Node* p=header;
    if(p!=NULL){
    while(p->next!=NULL)        //move to the end of the list.
        p=p->next;

     while(p!=NULL)             //move from the end of the list to the beginning, printing the key and its corresponding number on the way.
    {
        cout<< "\tKey:\t"<< p->key << "\tholds the number " << p->data << endl;
        p=p->prev;
    }
    cout<<"\n\n";
    }
    else
        cout<< "There is no list to print\n\n";
}
