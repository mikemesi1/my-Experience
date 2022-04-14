/*
Michael Mesi
Final: Question One code.
This program builds a flow chart type game filled with animals that the user
inputs during runtime. This is done using a Binary Tree with root->data
initialized as a "elephant".
*/
#include"AnimalBtree.h"      //Header file containing the Binary tree class Btree, the header file node.H and other necessary files.


int main()
{

    Btree tr;
    char ans='y';       //the users answer to the questions asked.
    while(ans =='y'){   //While the user doesn't want to quit keep asking.
    cout <<"Shall we play a game?";
    cin>> ans;
    if(ans == 'y')      //if yes then enter tr.game() where the tree will be accessed.
        tr.Game();

    else if(ans =='n')  //Exits loop, leading to end of execution.
    {
        cout <<"Bye!";

    }

    else        //if the user enters an invalid response.
    {
        cout<<"please enter 'y', or 'n' in response to questions.\n\n";
        ans ='y';   //set to y so that it asks again so they can input again
    }
    }
    return 0;
}



 Btree::Btree()         //constructor.
 {
     root=new Node<string>;
     root->data="elephant";     //imitating root in question 1 of final pdf file.

 }

void Btree :: Game()

{   char ans='y';
    Node<string>* ptr=root;     //pointer to move through tree.
    ptr=root;
    while(ptr!=NULL){           //until pointer hits a null(end of subtree).
    if(isleaf(ptr))             //if leaf, ask if this is the animal they were thinking of.
    {
        cout <<"Were you thinking of a " << ptr->data << "?";
        cin >>ans;
        if(ans =='y')       //if yes cout and break loop.
        {
                cout<<"Great!\n\n";
                break;

        }
        else if(ans =='n')  //if not the animal, call insert.
        {
        Node<string>* tmp=ptr;
        Insert(tmp);
        break;

        }
        else
        {
            cout<< "please enter 'y', or 'n' in response to questions.\n\n";
        }

    }
    else if(!isleaf(ptr))           //if not leaf.
    {
            cout <<ptr->data <<"  ";    //ask usedr question.
            cin >>ans;
            if(ans =='y')               //if yes checkout right child.
                ptr=ptr->right;
            else if(ans =='n')          //if no checkout left child.
                ptr= ptr->left;
    }

    }

}
void Btree:: Insert(Node<string>* &ptr)
{
    string rest_of_line;
    char new_answer;

    Node<string>* new_animal =new Node<string>; //New animal being added.
    Node<string>* old_animal =new Node<string>; //old animal whos name is held by ptr->data.
    old_animal->data=ptr->data;

    cout <<"Doh! What was the animal? ";
    cin >> new_animal->data;            //input new animal name

    cout <<"What is a question separating a " <<old_animal->data << " from a " << new_animal->data <<"?";
    cin >>ptr->data;                    //input question to choose which leaf/sub tree to go down
    getline(cin,rest_of_line);          //Only way I could get this function to work, if i tried getline(cin,ptr->data) alone it would
    ptr->data=ptr->data+rest_of_line;   //not allow a question to be input.

    cout << "What is the correct answer for the animal? ";
    cin >>new_answer;                   //Inputs response to go to new question. Decides if new animal will be the left or right child.
    cout<<endl;

    if(new_answer=='y')
    {
        ptr->left=old_animal;   //makes old animal left child of question.
        ptr->right=new_animal;  //makes new animal right child of question.
    }

    else if(new_answer=='n')
    {
        ptr->right=old_animal;  //makes old animal right child of question.
        ptr->left=new_animal;   //makes new animal left child of question.
    }
}
bool Btree:: isleaf(Node<string> *ptr)
{
if (ptr->left==NULL && ptr->right==NULL)    //if node has no children return  true.
    return true;
return false;                               // else return false
}
