#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include "event.cpp"
#include "event.h"
#include "mainwindow.h"
#include "dayview.h"
#include "tester.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->setWindowTitle("Register");
    w->show();







    return a.exec();
}
