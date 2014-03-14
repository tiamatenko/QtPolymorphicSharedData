/*
 * Shape.h
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

#ifndef SHAPE_H
#define SHAPE_H

#include "global.h"

class Shape : public QtBasePolymorphicSharedType
{
    QT_POLYMORPHIC_TYPE(Shape, ShapeData)
public:
    double x() const;
    void setX(double x);

    double y() const;
    void setY(double y);

    double z() const;
    void setZ(double z);

    double area() const;

    void printInfo() const;

    bool operator==(const Shape &shape) const;
    bool operator!=(const Shape &shape) const;
    bool operator<(const Shape &shape) const;
    bool operator<=(const Shape &shape) const;
    bool operator>(const Shape &shape) const;
    bool operator>=(const Shape &shape) const;
};

class Ellipse : public Shape
{
    QT_POLYMORPHIC_TYPE(Ellipse, EllipseData)
public:
    Ellipse(double x, double y, double z, double majorAxis, double minorAxis);

    double majorAxis() const;
    void setMajorAxis(double majorAxis);

    double minorAxis() const;
    void setMinorAxis(double minorAxis);
};

class Triangle : public Shape
{
    QT_POLYMORPHIC_TYPE(Triangle, TriangleData)
public:
    Triangle(double x, double y, double z, double side1, double side2, double angle);

    double side1() const;
    void setSide1(double side1);

    double side2() const;
    void setSide2(double side2);

    double angle() const;
    void setAngle(double angle);
};

class AbstractParallelogram : public Shape
{
    QT_POLYMORPHIC_TYPE(AbstractParallelogram, AbstractParallelogramData)
public:
    AbstractParallelogram(double x, double y, double z, double side1, double side2);

    double side1() const;
    void setSide1(double side1);

    double side2() const;
    void setSide2(double side2);
};

class Rectangle : public AbstractParallelogram
{
    QT_POLYMORPHIC_TYPE(Rectangle, RectangleData)
public:
    Rectangle(double x, double y, double z, double width, double height);

    inline double width() const { return side1(); }
    inline void setWidth(double width) { setSide1(width); }

    inline double height() const { return side2(); }
    inline void setHeight(double height) { setSide2(height); }
};

class Parallelogram : public AbstractParallelogram
{
    QT_POLYMORPHIC_TYPE(Parallelogram, ParallelogramData)
public:
    Parallelogram(double x, double y, double z, double side1, double side2, double angle);

    double angle() const;
    void setAngle(double angle);
};

class AxonometricObject
{
public:
    virtual double volume() const = 0;
    virtual QVariant foo() const = 0;
    virtual void setFoo(const QVariant &foo) = 0;
};

class Parallelepiped : public Rectangle, public AxonometricObject
{
    QT_POLYMORPHIC_TYPE_IFACE1(Parallelepiped, ParallelepipedData, AxonometricObject)
public:
    Parallelepiped(double x, double y, double z, double width, double height, double thickness);

    double thickness() const;
    void setThickness(double thickness);

    virtual double volume() const;

    virtual QVariant foo() const;
    virtual void setFoo(const QVariant &foo);
};

QT_DECLARE_POLYMORPHIC_SHARED(Shape)
QT_DECLARE_POLYMORPHIC_SHARED(Ellipse)
QT_DECLARE_POLYMORPHIC_SHARED(Triangle)
QT_DECLARE_POLYMORPHIC_SHARED(AbstractParallelogram)
QT_DECLARE_POLYMORPHIC_SHARED(Rectangle)
QT_DECLARE_POLYMORPHIC_SHARED(Parallelogram)
QT_DECLARE_POLYMORPHIC_SHARED(Parallelepiped)

#endif // SHAPE_H