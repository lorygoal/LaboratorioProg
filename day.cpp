#include "day.h"

Day::Day()
{
    this->d = new DayView(this);

}

void Day::viewSetUp(QString s) {
    this->d->setUp(s);
}

void Day::updateView() {
    for (auto act: this->attività) {
        d->update(act);
    }
}

Event* Day::search(QString act, QString start, QString end) const {
    for (auto it: this->attività) {
        if (it->getActivity() == act && it->getStartHour()==start && it->getEnd_Hour()== end)
            return it;
        }
    return nullptr;
    }

std::list<Event*> Day::search(QString act) {
    std::list<Event*> acts;
    for (auto it: this->attività) {
        if (it->getActivity() == act)
             acts.push_back(it);
    }
    return acts;
}

void Day::remove(QString act, QString start, QString end) {
    auto e = search(act, start, end);

    if (e != nullptr){
        this->attività.remove(e);
    }
}


