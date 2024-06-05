#include "common_scheduler.h"

/*
	This is the class that constructs all schedulers, and stores their types
	(sorted or not, preemptive or not). More details on the types in their 
	respective files.
	
*/

CommonScheduler::CommonScheduler(SortingBase* readyQueue_, Preemptive preemptive_) : readyQueue (readyQueue_)
                                                                                   , preemptive (preemptive_){}
int CommonScheduler::processNo = 0;
void CommonScheduler::paintEvent() {
    QPainter painter(UIpointer);
	int x = 30;
	int y = 300;
	int height = 100; // Height of the rectangles
	QFont font = painter.font();
	font.setPointSize(5); // Adjust font size as needed
	painter.setFont(font);
	painter.setBrush(Qt::white);
	painter.drawRect(10, 290, 780, 120);
	for (const auto& p : ganttChart) {
		QColor color = QColor::fromHsl((p.getID() * 30) % 360, 255, 150); // Adjust saturation and lightness as needed
		painter.setBrush(color);
		painter.drawRect(x, y, 30, height);
		QString pidText = QString("PID: %1").arg(p.getID());
		painter.drawText(x + 5, y + height / 3, pidText);
		QString remTimeText = QString("RemT: %1").arg(p.getBurst());
		painter.drawText(x + 5, y + (height * 2) / 3, remTimeText);
		x += 30 + 10;
		if(x > 770 && y == 300){
			y = 420;
			x = 30;
			painter.setBrush(Qt::white);
			painter.drawRect(10, 410, 780, 120);
		}
		else if(x > 770 && y == 420){
			y = 300;
			x = 30;
			painter.setBrush(Qt::white);
			painter.drawRect(10, 290, 780, 120);
		}
	}
}
void CommonScheduler::setUIPointer(QDialog* qd) {
    UIpointer = qd;
}

void CommonScheduler::start() {
	running = 1;
    while (running) {
        if (!readyQueue->empty()) {
            process currentProcess = readyQueue->top();
            //qDebug() << getTime() << ' ' << currentProcess.getID();
            readyQueue->pop();
			int execTime;
			if (preemptive.isPreemptive())
                execTime = min(preemptive.getTimeQuantum(), currentProcess.getBurst());
			else 
				execTime = currentProcess.getBurst();
								
			while (execTime--) {
				currentProcess.setBurst(currentProcess.getBurst() - 1);
                readyQueue->incrementTime();
				ganttChart.push_back(currentProcess);
			}
			
			if (currentProcess.getBurst() > 0) {
                readyQueue->push(currentProcess);
            } else {
                currentProcess.calcProcessTurnaroundTime(getTime() - 0);
                currentProcess.calcProcessWaitingTime(getTime() - 0);
				sumWaiting += currentProcess.getWaitingTime();
                sumTurnaround += currentProcess.getTurnaroundTime();
				processNo++;
/*
                qDebug() << "Processno: " << processNo << ' '
                         << "waiting time: " << currentProcess.getWaitingTime()
                         << "turnaround: " << currentProcess.getTurnaroundTime();
*/
            }
		} else 
            readyQueue->incrementTime();
	}
}


// Getters
double CommonScheduler::getSumWaiting() const {
    return sumWaiting;
}
double CommonScheduler::getSumTurnaround() const {
    return sumTurnaround;
}
int CommonScheduler::getProcessNo() const {
    return processNo;
}

// Wrappers
void CommonScheduler::addLive(process p) {
    this->readyQueue->addLive(p);
}
void CommonScheduler::addNotLive(process p) {
    this->readyQueue->addNotLive(p);
}
int CommonScheduler::getTime() const {
    return (this->readyQueue)->getTime();
}
void CommonScheduler::setTimeQuantum(int timeQuantum_){
    this->preemptive.setTimeQuantum(timeQuantum_);
}




CommonScheduler::~CommonScheduler(){
    //qDebug()<<"it IS in fact, deleted";
    if (this -> readyQueue)
        delete this -> readyQueue;
}
void CommonScheduler::stop(){
    running = 0;
}
