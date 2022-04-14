#ifndef CRINTERFACE_H
#define CRINTERFACE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
/**
 * @brief provides an exteranal interface for credit card processing
 * 
 * @param price price of the order 
 * @return int returns an authentication number
 */
int crAuthentication(float &price);

#endif