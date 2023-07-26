#ifndef DAYVIEW_H
#define DAYVIEW_H

#include <QDialog>
#include "QString"
#include "event.h"


namespace Ui {
class Day;
}

class DayView;
#include "day.h"

class DayView : public QDialog
{
    Q_OBJECT

public:
    explicit DayView( Day* g, QWidget *parent = nullptr);
    ~DayView();

    void setDate(QString dt);
    void setUp(QString s);
    void update(Event& act);

private slots:
    void on_pushButton_clicked();




private:
    Ui::Day *ui;
    QString date;
    Day* g;
    QList<QWidget*> widgets;
};


#endif // DAYVIEW_H
