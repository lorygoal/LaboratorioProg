#include "day.h"

Day::Day()
{
    this->d = new DayView(this);

}

Day::~Day(){
   // delete this->d;
}

void Day::viewSetUp(QString s) {
    this->d->setUp(s);
}

void Day::updateView() {
    //for (auto act: this->attività) {
    for (auto act: this->attività) {
        d->update(act);
    }
}

std::_List_const_iterator<Event> Day::search(QString act, QString start, QString end) const {
    std::_List_const_iterator<Event> it;
    for (it = this->attività.begin(); it != this->attività.end(); it++) {
        if (it->getActivity() == act && it->getStartHour()==start && it->getEnd_Hour()== end)
            return it;
        }
    return it;
    }

std::list<Event> Day::search(QString act) {
    std::list<Event> acts;
    for (auto it: this->attività) {
        if (it.getActivity() == act)
             acts.push_back(it);
    }
    return acts;
}

void Day::remove(QString act, QString start, QString end) {
    auto e = search(act, start, end);

    if (e != this->attività.end()){
        this->attività.erase(e);

    }
}


