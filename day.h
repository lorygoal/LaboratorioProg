#ifndef DAY_H
#define DAY_H

#include <QDialog>
#include <QList>
#include "QString"
#include "event.h"
#include "giorno.h"

namespace Ui {
class Day;
}

class Day : public QDialog
{
    Q_OBJECT

public:
    explicit Day(QWidget *parent = nullptr);
    ~Day();

    void setDate(QString dt);
    void update();

private slots:
    void on_pushButton_clicked();



private:
    Ui::Day *ui;
    QString date;
    Giorno* g;
    QList<QWidget*> widgets;
};

#endif // DAY_H
