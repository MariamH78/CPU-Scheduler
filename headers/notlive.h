#ifndef NOTLIVE_H
#define NOTLIVE_H


#include <QDialog>
#include <QCloseEvent>
#include "common_scheduler.h"
#include "live.h"

namespace Ui {
class notlive;
}

class notlive : public QDialog
{
    Q_OBJECT

public:
    explicit notlive(QWidget *parent = nullptr, bool showQuantum=0, bool showPriority=0, CommonScheduler *scheduler_=nullptr);
    ~notlive();
private slots:
    void on_add_clicked();

private:
    Ui::notlive *ui;
    static int COUNTER;
    CommonScheduler *scheduler;
    bool showQuantum;
    bool showPriority;
};

#endif // NOTLIVE_H

