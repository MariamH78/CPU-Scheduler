#include "preemptive.h"
/*
	Preemptive classes are (SJF-PRE, PRI-PRE, RR).
	NonPreemptive classes are (SJF-NON, PRI-NON, FCFS).
	
	Preemmptive classes are classes which are executed for a certain
	quantum before they are pushed back to wait in queue.
	
	This affects the way average waiting/average turnaround
	times, as well as the way exectime is calculated.
*/
int Preemptive::timeQuantum =0;
Preemptive::Preemptive(bool preemptive_) : preemptive(preemptive_) {timeQuantum=1;}
Preemptive::Preemptive(int timeQuantum_, bool preemptive_) : preemptive(preemptive_){timeQuantum = timeQuantum_;}

bool Preemptive::isPreemptive() const{
	return preemptive;
}

int Preemptive::getTimeQuantum() const{
	return timeQuantum;
}

void Preemptive::setTimeQuantum(int timeQuantum_){
	timeQuantum = timeQuantum_;
}
