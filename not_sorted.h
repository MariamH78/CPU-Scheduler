#ifndef NOT_SORTED_H
#define NOT_SORTED_H

#include <vector>
#include <map>
#include <queue> 
#include "process.h"
#include "sorting_base.cpp"

using namespace std;
/*
	this class is the same as Sorted and has a corresponding 
	function for adding a new element live or not. live updates add to the 
	queue, non-live add to the map.
	
	This class is needed to override the push/push_back top/front descrepancy.
*/
class NotSorted : public BaseSorting{
	private:
		map <int, vector<process>> newArrivals;
		queue <process> readyQueue;
		int globalTime = 0;
	
	public:
		bool empty() const override;
		void push(process p) const override;
		int top() const override;
		int pop() const override;
		
		void addLive (process p) const override;
		void addNotLive(process p) const override;
		
		int getTime();
		void incrementTime() const override;
			
};

#endif