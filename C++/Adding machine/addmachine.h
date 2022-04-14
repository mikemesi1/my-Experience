#ifndef ADDMACHINE_H_INCLUDED
#define ADDMACHINE_H_INCLUDED
#include<iostream>
#include<stack>         // to throw chars and ints onto for the undo function
#include<locale>        //to use locale for isdigit() and isalpha()

using namespace std;


void undo(string &c, int &a, int &b)    //takes a char and to ints, the char being what the last operator was. int a is the outcome of the operation, and int b is the last user input operand.
{
if(c=="+")  //if last operator was a plus. subtract b from a.
{
    a =a-b;
}

else if(c=="-") //if the last operator was a minus, add b to a.
{
    a=a+b;
}

else if(c=="*") //if the last operator was a star, divide a with b.
{
    a = a/b;
}


else if(c=="/") //if last operator was a slash,  multiply a with b.
{
    a=a*b;
}


}


#endif // ADDMACHINE_H_INCLUDED
