#ifndef NOT_SORTED_H
#define NOT_SORTED_H

#include <vector>
#include <map>
#include <queue> 
#include "process.h"
#include "base_sorting.h"
#include <chrono>
#include <thread>

using namespace std;
/*
	this class is the same as Sorted and has a corresponding 
	function for adding a new element live or not. live updates add to the 
	queue, non-live add to the map.
	
	This class is needed to override the push/push_back top/front descrepancy.
*/
class NotSorted : public SortingBase{
	private:
		map <int, vector<process>> newArrivals;
		queue <process> readyQueue;
		int globalTime = 0;
	
	public:
        bool empty() override;
        void push(process p)  override;
        process top() const override;
        void pop()  override;
		
        void addLive (process p)  override;
        void addNotLive(process p)  override;
		
        int getTime() const override;
        void incrementTime() override;
			
};

#endif
