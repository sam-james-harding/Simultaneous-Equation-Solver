#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_solveButton_clicked()
{
    //variable initialisation
    double eq1x, eq1y, eq1val;
    double eq2x, eq2y, eq2val;

    std::string xValString, yValString;

    double xVal, yVal;
    double determinant;

    //getting values from spinners
    eq1x = ui->eq1varXSpinner->value();
    eq1y = ui->eq1varYSpinner->value();
    eq1val = ui->eq1varValSpinner->value();

    eq2x = ui->eq2varXSpinner->value();
    eq2y = ui->eq2varYSpinner->value();
    eq2val = ui->eq2varValSpinner->value();

    //calculating results
    determinant = (eq1x*eq2y)-(eq1y*eq2x);

    if (determinant!=0) {
        //if the equations have solutions
        xVal = ((eq2y*eq1val) - (eq1y*eq2val))/(determinant);
        yVal = ((eq2val*eq1x)-(eq2x*eq1val))/(determinant);

        //setting strings to calculated values
        xValString = std::to_string(xVal);
        yValString = std::to_string(yVal);
    } else {
        //if the equations have no solution
        xValString = "No solution";
        yValString = "No solution";
    }

    //setting labels to string values
    QString xStr = QString::fromStdString(xValString);
    QString yStr = QString::fromStdString(yValString);

    ui->xValLbl->setText(xStr);
    ui->yValLbl->setText(yStr);
}

