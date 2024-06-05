#include "live.h"
#include "ui_live.h"

void START(CommonScheduler* scheduler);

live::live(QWidget *parent, bool showQuantum, bool showPriority, CommonScheduler* scheduler_)
    : QDialog(parent)
    , ui(new Ui::live)
    , scheduler(scheduler_)
{

    ui->setupUi(this);
    scheduler->setUIPointer(this);

    ui->quantum->setVisible(showQuantum);
    ui->quantum->setMinimum(1);
    ui->quantum->setValue(1);

    ui->priority->setVisible(showPriority);
    ui->priority->setValue(3);

    startTime = QTime::currentTime();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &live::updateChart); // Connect timer timeout signal to updateChart slot
    connect(timer, &QTimer::timeout, this, &live::updateAverages);
    timer->start(1000); // Start the timer with 1-second interval

    QtConcurrent::run(START,scheduler);
}

live::~live()
{
    delete ui;
}

void START(CommonScheduler* scheduler) {
    //qDebug()<<"inside live::start";
    scheduler->start();
}

void live::updateChart() {
    update(); // Update the UI
}

void live::paintEvent(QPaintEvent *event){
    scheduler->paintEvent();
}

void live::updateAverages() {
    if(scheduler->getProcessNo() <= 0) return;

    ui->avgturnt->setText(QString::number(scheduler->getSumTurnaround() / scheduler->getProcessNo()));
    ui->avgturnt_2->setText(QString::number(scheduler->getSumWaiting() / scheduler->getProcessNo()));
}

void live::on_add_clicked()
{
    int burstTime = ui->BurstTime->value();
    int priority  = ui->priority->value();

    if (process::getCount() == 0){
        int quantum = ui->priority->value();
        scheduler->setTimeQuantum(quantum);
        ui->quantum->setVisible(false);
    }

    int arrivalTime = scheduler->getTime();
    //qDebug()<< "current time: " << arrivalTime;
    scheduler->addLive(process(arrivalTime, burstTime, priority));
}

