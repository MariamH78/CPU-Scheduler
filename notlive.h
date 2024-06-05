#ifndef NOT_LIVE_H
#define NOT_LIVE_H

#include <QDialog>
#include <QCloseEvent>
#include "common_scheduler.h"

namespace Ui {
class NotLiveUI;
}

class NotLiveUI : public QDialog
{
    Q_OBJECT
signals:
    void childClosed();
public:
    explicit NotLiveUI(QWidget *parent = nullptr, bool showQuantum, bool showPriority, CommonScheduler& scheduler_);
    ~NotLiveUI();
private slots:
    void on_pushButton_clicked();
    void on_choose_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Ui::NotLiveUI *ui;
	static int COUNTER = 0;
};

#endif 
