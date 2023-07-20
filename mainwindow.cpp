#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dayview.h"
#include <iostream>
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString title = ui->dateEdit->text();
    auto it = this->calendario.find(title);
    if (it == this->calendario.end() ) {
       Day* g = new Day;
       this->calendario.insert(std::pair<QString, Day*>(title, g));
       g->viewSetUp(title);
}
    else {
       it->second->viewSetUp(title);
    }



}

