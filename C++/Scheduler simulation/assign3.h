#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring>
#include<deque>
#ifndef ASSIGN_H
#define ASSIGN_H

const int MAX_TIME = 500;   //max time the "system" will run for
const int IN_USE = 5;       //max processes at one time
const int HOW_OFTEN = 25;   //how offten to print system status
const int QUEUE_SIZE = 20;  //max queue size
const int ARRAY_SIZE = 10;  //max Array size
int timer;                  //int variable acting as timer
int IN_PLAY = 0;            //number of processes in PLay at one time
int idleTime = 0;           //total idle time

bool done();                //returns true if there is no more to be done
void sysState();            //prints the sztate of the system 
void EndProcess();          //prints out a processes info before it is ended
void in_Play();             //checks how many processes are in play
#endif