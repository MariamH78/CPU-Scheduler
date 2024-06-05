#ifndef SORTING_BASE_H
#define SORTING_BASE_H

#include "process.h"

/*
	This class is the parent of both sorting options.
	It makes it easier to construct objects and choose
	type of sorting method at runtime via pointers.
*/

class SortingBase{
	public:
		virtual bool empty() const override = 0;
		virtual void push(process p) const = 0;
		virtual int top() const = 0;	
		virtual int pop()  const = 0;		
		virtual void addLive (process p) const = 0;	
		virtual void addNotLive(process p) const = 0;	
		virtual int getTime() const = 0;
		virtual void incrementTime() const = 0;		
};

#endif //SORTING_BASE_H