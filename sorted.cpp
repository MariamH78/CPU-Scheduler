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
	return a.getArrivalTime() > b.getArrivalTime();
}
bool Sorted::compareByPriority(process a, process b) {
	return a.getPriority() > b.getPriority();
}	
bool Sorted::compareByBurst(process a, process b) {
	return a.getBurst() > b.getBurst();
}


bool Sorted::empty () const {
	return readyQueue.empty();
}
void Sorted::push (process p) const {
	readyQueue.push(p);
}
int Sorted::top() const {
	return readyQueue.top();
}
int Sorted::pop() const {
	readyQueue.pop();
}


void Sorted::addLive(process p) const{
	readyQueue.push(p);
}
void Sorted::addNotLive(process p) const{
	newArrivals[p.getArrivalTime()].push_back(p);
}


int Sorted::getTime(){
	return globalTime;
}
void Sorted::incrementTime() const {
	newArrivals.erase(globalTime - 1);

	for (auto process : newArrivals[globalTime])
		readyQueue.push(process)
	
	globalTime++;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second
}
