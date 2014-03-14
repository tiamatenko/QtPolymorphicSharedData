/*
 * tst_QtPolymorphicImplicitSharedType.cpp
 *
 * Copyright (c) 2014, Korobov Sergiy. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 */

#include "tst_QtPolymorphicImplicitSharedType.h"

#include <QtTest/QtTest>

//#include <math.h>

#include "Shape.h"

void tst_QtPolymorphicImlicitSharedType::initTestCase()
{
    qDebug("called before everything else");
}

void tst_QtPolymorphicImlicitSharedType::myFirstTest()
{
    QVERIFY(1 == 1);
}

void tst_QtPolymorphicImlicitSharedType::mySecondTest()
{
    QVERIFY(1 != 2);
}

void tst_QtPolymorphicImlicitSharedType::cleanupTestCase()
{
    qDebug("called after myFirstTest and mySecondTest");
}

QTEST_MAIN(tst_QtPolymorphicImlicitSharedType)
