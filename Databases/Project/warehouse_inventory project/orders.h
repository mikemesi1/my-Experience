#ifndef ORDERS_H
#define ORDERS_H
#include<iostream>
#include<vector>
#include <string>
#include"inventory.h"

class order : public Inventory
{
	public:

        order(){}
        
        void setWeight(int num){weight = num;}

        void setPrice(int num){price = num;}

        void setDay(int num){ day = num; }

        void setMonth(int num){ month = num; }

        void setYear(int num){ year = num; }

        void setFulfilled(){ fulfilled = true; }

        int getWeight(){ return weight; }

        float getPrice(){ return price; }

        int getDay(){ return day; }

        int getMonth(){ return month; }

        int getYear(){ return year; }
        
        bool getstatus() {return fulfilled;}

        void showOrder(std::vector<order> orderList);
        
        void  build_order();

        void print_order();

        int getTotalAmount(){ return price; }

        int getTotalWeight(){ return weight; }

        void listParts();

        void printHdr();

        void addPlist(Parts &c){partsList.push_back(c);}

        void getSize();

    private:
		int weight;
		float price;
		int day;
		int month;
		int year;
		bool fulfilled =false;
    std::vector<Parts> partsList;
};



#endif
