#ifndef TESTQTPOLYMORHICSHAREDDATA_H
#define TESTQTPOLYMORHICSHAREDDATA_H

#include <QtTest/QtTest>

class TestQtPolymorhicSharedData : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void myFirstTest();
    void mySecondTest();
    void cleanupTestCase();
};

#endif //TESTQTPOLYMORHICSHAREDDATA_H
