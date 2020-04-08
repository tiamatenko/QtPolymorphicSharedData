/****************************************************************************
** Shape.h
**
** Copyright (c) 2015-2020, Korobov Sergiy.
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

#ifndef SHAPE_H
#define SHAPE_H

#include "global.h"

#include <qmath.h>

class Shape : public QtBasePolymorphicSharedType
{
    QT_POLYMORPHIC_TYPE(Shape, ShapeData)
public:
    double x() const noexcept;
    void setX(double x) noexcept;

    double y() const noexcept;
    void setY(double y) noexcept;

    double z() const noexcept;
    void setZ(double z) noexcept;

    double area() const noexcept;

    void printInfo() const noexcept;

    bool operator==(const Shape &shape) const noexcept;
    bool operator!=(const Shape &shape) const noexcept;
    bool operator<(const Shape &shape) const noexcept;
    bool operator<=(const Shape &shape) const noexcept;
    bool operator>(const Shape &shape) const noexcept;
    bool operator>=(const Shape &shape) const noexcept;
    inline operator QVariant() const noexcept
    { return QVariant::fromValue(*this); }
};

class Ellipse : public Shape
{
    QT_POLYMORPHIC_TYPE(Ellipse, EllipseData)
public:
    Ellipse(double x, double y, double z, double majorAxis, double minorAxis) noexcept;

    double majorAxis() const noexcept;
    void setMajorAxis(double majorAxis) noexcept;

    double minorAxis() const noexcept;
    void setMinorAxis(double minorAxis) noexcept;
};

class Triangle : public Shape
{
    QT_POLYMORPHIC_TYPE(Triangle, TriangleData)
public:
    Triangle(double x, double y, double z, double side1, double side2, double angle) noexcept;

    double side1() const noexcept;
    void setSide1(double side1) noexcept;

    double side2() const noexcept;
    void setSide2(double side2) noexcept;

    double angle() const noexcept;
    void setAngle(double angle) noexcept;
};

class AbstractParallelogram : public Shape
{
    QT_POLYMORPHIC_TYPE(AbstractParallelogram, AbstractParallelogramData)
public:
    AbstractParallelogram(double x, double y, double z, double side1, double side2) noexcept;

    double side1() const noexcept;
    void setSide1(double side1) noexcept;

    double side2() const noexcept;
    void setSide2(double side2) noexcept;
};

class Rectangle : public AbstractParallelogram
{
    QT_POLYMORPHIC_TYPE(Rectangle, RectangleData)
public:
    Rectangle(double x, double y, double z, double width, double height) noexcept;

    inline double width() const noexcept { return side1(); }
    inline void setWidth(double width) noexcept { setSide1(width); }

    inline double height() const noexcept { return side2(); }
    inline void setHeight(double height) noexcept { setSide2(height); }
};

class Parallelogram : public AbstractParallelogram
{
    QT_POLYMORPHIC_TYPE(Parallelogram, ParallelogramData)
public:
    Parallelogram(double x, double y, double z, double side1, double side2, double angle) noexcept;

    double angle() const noexcept;
    void setAngle(double angle) noexcept;
};

class AxonometricObject
{
public:
    virtual double volume() const noexcept = 0;
    virtual QVariant foo() const noexcept = 0;
    virtual void setFoo(const QVariant &foo) noexcept = 0;
};

class Parallelepiped : public Rectangle, public AxonometricObject
{
    QT_POLYMORPHIC_TYPE_IFACE1(Parallelepiped, ParallelepipedData, AxonometricObject)
public:
    Parallelepiped(double x, double y, double z, double width, double height, double thickness) noexcept;

    double thickness() const noexcept;
    void setThickness(double thickness) noexcept;

    double volume() const noexcept override;

    QVariant foo() const noexcept override;
    void setFoo(const QVariant &foo) noexcept override;
};

QT_DECLARE_POLYMORPHIC_SHARED(Shape)
QT_DECLARE_POLYMORPHIC_SHARED(Ellipse)
QT_DECLARE_POLYMORPHIC_SHARED(Triangle)
QT_DECLARE_POLYMORPHIC_SHARED(AbstractParallelogram)
QT_DECLARE_POLYMORPHIC_SHARED_INTERFACE(AxonometricObject)
QT_DECLARE_POLYMORPHIC_SHARED(Rectangle)
QT_DECLARE_POLYMORPHIC_SHARED(Parallelogram)
QT_DECLARE_POLYMORPHIC_SHARED(Parallelepiped)

#endif // SHAPE_H
