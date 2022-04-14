#include "parts.h"

//setting up the constructor for parts class
Parts::Parts(int w, std::string n, int q, int part, int up){
    setWeight(w);
    setName(n);
    setQuantity(q);
    setPartNum(part);
    setUnitPrice(up);
    totalPriceWeight();
}