#include "preemptive.h"
/*
	Preemptive classes are (SJF-PRE, PRI-PRE, RR).
	NonPreemptive classes are (SJF-NON, PRI-NON, FCFS).
	
	Preemmptive classes are classes which are executed for a certain
	quantum before they are pushed back to wait in queue.
	
	This affects the way average waiting/average turnaround
	times, as well as the way exectime is calculated.
*/

Preemptive::Preemptive(bool preemptive_) : preemptive(preemptive_) {}
Preemptive::Preemptive(int timeQuantum_, bool preemptive_) : timeQuantum(timeQuantum_)
											   , preemptive(preemptive_){}

bool Preemptive::isPreemptive() const{
	return preemptive;
}

int Preemptive::getTimeQuantum() const{
	return timeQuantum;
}

void Preemptive::setTimeQuantum(timeQuantum_){
	timeQuantum = timeQuantum_;
}
