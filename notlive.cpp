#include "live_ui.h"
#include "ui_live_ui.h"

using namespace std;

NotLiveUI::NotLiveUI(QWidget *parent, bool showQuantum, bool showPriority, CommonScheduler scheduler_)
    : QDialog(parent)
    , ui(new Ui::NotLiveUI)
	, scheduler(scheduler_)
{
    ui->setupUi(this);
	
	ui->quantum->setVisible(showQuantum);
    ui->quantum->setMinimum(1);
	ui->quantum->setValue(1);
	
	ui->priority->setVisible(showPriority);
	ui->priority->setValue(3);
}

NotLiveUI::~NotLiveUI()
{
    delete ui;
}

void NotLiveUI::on_pushButton_clicked()
{
	// Static
    ADD_COUNTER++;
	
    int burstTime = ui->btime->value();
    int arrivalTime = ui->btime_2->value();
	
	// The default is 3, and it's hidden to the
	// user if showPriority is false.
    int priority = ui->priority->value();
	
	// The default is 1, and it's hidden to the
	// user if showQuantum is false.
	// This is a static shared member, so it only
	// takes the last value entered.
	int quantum = ui->quantum->value();
	
    scheduler.addNotLive(process(arrivalTime, burstTime, priority));
	
    if(counter == (ui->num->value())){
		scheduler.setQuantumTime(quantum);
		LiveUI* subwindow = new LiveUI(this, scheduler);
		subwindow->show();
		close();
	}
}

void NotLiveUI::closeEvent(QCloseEvent *event) {
	scheduler.stop();
    emit childClosed();
    event->accept();
}
