#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include "event.cpp"
#include "event.h"
#include "mainwindow.h"
#include "day.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->setWindowTitle("Calendario");
    w->show();
    //Event* event = new Event(22, 10, "compiti", 23, 10, "23 Giugno");

   /* QLabel *label = new QLabel("Hello World");
    QPushButton *button = new QPushButton();
    label->show();
    label->setWindowTitle("CALENDAR");
    label->resize(400, 400);
    button->show();
    button->addAction( ); */




    return a.exec();
}
