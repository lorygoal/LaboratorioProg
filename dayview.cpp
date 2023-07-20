#include "dayview.h"
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




DayView::DayView(Day* g, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DayView),
    g(g)

{
    //this->g = new Giorno;
    ui->setupUi(this);
    QVBoxLayout* Vlay = new QVBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(Vlay);

}

DayView::~DayView()
{
    delete ui;
}
void DayView::setDate(QString dt) {
    this->date = dt ;
}
void DayView::setUp(QString s) {
    this->show();
    this->setWindowTitle("Activities | "+ s);
    this->setDate(s);
}

void DayView::update(Event* act){
        QWidget* widget = new QWidget();
        this->widgets.append(widget);
        QLineEdit* line = new QLineEdit();
        QFont f = line->font();
        f.setPointSize(11);
        line->setFont(f);
        line->setAlignment(Qt::AlignHCenter);




        QHBoxLayout* Hlay = new QHBoxLayout;
        QLabel* from = new QLabel("     From:");

        QLabel* start = new QLabel;

        QLabel* to = new QLabel("     To:");


        QLabel* end = new QLabel;

        widget->setMinimumHeight(50);
        ui->scrollAreaWidgetContents->layout()->addWidget(widget);


        QPushButton* remove = new QPushButton("Delete");

        widget->setLayout(Hlay);
        widget->layout()->addWidget(line);
        widget->layout()->addWidget(from);
        widget->layout()->addWidget(start);
        widget->layout()->addWidget(to);
        widget->layout()->addWidget(end);
        widget->layout()->addWidget(remove);


        QString activ = act->getActivity();
        line->setText(activ);

        QString sh = act->getStartHour();
        start->setText(sh);

        QString eh = act->getEnd_Hour();
        end->setText(eh);

        connect(remove, &QPushButton::clicked, this, [widget, line, this, start, end](){
            this->g->remove(line->text(), start->text(), end->text());
            qDeleteAll(widgets.begin(), widgets.end());
            widgets.clear();
            this->g->updateView();
          });
 }


void DayView::on_pushButton_clicked()
{   ui->pushButton->setEnabled(false);
    QWidget* widget = new QWidget();
    this->widgets.append(widget);

    QLineEdit* line = new QLineEdit();

    QFont f = line->font();
    f.setPointSize(11);
    line->setFont(f);
    line->setAlignment(Qt::AlignHCenter);



    QHBoxLayout* Hlay = new QHBoxLayout;
    QLabel* from = new QLabel("     From:");
    QTimeEdit* start = new QTimeEdit;
    QLabel* to = new QLabel("     To:");
    QPushButton* confirm = new QPushButton("Confirm");
    QPushButton* remove = new QPushButton("Delete");

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
    widget->layout()->addWidget(remove);
    remove->hide();



    connect(confirm, &QPushButton::clicked, this, [start, line, end, this, confirm, widget, remove](){
        ui->pushButton->setEnabled(true);

        Event* e = new Event(start->text(), line->text(), end->text(), this->date);

        this->g->insert(e);
        confirm->hide();
        remove->show();
        line->setEnabled(false);
        qDeleteAll(widgets.begin(), widgets.end());
        widgets.clear();
        //update();
        this->g->updateView();



    });




}



