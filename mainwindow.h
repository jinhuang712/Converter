#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuaternion>
#include <QVector3D>

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

    void on_actionRadians_triggered();

    void on_actionDegrees_triggered();

    void on_actionYZX_triggered();

    void on_actionZXY_triggered();

    void on_actionXYZ_triggered();

private:
    Ui::MainWindow *ui;
    QString mode;
    bool radian;
};


#endif // MAINWINDOW_H
