/****************************************************************************
** tst_QtPolymorphicImplicitSharedType.h
**
** Copyright (c) 2014, Korobov Sergiy.
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

#ifndef TST_QT_POLYMORPHIC_IMPLICIT_SHARED_TYPE
#define TST_QT_POLYMORPHIC_IMPLICIT_SHARED_TYPE

#include <QtCore/QObject>

class tst_QtPolymorphicImlicitSharedType : public QObject
{
    Q_OBJECT
public:
    tst_QtPolymorphicImlicitSharedType() {}

private slots:
    void initTestCase();
    void myFirstTest();
    void mySecondTest();
    void cleanupTestCase();
};


#endif // TST_QT_POLYMORPHIC_IMPLICIT_SHARED_TYPE
