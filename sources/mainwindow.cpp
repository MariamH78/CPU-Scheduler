#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorted.h"
#include "not_sorted.h"
#include "preemptive.h"
#include "live.h"
#include "notlive.h"

#include "common_scheduler.h"

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

    ui->comboBox_2->addItem("Not Live");
    ui->comboBox_2->addItem("Live");
}

MainWindow::~MainWindow()
{
    //qDebug()<<"deleting sched";

    delete scheduler;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int  selectedScheduler = ui -> comboBox   -> currentIndex();
    bool selectedLive      = ui -> comboBox_2 -> currentIndex();
	
	bool showQuantum;
    bool showPriority;

    Sorted* sorted;
    NotSorted* notSorted;

	switch (selectedScheduler) {
		case ROUND_ROBIN:
			showQuantum = 1;
			showPriority = 0;
            notSorted = new NotSorted();
            scheduler = new CommonScheduler(notSorted, Preemptive(1));
			break;

		case FCFS:
			showQuantum = 0;
			showPriority = 0;
            sorted = new Sorted("arrival");
            scheduler = new CommonScheduler(sorted, Preemptive(0));
			break;
			
		case SJF_PREEMPT:
			showQuantum = 0;
			showPriority = 0;
            sorted = new Sorted("burst");
            scheduler = new CommonScheduler(sorted, Preemptive(1));
			break;
		case SJF_NON_PREEMPT:
			showQuantum = 0;
			showPriority = 0;
            sorted = new Sorted("burst");
            scheduler = new CommonScheduler(sorted, Preemptive(0));
			break;
			
		case PRI_PREEMPT:
			showQuantum = 0;
			showPriority = 1;
            sorted = new Sorted("priority");
            scheduler = new CommonScheduler(sorted, Preemptive(1));
			break;
		case PRI_NON_PREEMPT:
			showQuantum = 0;
			showPriority = 1;
            sorted = new Sorted("priority");
            scheduler = new CommonScheduler(sorted, Preemptive(0));
            break;

		default:
			break;
    }
	
    if (selectedLive){
        live* subwindow = new live(this->parentWidget(), showQuantum, showPriority, scheduler);
        subwindow->show();
    } else {
        notlive* subwindow = new notlive(this->parentWidget(), showQuantum, showPriority, scheduler);
        subwindow->show();
	}

    close();
}



