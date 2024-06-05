#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H

/*
	Preemptive classes are (SJF-PRE, PRI-PRE, RR).
	NonPreemptive classes are (SJF-NON, PRI-NON, FCFS).
	
	Preemmptive classes are classes which are executed for a certain
	quantum before they are pushed back to wait in queue.
	
	This affects the way average waiting/average turnaround
	times, as well as the way exectime is calculated.
*/

class Preemptive{
	private:
		static int timeQuantum = 1;
		bool preemptive;
	
	public:
		Preemptive(bool preemptive_) : preemptive(preemptive_);
		Preemptive(int timeQuantum_, bool preemptive_);

		bool isPreemptive() const;

		int getTimeQuantum() const;
		void setTimeQuantum(timeQuantum_);
};

#endif
