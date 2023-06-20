#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "day.h"
#include <iostream>
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
       Day* d = new Day;
       d->show();
       this->calendario.insert(std::pair<QString, Day*>(title, d));
       d->setWindowTitle("Le tue attività del "+ title);
       d->setDate(title); }
    else {
       it->second->show();
       it->second->setWindowTitle("Le tue attività del "+ title);
       it->second->setDate(title);
    }

    /*for (auto i : this->calendario) {
        QLabel* l = new QLabel(i.first);
        l->show(); }*/


}

