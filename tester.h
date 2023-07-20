#ifndef TESTER_H
#define TESTER_H

#include <QObject>
#include <QTest>
#include "day.h"
#include "dayview.h"
#include "event.h"

class Tester : public QObject
{
    Q_OBJECT

private slots:
    void insertTest();
    void researchTest();
    void removeTest();



};

#endif // TESTER_H
