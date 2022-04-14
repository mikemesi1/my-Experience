#ifndef ADMIN_H
#define ADMIN_H
#include"iostream"
#include"warehouse.h"
#include"orders.h"
#include"brackets.h"
/**
 * @brief provides an admin interface for displaying orders, searching orders, and setting  the different shipping prices and weights
 * 
 * @param orderList a vector filled with orders class objects.
 * @param brackets  a bracket class object dictating what a persons shipping price should be
 ************************************************************************************************************************************/
void admin(vector<order> &orderList, brackets &brackets);
#endif