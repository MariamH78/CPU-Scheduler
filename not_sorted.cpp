#include "not_sorted.h"

using namespace std;
/*
	this class is the same as Sorted and has a corresponding 
	function for adding a new element live or not. live updates add to the 
	queue, non-live add to the map.
	
	This class is needed to override the push/push_back top/front descrepancy.
*/

bool NotSorted::empty() {
	return readyQueue.empty();
}
void NotSorted::push(process p)  {
    readyQueue.push(p);
}
process NotSorted::top() const {
	return readyQueue.front();
}
void NotSorted::pop()  {
	readyQueue.pop();
}


void NotSorted::addLive (process p)  {
    readyQueue.push(p);
}

void NotSorted::addNotLive(process p)  {
    newArrivals[p.getArrival()].push_back(p);
}


int NotSorted::getTime()const{
	return globalTime;
}

void NotSorted::incrementTime(){
    newArrivals.erase(globalTime);
    globalTime++;
    for (auto process : newArrivals[globalTime])
        readyQueue.push(process);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second
}
