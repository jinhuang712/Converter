#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
#include <stdio.h>
#include <QtMath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->centralWidget);
    this->setWindowTitle("Quaternion & Euler Converter");
    mode = "XYZ";
    radian = false;
    initialized = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*  slots */
void MainWindow::on_euler_to_quaternion_clicked()
{
    initialized = true;
    e2q();
}

void MainWindow::on_quaternion_to_euler_clicked()
{
    initialized = true;
    q2e();
}

void MainWindow::on_mode_currentTextChanged(const QString &arg1)
{
    mode = arg1;
    if (!initialized)
        return;
    if (last_q2e)
        q2e();
    else
        e2q();
}

void MainWindow::on_math_currentIndexChanged(const QString &arg1)
{
    double x = ui->rX->text().toDouble();
    double y = ui->rY->text().toDouble();
    double z = ui->rZ->text().toDouble();
    if (arg1 == "Radians") {
        if (radian)
            return;
        ui->rX->setText(QString::number(x * M_PI / 180.0));
        ui->rY->setText(QString::number(y * M_PI / 180.0));
        ui->rZ->setText(QString::number(z * M_PI / 180.0));
        radian = true;
    } else {
        if (!radian)
            return;
        ui->rX->setText(QString::number(x * 180.0 / M_PI));
        ui->rY->setText(QString::number(y * 180.0 / M_PI));
        ui->rZ->setText(QString::number(z * 180.0 / M_PI));
        radian = false;
    }
}

/* helper */
void MainWindow::e2q()
{
    double x = ui->rX->text().toDouble();
    double y = ui->rY->text().toDouble();
    double z = ui->rZ->text().toDouble();
    Euler e(x, y, z);
    Quaternion q = e.toQuaternion(mode, radian);

    ui->q1->setText(QString::number(q.scalar, 'f', 5));
    ui->q2->setText(QString::number(q.x,      'f', 5));
    ui->q3->setText(QString::number(q.y,      'f', 5));
    ui->q4->setText(QString::number(q.z,      'f', 5));

    last_q2e = false;
    ui->centralWidget->repaint();
}


void MainWindow::q2e()
{
    double scalar =  ui->q1->text().toDouble();
    double q2 =      ui->q2->text().toDouble();
    double q3 =      ui->q3->text().toDouble();
    double q4 =      ui->q4->text().toDouble();
    Quaternion q(scalar, q2, q3, q4);
    Euler e = q.toEuler(mode, radian);
    ui->rX->setText(QString::number(e.x, 'f', 5));
    ui->rY->setText(QString::number(e.y, 'f', 5));
    ui->rZ->setText(QString::number(e.z, 'f', 5));

    last_q2e = true;
    ui->centralWidget->repaint();
}
