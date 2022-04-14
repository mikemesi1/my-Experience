#include"orders.h"

//shows the order for the admin
void order :: showOrder(std::vector<order> orderList){
    if(orderList.size() > 0){
        int counter = 1;
        std::cout << "These are the orders:\n\n";
        for(std::vector<order>::iterator it = orderList.begin(); it != orderList.end(); it++){
            std::cout << counter << ":";
            std::cout << std::endl << (it->getMonth()) << "/" << (it->getDay()) << "/" << (it->getYear()) << std::endl;
            std::cout << "Lists of parts that about being bought\n";
            std::cout << "Total Weight: " << (it->getWeight()) << " Total Price " << (it->getPrice()) << std::endl;
            counter++;
        }
        orderList.clear();
    }
    else
        std::cout << "There are no more orders.\n";
}

//prints the order for the admin
void order:: print_order()
{
    std::cout << std::endl << getMonth() << "/" << (getDay()) << "/" << (getYear()) << std::endl;
    std::cout << "Lists of parts that about being bought\n";
    std:: cout << "Parts:\nWeight\tName\tQuantity\tPart #\tUnit Price\n";
    for(unsigned i=0; i < partsList.size();i++){
        std:: cout << partsList[i].getWeight() << "\t"<< partsList[i].getName()<< "\t"<<
         partsList[i].getQuantity()<< "\t\t\t"<< partsList[i].getPartNum()<< "\t"<< partsList[i].getUnitPrice()<< std:: endl;

    }
    std ::cout << "Total Weight: " << getWeight() << " Total Price " << getPrice() << std::endl;
}

//prints out the parts that are in the order.
void order::listParts(){
    printHdr();
    for(std::vector<Parts>::iterator it = partsList.begin(); it != partsList.end(); it++){
        std::cout << std::setfill(' ') << std::setw(5) << it->getQuantity() << 
            std::setfill(' ') << std::setw(25) << it->getName() <<
            std::setfill(' ') << std::setw(10) << it->getTotalWeight() << 
            std::setfill(' ') << std::setw(10) << it->getUnitPrice() << 
            std::setfill(' ') << std::setw(12) << (it->getUnitPrice() * it->getQuantity()) << std::endl;
            // weight += it->getTotalWeight();
            // price += it->getTotalPrice();
        }
}

//prints out the header for printing out the order
void order::printHdr(){
    std::cout << std::setfill(' ') << std::setw(5) << "QTY" << 
        std::setfill(' ') << std::setw(25) << "DESCRIPTION" <<
        std::setfill(' ') << std::setw(10) << "WEIGHT" << 
        std::setfill(' ') << std::setw(10) << "PRICE" << 
        std::setfill(' ') << std::setw(12) << "TOTAL" << std::endl;
}

//returns the size of vector
void order::getSize(){
    std::cout << "Vector has size of " << partsList.size() << std::endl;
}
