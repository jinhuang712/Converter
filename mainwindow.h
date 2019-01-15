#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuaternion>
#include <QVector3D>
#include "quaternion.h"
#include "euler.h"

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

private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
