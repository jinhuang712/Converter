#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->q1->setText("0.857");
    ui->q2->setText("-0.001");
    ui->q3->setText("-0.488");
    ui->q4->setText("0.163");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_euler_to_quaternion_clicked()
{
    double x = ui->rX->text().toDouble();
    double y = ui->rY->text().toDouble();
    double z = ui->rZ->text().toDouble();
    Euler e(x, y, z);
    Quaternion q = e.toQuaternion();

    ui->q1->setText(QString::number(q.scalar, 'f', 5));
    ui->q2->setText(QString::number(q.x,      'f', 5));
    ui->q3->setText(QString::number(q.y,      'f', 5));
    ui->q4->setText(QString::number(q.z,      'f', 5));

    ui->centralWidget->repaint();
}

void MainWindow::on_quaternion_to_euler_clicked()
{

    double scalar =  ui->q1->text().toDouble();
    double q2 =      ui->q2->text().toDouble();
    double q3 =      ui->q3->text().toDouble();
    double q4 =      ui->q4->text().toDouble();
    Quaternion q(scalar, q2, q3, q4);
    Euler e = q.toEuler();
    ui->rX->setText(QString::number(e.x, 'f', 5));
    ui->rY->setText(QString::number(e.y, 'f', 5));
    ui->rZ->setText(QString::number(e.z, 'f', 5));

    ui->centralWidget->repaint();
}

