/*#include <QObject>
#include <QTest>
#include "giorno.h"
#include "event.h" */

#include "tester.h"



void Tester::insertTest(){
    Giorno* g = new Giorno;
    Event* e = new Event("10", "palestra", "12", "13/08/2023");
    g->insert(e);
    QCOMPARE(g->getEvents().size(), 1);
}
void Tester::researchTest(){
    Giorno* g = new Giorno;
    Event* e = new Event("10", "palestra", "12", "13/08/2023");
    g->insert(e);
    QCOMPARE(g->search("palestra", "10", "12"), e);

}
void Tester::removeTest(){
    Giorno* g = new Giorno;
    Event* e = new Event("10", "palestra", "12", "13/08/2023");
    g->insert(e);
    g->remove("palestra", "10", "12");
    QCOMPARE(g->getEvents().size(), 0);
}

//QTEST_MAIN(Tester)

