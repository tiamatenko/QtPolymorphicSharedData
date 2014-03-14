#
# tst_QtPolymorphicImplicitSharedType.pro
#
# Copyright (c) 2014, Korobov Sergiy. All rights reserved.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301  USA

CONFIG  += testcase
CONFIG  -= app_bundle

TARGET = tst_QtPolymorphicImplicitSharedType

QT     = testlib

INCLUDEPATH += ../../shared \
               ../../include

SOURCES = tst_QtPolymorphicImplicitSharedType.cpp
          #../../shared/Shape.cpp

HEADERS = tst_QtPolymorphicImplicitSharedType.h \
          ../../shared/global.h \
          ../../shared/Shape.h \
          ../../include/QtPolymorphicSharedData.h