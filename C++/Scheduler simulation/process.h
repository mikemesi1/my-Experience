#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <queue>
#include <iomanip>
#ifndef PROCESS_H
#define PROCESS_H

//process struct to act as a proocess
struct process{

    std :: string processName;  
    int arrivalTime;   

    int processID;  //the given process id
    char history[ARRAY_SIZE][2];    //the "Plan" the process will follow
    int Subscript;                  //the subscript for the history array
    int CPUTimer;                   //the CPU Burst timer
    int IOTimer;                    //the input/output burst timer
    int CPUTotal;                   //the total time the process was on the cpu
    int ITotal;                     //the total time the process was doing input
    int OTotal;                     //the total time the process was doing output
    int CPUCount;                   //the cpu burst count
    int ICount;                     //the input burst count
    int OCount;                     //the output burst count
    int startWait;                  //the time the process starts a wait period
    int WaitTime;                   //the time thep process has been in waiting
};
#endif