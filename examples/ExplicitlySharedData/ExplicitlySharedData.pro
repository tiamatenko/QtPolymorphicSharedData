#
# ExplicitlySharedData.pro
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

TARGET = ExplicitlySharedData

TEMPLATE = app

QT       += core
#QT       -= gui

CONFIG   += console c++11
CONFIG   -= app_bundle

#QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ../../shared \
               ../../include

DEFINES += USE_EXPLICIT_SHARED_DATA _USE_MATH_DEFINES

SOURCES += ../../shared/Shape.cpp \
           ../main.cpp

HEADERS += ../../shared/global.h \
           ../../shared/Shape.h \
           ../../include/QtPolymorphicSharedData.h
