#ifndef PROCESS_H
#define PROCESS_H

class process {
private:
    static int COUNT;
    int ID;
    int arrival;
    int initialBurst;
    int burst;
    int waitingTime = 0;
    int turnaroundTime = 0;
    int priority = 3;

public:
    process(int arrival_, int burst_, int priority_);
    static int getCount();
	
    int getID() const;
    void setID(int id);
	
    int getArrival() const;
    void setArrival(int arrival_);
	
    int getBurst() const;
    void setBurst(int burst_);
	
    int getPriority()const;
    void setPriority(int priority_);
	
    int getWaitingTime() const;
    int getTurnaroundTime() const;
	
    void calcProcessWaitingTime(int finishTime);
    void calcProcessTurnaroundTime(int finishTime);
};

#endif
