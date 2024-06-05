#include "process.h"

process::process(int id, int arrival_, int burst_, int priority_)
{
    ID = ++COUNT;
    arrival = arrival_;
    burst = burst_;
    priority = priority_;
}


int process::getID()const {
    return ID;
}
int process::getCount()const {
    return COUNT;
}
int process::getArrival()const {
    return arrival;
}
void process::setArrival(int arrival_) {
    arrival = arrival_;
}

int process::getBurst()const {
    return burst;
}
void process::setBurst(int burst_) {
    burst = burst_;
}

int process::getPriority() const
{
    return priority;
}

void process::setPriority(int priority_)
{
    priority = priority_;
}

int process::getWaitingTime()const {
    return waitingTime;
}

int process::getTurnaroundTime()const {
    return turnaroundTime;
}

//function to calculate waiting time
void process::calcProcessWaitingTime(int finishTime) {
    waitingTime = finishTime - this->burst - this->arrival;
}

//function to calculate turnaround time
void process::calcProcessTurnaroundTime(int finishTime) {
    turnaroundTime = finishTime - this->arrival;
}

