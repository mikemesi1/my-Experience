#include "addmachine.h"


int main()
{
locale loc;        //locale variable to use isdigit() and isalpha().
string c;         //string to decide what happens to the variable outcome.
int alarm=0;
int outcome=0;  //outcome of the operation.
int num;       //number the user inputs.
stack<string> sc;   //stack to store the strings.
stack<int> si;      //stack to store last user input operand.

cout << "Welcome to the adding machine. if you would like to stop at any time enter 'z'.\n";
cout<< " if you would like to add, subtract, multiply, or divide type; '+', '-', '*', or '/' respectively.\n";
cout << "if you would like to undo your last action type 'u' and if you would like to start with a clean slate type 'c'\n\n";
cout << "Enjoy!!!\n\n";

while(c!="z")   //until the user inputs z.
{
cout << "=>" << outcome << endl;
cin >>c;

for(int i=0; i<c.size();i++){   //move over the string and check if its a number. if it isn't, don't try to use stoi.
    if(!isdigit(c[i],loc))
        alarm =1;
}
if(alarm==0)
{
    num=stoi(c);                //converting string to a number that can be used as a operand.
    si.push(num);               //push number onto stack
    cin>>c;                     //input operator.
    sc.push(c);                 //push operator unto stack.

      if(c=="+")    //if string is plus, preform addition.
{
    outcome =outcome+si.top();

}

else if(c=="-")    //if string is minus, preform subtraction.
{
    outcome=outcome-si.top();
}

else if(c=="*")     //if string is star, preform multiplication.
{
    outcome = outcome*si.top();
}


else if(c=="/")     //if string is slash, preform division.
{
    outcome=outcome/si.top();
}
}
else if(isalpha(c[0],loc)){ //else if the string is not a number, if its a letter of the alphabet, check which one.

if(c=="u")  //if is u call undo.
{
alarm=0;
if(!si.empty()){    //if the stack isn't empty, don't want to pop an empty stack.
undo(sc.top(),outcome,si.top());    //call undo to reverse last operation.
sc.pop();
si.pop();
}
else                //else send message that theres nothing to be done.
{
    cout<< "There is nothing to undo\n";
}
}
else if(c=="c")    //if string is c then clear the current numbers and remove members on stack.
{
    alarm=0;
    outcome =0;
    num =0;
    c="";
    while(!si.empty())  //until the int stack is empty, remove the top.
        si.pop();
    while(!sc.empty())  //until the string stack is empty, remove the top.
        sc.pop();

}
else if(c=="z")     //if string is z then end the program.
{
    cout << "goodbye!!\n\n";
    break;
}
else                //if its none of the above, let the user know they put something incorrect in.
{
    cout<<"Not a valid Entry\n\n";
    alarm=0;
}
}
else                 //if its none of the above, let the user know they put something incorrect in.
{
alarm =0;
cout << "Not a valid entry\n\n";
}

}
return 0;
}


