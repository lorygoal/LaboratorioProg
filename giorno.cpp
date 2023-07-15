#include "giorno.h"

Giorno::Giorno()
{
}

Event* Giorno::search(QString act, QString start, QString end) const {
    for (auto it: this->attività) {
        if (it->getActivity() == act && it->getStartHour()==start && it->getEnd_Hour()== end)
            return it;
        }
    }

void Giorno::remove(QString act, QString start, QString end) {
    Event* e = search(act, start, end);
    this->attività.remove(e);
}
