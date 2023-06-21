#include "day.h"
#include "ui_day.h"
#include "QPushButton"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QLineEdit"
#include "QWidget"
#include "QTimeEdit"
#include "QLabel"
#include "event.h"
#include "QTextEdit"



Day::Day(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Day)
{
    ui->setupUi(this);
    QVBoxLayout* Vlay = new QVBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(Vlay);

    for (auto act : this->attività) {
        QWidget* widget = new QWidget();
        QLineEdit* line = new QLineEdit();
        //QTextEdit* line = new QTextEdit();
        QFont f = line->font();
        f.setPointSize(11);
        line->setFont(f);
        line->setAlignment(Qt::AlignHCenter);




        QHBoxLayout* Hlay = new QHBoxLayout;
        QLabel* from = new QLabel("     From:");
        QTimeEdit* start = new QTimeEdit;
        QLabel* to = new QLabel("     To:");

        QTimeEdit* end = new QTimeEdit;
        widget->setMinimumHeight(50);
        ui->scrollAreaWidgetContents->layout()->addWidget(widget);

        widget->setLayout(Hlay);
        widget->layout()->addWidget(line);
        widget->layout()->addWidget(from);
        widget->layout()->addWidget(start);
        widget->layout()->addWidget(to);
        widget->layout()->addWidget(end);


        QString activ = act->getActivity();
        line->setText(activ);


}



}

Day::~Day()
{
    delete ui;
}
void Day::setDate(QString dt) {
    this->date = dt ;
}

void Day::on_pushButton_clicked()
{   ui->pushButton->setEnabled(false);
    QWidget* widget = new QWidget();
    QLineEdit* line = new QLineEdit();
    //QTextEdit* line = new QTextEdit();
    QFont f = line->font();
    f.setPointSize(11);
    line->setFont(f);
    line->setAlignment(Qt::AlignHCenter);



    QHBoxLayout* Hlay = new QHBoxLayout;
    QLabel* from = new QLabel("     From:");
    QTimeEdit* start = new QTimeEdit;
    QLabel* to = new QLabel("     To:");
    QPushButton* confirm = new QPushButton("Confirm");

    QTimeEdit* end = new QTimeEdit;
    widget->setMinimumHeight(50);
    ui->scrollAreaWidgetContents->layout()->addWidget(widget);

    widget->setLayout(Hlay);
    widget->layout()->addWidget(line);
    widget->layout()->addWidget(from);
    widget->layout()->addWidget(start);
    widget->layout()->addWidget(to);
    widget->layout()->addWidget(end);
    widget->layout()->addWidget(confirm);



    connect(confirm, &QPushButton::clicked, this, [start, line, end, this, confirm, widget](){
        ui->pushButton->setEnabled(true);
        Event* e = new Event(start->text(), line->text(), end->text(), this->date);
        this->attività.push_front(e);
        confirm->hide();


        line->setEnabled(false);


    });



}



