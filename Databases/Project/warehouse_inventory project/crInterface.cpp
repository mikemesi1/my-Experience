
#include "crinterface.h"
int crAuthentication(float &price)
{
    string email;
    string crnum, cvv, expdate;
    int crflag = 0;
    while (crflag != 1)//until they enter a correct credit card
    {
        cout << "Enter your email address.\n";  
        cin >> email;
        cout << "Enter your credit card number\n";
        cin >> crnum;
        if (crnum.size() != 16)             //check valid email address
            cout << "Credit card number is not valid, enter a 16 digit number\n";
        else    // move on to cvv
        {

            cout << "Enter your cvv number\n";
            cin >> cvv;
            while (crflag != 1)     
            {
                if (cvv.size() != 3)        //check valid cvv
                {
                    cout << "CVV number not valid, enter a 3 digit number\n";
                }
                else                    //move on to expiration date
                {
                    cout << "Enter your expiration date\n";
                    cin >> expdate;
                    crflag = 1;
                }
            }
        }
    }
    cout << "Thank you for your purchase, a confirmation email has been sent to " << email << std :: endl;

    srand((unsigned)time(0));
    int i;
    i = (rand() % 6) + 1;
    return i;   //return random authentication number.
}