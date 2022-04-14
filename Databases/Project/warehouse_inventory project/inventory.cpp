#include <iostream>
#include "parts.h"
#include <vector>
#include <string>
#include "inventory.h"

//add and subtract 
//constructor to fill with default items will be done in main
//

//adding function
void Inventory::addInventory (int weight, std::string name, int quantity, int partNum, int Price) {

      Parts _parts(weight,name,quantity,partNum,Price);

      InventoryList.push_back(_parts);
  
}


//suibtracting function
int Inventory::subInventory(int n, int Oquantity) {
    
    if (InventoryList[n].getQuantity() > Oquantity) {
        InventoryList[n].setQuantity(InventoryList[n].getQuantity() - Oquantity); 
        return 1;
    }
    else if (InventoryList[n].getQuantity() < Oquantity) {
        std::cout << "Sorry we do not have that many in stock" << std::endl;
        return 0;
    }
    return 0;
}
//get function

Parts Inventory::getPart(int partVal) {

    return InventoryList[partVal];  

}

//search function
void Inventory::searchInventoryName(std::string name) {

    int flag = 0;

    for(unsigned i=0; i < InventoryList.size(); i++){
            InventoryList[i].getName();
            if (InventoryList[i].getName() == name) {
                flag = 1;
                std::cout << "Part Name has been found" << endl;
            }
    }

    if (flag == 0) {
        std::cout << "The Part name cannot be found" << std::endl;
    }
}

bool Inventory::searchInventoryNum(int partNum) {

    int num=InventoryList.size();

        if(num > partNum && partNum >= 0)
        {
            std:: cout << "The part number has been found.\n";
            return true;
        }
        else
            std::cout << "The Part number cannot be found" << std::endl;
        return false;

}

void Inventory::populateParts(){
    InventoryList.push_back(Parts(10, "Batttery", 20, 1, 100));
    InventoryList.push_back(Parts(10, "Brakes", 30, 2, 20));
    InventoryList.push_back(Parts(10, "Stuff", 32, 2, 210));
}

void Inventory :: print_inventory()
{
    for(unsigned i=0; i < InventoryList.size();i++)
    {
        std:: cout << i+1 << "\tPart Name: " << InventoryList[i].getName() << "\tPrice: "<< InventoryList[i].getUnitPrice()<< "\tQuantity: " << InventoryList[i].getQuantity() << std:: endl;
    }
}