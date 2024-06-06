#ifndef LIVE_H
#define LIVE_H
#include <QDialog>
#include <thread>
#include <chrono>
#include <QTime>
#include <QPainter>
#include <QTimer>
#include <qtconcurrentrun.h>
#include <QThread>
#include <QCloseEvent>
#include "common_scheduler.h"

#include "process.h"

namespace Ui {
class live;
}

class live : public QDialog
{
    Q_OBJECT
signals:
    void updateChartNeeded(); // Signal to indicate that UI update is needed
    void startSignal();

private slots:
    void updateChart(); // Slot for updating the chart
    void on_add_clicked();
    void updateAverages();


public:
    explicit live(QWidget *parent = nullptr, bool showQuantum=0, bool showPriority=0, CommonScheduler *scheduler_=nullptr);
    //static void start();
    ~live();

private:
    virtual void paintEvent(QPaintEvent *event);
    Ui::live *ui;
    QTimer *timer; // Timer for updating the chart
    QTime startTime;
    CommonScheduler* scheduler;
};

#endif // LIVE_H


