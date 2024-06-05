#include "live_ui.h"
#include "ui_live_ui.h"

using namespace std;

void LiveUI();

LiveUI::LiveUI(QWidget *parent, bool showQuantum, bool showPriority, CommonScheduler scheduler_)
    : QDialog(parent)
    , ui(new Ui::LiveUI)
	, scheduler(scheduler_)
{
    ui->setupUi(this);
	
	ui->quantum->setVisible(showQuantum);
    ui->quantum->setMinimum(1);
	ui->quantum->setValue(1);
	
	ui->priority->setVisible(showPriority);
	ui->priority->setValue(3);
	
    startTime = QTime::currentTime();
	
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LiveUI::updateChart); // Connect timer timeout signal to updateChart slot
    connect(timer, &QTimer::timeout, this, &CommonScheduler::updateAverages);
    timer->start(1000); // Start the timer with 1-second interval
    
	QtConcurrent::run(LiveUI);
}

void LiveUI() {
	scheduler.start();
}

void LiveUI::updateChart() {
    update(); // Update the UI
}

void updateAverages() {
	if(scheduler.getProcessNo() <= 0) return;
	
	ui->avgturn->setText(QString::number(scheduler.getSumTurnaround() / scheduler.getProcessNo()));
	ui->avgwait->setText(QString::number(scheduler.getSumWaiting() / scheduler.getProcessNo()));
}



LiveUI::~LiveUI()
{
    delete ui;
}

void LiveUI::on_close_clicked()
{
	scheduler.stop();
    close();
}

void LiveUI::on_add_clicked()
{
    int burstTime = ui->burst->value();
    int priority  = ui->priority->value();
	
	if (process::COUNT == 0){
		int quantum = ui->priority->value();
		scheduler.setTimeQuantum(quantum);
		ui->quantum->setVisible(false);
	}
		
    QTime currentTime = QTime::currentTime();
    int arrivalTime = currentTime.secsTo(startTime);
    scheduler.addLive(process(arrivalTime, burstTime, priority));
}

void LiveUI::closeEvent(QCloseEvent *event) {
	scheduler.stop();
    emit childClosed();
    event->accept();
}

