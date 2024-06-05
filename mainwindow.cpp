#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorted.h"
#include "not_sorted.h"
#include "preemptive.h"
#include "nonpreemptive.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
    ui->comboBox->addItem("FCFS");
    ui->comboBox->addItem("SJF Preemptive");
    ui->comboBox->addItem("SJF Non-preemptive");
    ui->comboBox->addItem("Priority Preemptive");
    ui->comboBox->addItem("Priority Non-preemptive");
    ui->comboBox->addItem("Round Robin");

    ui->comboBox_2->addItem("Live");
    ui->comboBox_2->addItem("Not live");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int  selectedScheduler = ui -> comboBox  -> currentIndex();
    bool selectedLive      = ui -> comboBox2 -> currentIndex();
	
	bool showQuantum;
	bool showPriority;
	CommonScheduler scheduler;
	
	switch (selectedScheduler) {
		case ROUND_ROBIN:
			showQuantum = 1;
			showPriority = 0;
			scheduler = CommonScheduler(NotSorted(), Preemptive(1));			
			break;
			
		case FCFS:
			showQuantum = 0;
			showPriority = 0;
			scheduler = CommonScheduler(Sorted("arrival"), Preemptive(0));			
			break;
			
		case SJF_PREEMPT:
			showQuantum = 0;
			showPriority = 0;
			scheduler = CommonScheduler(Sorted("burst"), Preemptive(1));	
			break;
		case SJF_NON_PREEMPT:
			showQuantum = 0;
			showPriority = 0;
			scheduler = CommonScheduler(Sorted("burst"), Preemptive(0));
			break;
			
		case PRI_PREEMPT:
			showQuantum = 0;
			showPriority = 1;
			scheduler = CommonScheduler(Sorted("priority"), Preemptive(1));
			break;
		case PRI_NON_PREEMPT:
			showQuantum = 0;
			showPriority = 1;
			scheduler = CommonScheduler(Sorted("priority"), Preemptive(0));
			break;
			
		default:
			break;
	}		
	
	if (selectedLive){
		LiveUI* subwindow = new LiveUI(this, showQuantum, showPriority, scheduler);
		subwindow->show();
		connect(subwindow, &subwindow::childClosed, this, &MainWindow::close);
	} else {
		NotLiveUI* subwindow = new NotLiveUI(this, showQuantum, showPriority, scheduler);
		subwindow->show();
		connect(subwindow, &subwindow::childClosed, this, &MainWindow::close);
	}
	
	hide();
}



