#ifndef COMMON_SCHEDULER_H
#define COMMON_SCHEDULER_H

#include <QDialog>
#include <vector>
#include <thread>
#include <chrono>
#include <QTime>
#include <QPainter>

#include "process.h"
#include "sorted.h"
#include "not_sorted.h"
#include "preemptive.h"

/*
	This is the class that constructs all schedulers, and stores their types
	(sorted or not, preemptive or not). More details on the types in their 
	respective files.
	
*/

class CommonScheduler{
	private:
		static int processNo = 0;
		double sumWaiting = 0;
		double sumTurnaround = 0;
		
		vector<process> ganttChart;
		
		SortingBase& readyQueue; // Member can be of type Sorted or NotSorted.
								 // Responsible for all queue and time handling.
		Preemptive preemptive; // Member that determines preemption stuff.
							   // Only stores the variables, can be removed entirely in a later version.

		bool running = 0;

		
	public:
		QTime startT;
		CommonScheduler(SortingBase& readyQueue_, Preemptive preemptive_);

		virtual void paintEvent(QPaintEvent *event);
		
		void start();
		void stop();
		
		// A few wrapper functions
		void addLive(process p);
		void addNotLive(process p);
		
		void setTimeQuantum(timeQuantum_);

		// Some getters
		int getSumWaiting() const;
		int getSumTurnaround() const;
		int getProcessNo() const;

};


#endif //COMMON_SCHEDULER_H