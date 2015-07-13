/****************************************************************************
** tst_QtPolymorphicImplicitSharedType.cpp
**
** Copyright (c) 2015, Korobov Sergiy.
** All rights reserved.
** Contact: Korobov Sergiy (tiamatenko@gmail.com)
**
** This file is part of the QtPolymorphicSharedData.
**
** The QtPolymorphicSharedData is free software:
** you can redistribute it and/or modify it under the terms of the
** Lesser GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** The QtPolymorphicSharedData is distributed in the hope
** that it will be useful, but WITHOUT ANY WARRANTY; without even the
** implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the Lesser GNU General Public License for more details.
**
** You should have received a copy of the Lesser GNU General Public License
** along with the QtPolymorphicSharedData.
** If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include <QtTest>

#include "Shape.h"

#include <QObject>

class tst_QtPolymorphicImplicitSharedType : public QObject
{
    Q_OBJECT
public:
    tst_QtPolymorphicImplicitSharedType() {}

private slots:
    void initTestCase();
    void myFirstTest();
    void mySecondTest();
    void cleanupTestCase();
};

void tst_QtPolymorphicImplicitSharedType::initTestCase()
{
    qDebug("called before everything else");
}

void tst_QtPolymorphicImplicitSharedType::myFirstTest()
{
    QVERIFY(1 == 1);
}

void tst_QtPolymorphicImplicitSharedType::mySecondTest()
{
    QVERIFY(1 != 2);
}

void tst_QtPolymorphicImplicitSharedType::cleanupTestCase()
{
    qDebug("called after myFirstTest and mySecondTest");
}

QTEST_MAIN(tst_QtPolymorphicImplicitSharedType)
#include "tst_QtPolymorphicImplicitSharedType.moc"
