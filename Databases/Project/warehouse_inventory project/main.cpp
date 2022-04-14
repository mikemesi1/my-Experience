#include <iostream>
#include <iomanip>
#include <string>
#include "admin.h"
#include "warehouse.h"
#include "parts.h"
#include "inventory.h"
#include <vector>
#include "crinterface.h"
using namespace std;

int interfaceNum =-1;
string password;


int n, grabarrayitem;

int main()
{
    Inventory myInventory;
    myInventory.populateParts();
    std:: vector<order> orders; 
    brackets bracket;


       cout << "Where would you like to go to? Please enter a number, \n";
    //inital interface to start 
    while(interfaceNum != 0){
        cout << "0. Exit\n"
             << "1. Shopping \n"
             << "2. Warehouse Employee \n"
             << "3. Update Parts List \n"
             << "4. Admin Control\n";
        cin >> interfaceNum;
    //check for interface if its a valid input
        if (interfaceNum > 4)
        {
            cout << "Not a valid number\n";
            return 0;
        }
        else
        {
            /* shopping interface where use selects the parts they want then
            enters the qauntity they want once 0 is entered it asks them 
            for their email and credit card information (all done in the credit card interface)
            and the authorization number is printed and an email is sent on cout
            */ 
            if (interfaceNum == 1)
            {
                cout << "Please enter which parts you would like by entering the number, to quit(-1)\n";
                order order1; 
                int a;
                float OrderCost=0;
                float OrderWeight=0;
                myInventory.print_inventory();
                while (n != -1) {
                    cout << "---- Enter Parts #----\n";
                     cin >> n;
                    Parts temp;
                    n--;
                    if(myInventory.searchInventoryNum(n)){
                        order1.setDay(6);
                        order1.setMonth(12);
                        order1.setYear(2021);
                        temp = myInventory.getPart(n);
    //                  modifiers           
                        cout << "How many would you like?\n";
                        cin >> a;
                        if (myInventory.subInventory(n, a) > 0){
                            temp.setQuantity(a);
                            order1.addPlist(temp);   
                            OrderCost +=(a * temp.getUnitPrice());
                            OrderWeight+=(a * temp.getWeight());
                        }
                    }
                    
                }
                order1.setWeight(OrderWeight);


                //Check to see what shipping price to add to the order.
                if(order1.getWeight()<bracket.get_wt1())
                {
                    OrderCost += bracket.get_brprc0();
                }
                else if(order1.getWeight()> bracket.get_wt1() && order1.getWeight()< bracket.get_wt2())
                {
                    OrderCost += bracket.get_brprc1();
                }
                else
                {
                    OrderCost += bracket.get_brprc2();                    
                }

                order1.setPrice(OrderCost);     //set order price
                int authnum =crAuthentication(OrderCost);
                cout << "Here is your athentication number: " << authnum;
                orders.push_back(order1);       //push order unto order list
            }
            // warehouse interface call where the warhouse values are handled
            else if (interfaceNum == 2)
            {
                cout << "welcome Warehouse Employee " << endl;
                warehouse(orders);
            }
            else if (interfaceNum == 3) //update the parts in the inventory
            {

                string partName;
                int partNumber;
                int partWeight;
                int partQuantity;
                int partPrice;
                cout << "Welcome to Parts Update\n" << endl;
                cout << "Please enter the new part name" << endl;
                    cin >> partName;
                cout << "Please enter the part Number" << endl;
                    cin >> partNumber;
                cout << "Please enter the Weight of the part" << endl;
                    cin >> partWeight;
                cout << "Please enter the amount of parts bought" << endl;
                    cin >> partQuantity;
                cout << "Please enter the cost of the part" << endl;
                    cin >> partPrice;
            
                myInventory.addInventory(partWeight,partName,partQuantity,partNumber,partPrice);

            }
            else if (interfaceNum == 4) //admin control interface call where Admin enters a password and is granted access if correct
            {

                cout << "You have chosen Admin Control, Please enter the password\n";
                cout << "password is password\n" << std::endl;
                cin >> password;
                int i = 1;
                while (i != 0)
                {
                    if (password == "password")
                    {
                     i = 0;
                     cout << "welcome to Admin Control\n";
                     admin(orders, bracket);
                     }
                else
                 {
                     i = 1;
                     cout << "Password is incorrect Please try again\n";

                    }
                }
          }
        }
    }
    return 0;
}