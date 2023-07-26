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
    ~Day();
    /*std::list<Event*> getEvents() const{
        return this->attività;
    }*/

    /*void insert(Event* e) {
        this->attività.push_back(e);
    }*/

    void insert(Event& e) {
        this->attività.push_back(e);
    }
    std::_List_const_iterator<Event> search(QString act, QString start, QString end) const;

    std::list<Event> search(QString act);


    void remove(QString act, QString start, QString end);

    int getActSize() {
        return attività.size();
    }
    std::_List_const_iterator<Event> getListEnd() {
        return this->attività.end();
    }

   /* DayView* getDayView(){
        return this->d;
    }  */

    void viewSetUp(QString s);

    void updateView();


private:
    //std::list<Event*> attività;
    std::list<Event> attività;
    DayView* d;
};

#endif // DAY_H
