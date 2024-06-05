#ifndef SORTED_H
#define SORTED_H

#include <vector>
#include <map>
#include <queue> 
#include <functional>
#include "process.h"
#include "sorting_base.cpp"

using namespace std;
/*
	this class should handle its own time updates, and have a corresponding 
	function for adding a new element live or not. live updates add to the 
	queue, non-live add to the map.
	
	classes that do not have a sorting function also have their own
	add function, and they add to their queue.
	
	if a class is not of a sorting type, 
*/
class Sorted : public BaseSorting{
	private:
		map <int, vector<process>> newArrivals;
		priority_queue <process, vector<process>, function<bool(process, process)>> readyQueue;
		int globalTime = 0;
		
		static bool compareByArrival(process a, process b);
		static bool compareByPriority(process a, process b);
		static bool compareByBurst(process a, process b);
	
	public:
		Sorted(string method);
		
		bool empty() const override;
		void push(process p) const override;
		int top() const override;
		int pop() const override;
		
		void addLive(process p) const override;
		void addNotLive(process p) const override;
		
		int getTime();
		void incrementTime() const override;
};

#endif //SORTED_H