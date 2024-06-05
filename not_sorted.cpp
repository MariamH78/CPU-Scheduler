#include "not_sorted.h"

using namespace std;
/*
	this class is the same as Sorted and has a corresponding 
	function for adding a new element live or not. live updates add to the 
	queue, non-live add to the map.
	
	This class is needed to override the push/push_back top/front descrepancy.
*/

NotSorted::empty() const {
	return readyQueue.empty();
}
NotSorted::push(process p) const {
	readyQueue.push_back(p);
}
NotSorted::top() const {
	return readyQueue.front();
}
NotSorted::pop() const {
	readyQueue.pop();
}


NotSorted::addLive (process p) const {
	readyQueue.push_back(p);
}
NotSorted::addNotLive(process p) const {
	newArrivals[p.getArrivalTime()].push_back(p);
}


NotSorted::getTime(){
	return globalTime;
}
NotSorted::incrementTime() const {
	newArrivals.erase(globalTime - 1);

	for (auto process : newArrivals[globalTime])
		readyQueue.push(process)
	
	globalTime++;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second
	
}
