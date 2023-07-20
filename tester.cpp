/*#include <QObject>
#include <QTest>
#include "giorno.h"
#include "event.h" */

#include "tester.h"



void Tester::insertTest(){
    Day* g = new Day;
    Event* e = new Event("10", "palestra", "12", "13/08/2023");
    g->insert(e);
    QCOMPARE(g->getActSize(), 1);
}
void Tester::researchTest(){
    Day* g = new Day;
    Event* e = new Event("10", "palestra", "12", "13/08/2023");
    g->insert(e);
    QCOMPARE(g->search("palestra", "10", "12"), e);
    QCOMPARE(g->search("palestra", "10", "14"), nullptr);

}
void Tester::removeTest(){
    Day* g = new Day;
    Event* e = new Event("10", "palestra", "12", "13/08/2023");
    g->insert(e);
    g->remove("palestra", "10", "12");
    QCOMPARE(g->getActSize(), 0);
}

//QTEST_MAIN(Tester)

