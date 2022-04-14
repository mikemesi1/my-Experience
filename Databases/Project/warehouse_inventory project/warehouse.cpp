#include "warehouse.h"

//checks if the user puts in proper input
bool checkYes(){

    std::string cont;    
    while(true){
        std::getline(std::cin,cont);
        if(cont == "y"){
            return true;
        }
        else if(cont == "n"){
            return false;
        }
        else
            std::cout << "Please enter y or n.\n";
    }
}

//shows the order. It goes through the list of parts and prints out their weight and price
//then pritns out total weight and total amount
void showOrder2(std::vector<order> &orderList){
    if(!(checkFulfilled(orderList))){
        int counter = 1;
        std::cout << "These are the orders:\n\n";
        for(std::vector<order>::iterator it = orderList.begin(); it != orderList.end(); it++){
            if(!(it->getstatus())){
                std::cout << counter << ":";
                std::cout << std::endl << (it->getMonth()) << "/" << (it->getDay()) << "/" << (it->getYear()) << std::endl;
                it->listParts();
                std::cout << "Total Weight: " << (it->getTotalWeight()) << " Total Price " << (it->getTotalAmount()) << std::endl;
                counter++;
            }
        }
    }
    else
        std::cout << "\nThere are no more orders.\n";
}

//checks which order(s) in orderlist are fulfilled or not
bool checkFulfilled(std::vector<order> &orderList){
    int unfulfilled = 0;
    for(std::vector<order>::iterator it = orderList.begin(); it != orderList.end(); it++){
        if(!(it->getstatus()))
            unfulfilled++;
    }
    if(unfulfilled > 0)
        return false;
    else
        return true;       
}

//the main warehouse interface
//takes in the reference to vectors of orders that are passed in from the main
//it will ask if the employee would want to print it out or not.
//if they print it out, the order status is changed to fulfilled
//then it will not show up in the order list anymore

void warehouse(vector<order> &orders){

    bool done = false;

    std::cout << "You have entered the warehouse terminal.\n";

    while(!done){

        std::cout << "\nWould you like to see the order? (y/n)\n";
        if(checkYes()){
            showOrder2(orders);
            if(!checkFulfilled(orders)){
                std::cout << "\nWould you like to print them now?\n";
                if(checkYes()){
                    for(std::vector<order>::iterator it = orders.begin(); it != orders.end(); it++){
                        if(!(it->getstatus()))
                            it->setFulfilled();
                    }           
                    std::cout << "Printing the invoice.\n";
                    std::cout << "Sending the confirmation email to the customer.\n\n";
                }
            }
        }

        std::cout << "Do you want to exit the warehouse terminal? (y/n)\n";
        if(checkYes()){
            done = true;
        }
    }

    for(std::vector<order>::size_type i = 0; i < orders.size(); i++){
        std::cout << "order status is " << orders[i].getstatus() << std::endl;
    }    

    std::cout << "Returning to the main terminal.\n";
}