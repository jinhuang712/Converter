#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_euler_to_quaternion_clicked();

    void on_quaternion_to_euler_clicked();

    void on_mode_currentTextChanged(const QString &arg1);

    void on_math_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString mode;
    bool radian;
    bool last_q2e;
    bool initialized;

    void q2e();
    void e2q();
};


#endif // MAINWINDOW_H
