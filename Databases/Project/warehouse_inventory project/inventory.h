#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "parts.h"
#include <vector>
#include <string>
#include <iomanip>


class Inventory : public Parts
{
    	public:

        Inventory(){}

        void addInventory(int weight, std::string name, int quantity, int partNum, int Price);
        int subInventory(int n, int Oquantity);
        Parts getPart(int partVal);
        void searchInventoryName(std::string name);
        bool searchInventoryNum(int partNum);
        void populateParts();
        void print_inventory();


        private:

        std::vector<Parts> InventoryList;
        


};

#endif

// "1. Battery", "2. Brakes", "3. Axle", "4. Fuel Injector", "5. Piston",
//                        "6. A / C Compressor", "7. Radiator", "8. Engine Fan", "9. Clutch",
//                        "10. Spare Tire", "11. Transmission", "13. Shock Absorbers",
//                        "14. Air Filter", "15. Spark Plug", "16. Catalytic Converter Muffler"