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
    bool selectedLive      = ui -> comboBox_2 -> currentIndex();
	
	bool showQuantum;
	bool showPriority;
	CommonScheduler* scheduler;
    Sorted sorted("burst");
	NotSorted notSorted;
	switch (selectedScheduler) {
		case ROUND_ROBIN:
			showQuantum = 1;
			showPriority = 0;
            notSorted = NotSorted();
            scheduler = new CommonScheduler(notSorted, Preemptive(1));
			break;
			
		case FCFS:
			showQuantum = 0;
			showPriority = 0;
            sorted = Sorted("arrival");
			scheduler = new CommonScheduler(sorted, Preemptive(0));			
			break;
			
		case SJF_PREEMPT:
			showQuantum = 0;
			showPriority = 0;
            sorted = Sorted("burst");
            scheduler = new CommonScheduler(sorted, Preemptive(1));
			break;
		case SJF_NON_PREEMPT:
			showQuantum = 0;
			showPriority = 0;
            sorted = Sorted("burst");
            scheduler = new CommonScheduler(sorted, Preemptive(0));
			break;
			
		case PRI_PREEMPT:
			showQuantum = 0;
			showPriority = 1;
            sorted = Sorted("priority");
            scheduler = new CommonScheduler(sorted, Preemptive(1));
			break;
		case PRI_NON_PREEMPT:
			showQuantum = 0;
			showPriority = 1;
            sorted = Sorted("priority");
            scheduler = new CommonScheduler(sorted, Preemptive(0));
            break;

		default:
			break;
    }
	
    if (selectedLive == 0){
        live* subwindow = new live(this, showQuantum, showPriority, scheduler);
        subwindow->show();
        connect(subwindow, &live::childClosed, this, &MainWindow::close);
    } else if (selectedLive == 1){
        notlive* subwindow = new notlive(this, showQuantum, showPriority, scheduler);
        subwindow->show();
        connect(subwindow, &notlive::childClosed, this, &MainWindow::close);
	}
	
	hide();
}



