#############################################################################
##
## tst_QtPolymorphicExplicitSharedType.pro
##
## Copyright (c) 2014, Korobov Sergiy.
## All rights reserved.
## Contact: Korobov Sergiy (tiamatenko@gmail.com)
##
## This file is part of the QtPolymorphicSharedData.
##
## The QtPolymorphicSharedData is free software:
## you can redistribute it and/or modify it under the terms of the
## Lesser GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## The QtPolymorphicSharedData is distributed in the hope
## that it will be useful, but WITHOUT ANY WARRANTY; without even the
## implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
## See the Lesser GNU General Public License for more details.
##
## You should have received a copy of the Lesser GNU General Public License
## along with the QtPolymorphicSharedData.
## If not, see <http://www.gnu.org/licenses/>.
##
#############################################################################

TARGET = tst_QtPolymorphicExplicitSharedType

CONFIG *= qt depend_includepath
QT       += testlib
CONFIG   -= app_bundle

INCLUDEPATH += ../../shared \
               ../../include

DEFINES += USE_EXPLICIT_SHARED_DATA

SOURCES += tst_QtPolymorphicExplicitSharedType.cpp \
           ../../shared/Shape.cpp

HEADERS += ../../shared/global.h \
           ../../shared/Shape.h \
           ../../include/QtPolymorphicSharedData.h
