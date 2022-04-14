#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "orders.h"

void warehouse(vector<order> &orders);

bool checkYes();

void showOrder(std::vector<order> &orderList);

bool checkFulfilled(std::vector<order> &orderList);
#endif