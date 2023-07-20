#ifndef DAY_H
#define DAY_H

#include "event.h"
#include "QString"


class Day;
#include "dayview.h"

class Day
{
public:
    Day();
    /*std::list<Event*> getEvents() const{
        return this->attività;
    }*/

    void insert(Event* e) {
        this->attività.push_back(e);
    }
    Event* search(QString act, QString start, QString end) const;

    std::list<Event*> search(QString act);


    void remove(QString act, QString start, QString end);

    int getActSize() {
        return attività.size();
    }

   /* DayView* getDayView(){
        return this->d;
    }  */

    void viewSetUp(QString s);

    void updateView();


private:
    std::list<Event*> attività;
    DayView* d;
};

#endif // DAY_H
