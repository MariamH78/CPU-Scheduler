#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	// For combobox settings.
	enum schedulerOption {
		FCFS = 0,
		SJF_PREEMPT = 1,
		SJF_NON_PREEMPT = 2,
		PRI_PREEMPT = 3,
		PRI_NON_PREEMPT = 4,
		ROUND_ROBIN = 5,	
	};

	// Constructor and destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
