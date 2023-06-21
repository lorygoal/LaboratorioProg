#ifndef DAY_H
#define DAY_H

#include <QDialog>
#include "QString"
#include "event.h"

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

private slots:
    void on_pushButton_clicked();



private:
    Ui::Day *ui;
    QString date;
    std::list<Event*> attività;
};

#endif // DAY_H
