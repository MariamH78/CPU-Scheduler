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

#include "process.h"

namespace Ui {
class LiveUI;
}

class LiveUI : public QDialog
{
    Q_OBJECT

signals:
    void updateChartNeeded(); // Signal to indicate that UI update is needed
    void childClosed();

private slots:
    void updateChart(); // Slot for updating the chart
    void on_close_clicked();
    void on_add_clicked();
    void closeEvent(QCloseEvent *event);
    void updateAvgerages();

public:
    explicit LiveUI(QWidget *parent = nullptr, bool showQuantum, bool showPriority, CommonScheduler scheduler_);
    ~LiveUI();

private:
    Ui::LiveUI *ui;
    QTimer *timer; // Timer for updating the chart
	QTime startTime;
};

#endif // PRI_H

