#include "sorted.h"

using namespace std;
/*
	this class should handle its own time updates, and have a corresponding 
	function for adding a new element live or not. live updates add to the 
	queue, non-live add to the map.
	
	classes that do not have a sorting function also have their own
	add function, and they add to their queue.
	
	if a class is not of a sorting type, 
*/

Sorted::Sorted(string method){
	if (method == "arrival")
        readyQueue = priority_queue<process, vector<process>, function<bool(process, process)>>(compareByArrival);
	else if (method == "priority")
		readyQueue = priority_queue<process, vector<process>, function<bool(process, process)>>(compareByPriority);
	else if (method == "burst")
		readyQueue = priority_queue<process, vector<process>, function<bool(process, process)>>(compareByBurst);
	
}


bool Sorted::compareByArrival(process a, process b) {
    return a.getArrival() > b.getArrival();
}
bool Sorted::compareByPriority(process a, process b) {
	return a.getPriority() > b.getPriority();
}	
bool Sorted::compareByBurst(process a, process b) {
	return a.getBurst() > b.getBurst();
}


bool Sorted::empty () {
	return readyQueue.empty();
}
void Sorted::push (process p)  {
	readyQueue.push(p);
}
process Sorted::top() const {
	return readyQueue.top();
}
void Sorted::pop()  {
	readyQueue.pop();
}


void Sorted::addLive(process p) {
	readyQueue.push(p);
}
void Sorted::addNotLive(process p) {
    newArrivals[p.getArrival()].push_back(p);
}


int Sorted::getTime()const{
	return globalTime;
}
void Sorted::incrementTime() {
    newArrivals.erase(globalTime);
    globalTime++;
	for (auto process : newArrivals[globalTime])
        readyQueue.push(process);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second
}
