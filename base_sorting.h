#ifndef SORTING_BASE_H
#define SORTING_BASE_H
#include <QDebug>
#include "process.h"

/*
	This class is the parent of both sorting options.
	It makes it easier to construct objects and choose
	type of sorting method at runtime via pointers.
*/

class SortingBase{
	public:
        virtual bool empty() = 0;
        virtual void push(process p)  = 0;
        virtual process top() const = 0;
        virtual void pop() = 0;
        virtual void addLive (process p) = 0;
        virtual void addNotLive(process p) = 0;
		virtual int getTime() const = 0;
        virtual void incrementTime() = 0;
};

#endif //SORTING_BASE_H
