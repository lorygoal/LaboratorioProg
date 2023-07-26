
#include "tester.h"



void Tester::insertTest(){
    Day g;
    Event ev("10", "palestra", "12", "13/08/2023");
    Event& e = ev;
    g.insert(e);
    QCOMPARE(g.getActSize(), 1);
}
void Tester::researchTest(){
    Day g;
    Event ev("10", "palestra", "12", "13/08/2023");
    Event& e = ev;
    g.insert(e);
    QCOMPARE(g.search("palestra", "10", "12")->getActivity(), "palestra");
    QCOMPARE(g.search("palestra", "10", "12")->getStartHour(), "10");
    QCOMPARE(g.search("palestra", "10", "12")->getEnd_Hour(), "12");
    QCOMPARE(g.search("palestra", "10", "14"), g.getListEnd());

}
void Tester::removeTest(){
    Day g;
    Event e("10", "palestra", "12", "13/08/2023");
    g.insert(e);
    g.remove("palestra", "10", "12");
    QCOMPARE(g.getActSize(), 0);
}

//QTEST_MAIN(Tester)

