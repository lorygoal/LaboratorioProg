#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QPushButton>
#include <QLabel>


class Event
{
public:
    Event(QString sh, QString act, QString eh, QString d ): start_hour(sh), activity(act), end_hour(eh), day(d) {}
    ~Event();

    QString getActivity(){
        return this->activity;
    }

private:
    QString start_hour;
    QString activity;
    QString end_hour;
    QString day;

};

#endif // EVENT_H
