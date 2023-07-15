#ifndef GIORNO_H
#define GIORNO_H

#include "event.h"
#include "QString"


class Giorno
{
public:
    Giorno();
    std::list<Event*> getEvents() const{
        return this->attività;
    }

    void insert(Event* e) {
        this->attività.push_back(e);
    }
    Event* search(QString act, QString start, QString end) const;

    void remove(QString act, QString start, QString end);


private:
    std::list<Event*> attività;
};

#endif // GIORNO_H
