#ifndef PARTS_H
#define PARTS_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Parts
{
public:

    Parts(int w = 10, std::string n = "null", int q = 50, int part = 0, int up = 0);

    void setWeight(int w)
    {
        weight = w;
    }
    void setName(string n)
    {
        name = n;
    }
    void setQuantity(int q)
    {
        quantity = q;
    }
    void setPartNum(int num)
    {
        partNum = num;
    }
    void setUnitPrice(int p)
    {
        unitPrice = p;
    }
    void totalPriceWeight()
    {
        totPrice = unitPrice * quantity;
        totWeight = weight * quantity;
    }
    string getName() { return name; }
    int getWeight() { return weight; }
    int getQuantity() { return quantity; }
    int getPartNum() { return partNum; }
    float getUnitPrice() { return unitPrice; }
    float getTotalPrice() { return totPrice; }
    int getTotalWeight() { return totWeight; }

private:
    int weight;
    std::string name;
    int quantity;
    int partNum;
    float unitPrice;
    float totPrice = 0;
    int totWeight = 0;
};

#endif