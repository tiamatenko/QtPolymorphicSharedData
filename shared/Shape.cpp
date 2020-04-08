/****************************************************************************
** Shape.cpp
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

#include "Shape.h"

#include <iostream>

////// Shared Data //////

class ShapeData : public QtPolymorphicSharedData
{
    QT_POLYMORPHIC_ABSTRACT_DATA(Shape)
public:
    ShapeData(double _x, double _y, double _z) noexcept : x(_x), y(_y), z(_z)
    {
    }

    virtual double area() const noexcept = 0;

    virtual void printInfo() const noexcept
    {
        std::cout << "Type name: " << metaTypeName() << "; x = " << x << ", y = " << y << ", z = " << z;
    }

    double x;
    double y;
    double z;
};

class EllipseData : public ShapeData
{
    QT_POLYMORPHIC_DATA(Ellipse)
public:
    EllipseData(double _x, double _y, double _z, double _majorAxis, double _minorAxis) noexcept
        : ShapeData(_x, _y, _z), majorAxis(_majorAxis), minorAxis(_minorAxis) {}

    double area() const noexcept override { return M_PI * majorAxis * minorAxis; }
    void printInfo() const noexcept override
    {
        ShapeData::printInfo();
        std::cout << "; majorAxis = " << majorAxis << ", minorAxis = " << minorAxis;
    }

    double majorAxis;
    double minorAxis;
};

class TriangleData : public ShapeData
{
    QT_POLYMORPHIC_DATA(Triangle)
public:
    TriangleData(double _x, double _y, double _z, double _side1, double _side2, double _angle) noexcept
        : ShapeData(_x, _y, _z), side1(_side1), side2(_side2), angle(_angle) {}

    double area() const noexcept override { return side1 * side2 * sin(angle) / 2; }
    void printInfo() const noexcept override
    {
        ShapeData::printInfo();
        std::cout << "; side1 = " << side1 << ", side2 = " << side2 << ", angle = " << angle;
    }

    double side1;
    double side2;
    double angle;
};

class AbstractParallelogramData : public ShapeData
{
    QT_POLYMORPHIC_ABSTRACT_DATA(AbstractParallelogram)
public:
    AbstractParallelogramData(double _x, double _y, double _z, double _side1, double _side2) noexcept
        : ShapeData(_x, _y, _z), side1(_side1), side2(_side2) {}

    void printInfo() const noexcept override
    {
        ShapeData::printInfo();
        std::cout << "; side1 = " << side1 << ", side2 = " << side2;
    }

    double side1;
    double side2;
};

class ParallelogramData : public AbstractParallelogramData
{
    QT_POLYMORPHIC_DATA(Parallelogram)
public:
    ParallelogramData(double _x, double _y, double _z, double _side1, double _side2, double _angle) noexcept
        : AbstractParallelogramData(_x, _y, _z, _side1, _side2), angle(_angle) {}

    double area() const noexcept override { return side1 * side2 * sin(angle); }
    void printInfo() const noexcept override
    {
        AbstractParallelogramData::printInfo();
        std::cout << "; angle = " << angle;
    }

    double angle;
};

class RectangleData : public AbstractParallelogramData
{
    QT_POLYMORPHIC_DATA(Rectangle)
public:
    RectangleData(double _x, double _y, double _z, double _width, double _height) noexcept
        : AbstractParallelogramData(_x, _y, _z, _width, _height) {}

    double area() const noexcept override { return side1 * side2; }
    void printInfo() const noexcept override
    {
        ShapeData::printInfo();
        std::cout << "; width = " << side1 << ", height = " << side2;
    }

};

class ParallelepipedData : public RectangleData
{
    QT_POLYMORPHIC_DATA_IFACE1(Parallelepiped, AxonometricObject)
public:
    ParallelepipedData(double _x, double _y, double _z, double _width, double _height, double _thickness) noexcept
        : RectangleData(_x, _y, _z, _width, _height), thickness(_thickness) {}

    double area() const noexcept override { return 2 * (RectangleData::area() + (side1 + side2) * thickness); }
    void printInfo() const noexcept override
    {
        RectangleData::printInfo();
        std::cout << "; thickness = " << thickness;
    }
    virtual double volume() const noexcept { return side1 * side2 * thickness; }

    double thickness;
    QVariant foo;
};


////// Shared Types //////

////// Shape //////

double Shape::x() const noexcept
{
    QT_GET_D
    return d->x;
}

void Shape::setX(double x) noexcept
{
    QT_SET_D
    d->x = x;
}

double Shape::y() const noexcept
{
    QT_GET_D
    return d->y;
}

void Shape::setY(double y) noexcept
{
    QT_SET_D
    d->y = y;
}

double Shape::z() const noexcept
{
    QT_GET_D
    return d->z;
}

void Shape::setZ(double z) noexcept
{
    QT_SET_D
    d->z = z;
}

double Shape::area() const noexcept
{
    QT_GET_D
    return d->area();
}

void Shape::printInfo() const noexcept
{
    QT_GET_D
    d->printInfo();
    std::cout << std::endl;
}

bool Shape::operator==(const Shape &shape) const noexcept
{
    if (d == shape.d)
        return true;
    if (isNull() || shape.isNull() || metaTypeId() != shape.metaTypeId())
        return false;
    return qFuzzyCompare(area(), shape.area());
}

bool Shape::operator!=(const Shape &shape) const noexcept
{
    return !(*this == shape);
}

bool Shape::operator<(const Shape &shape) const noexcept
{
    if (shape.isNull())
        return false;
    if (isNull())
        return true;
    return area() < shape.area();
}

bool Shape::operator<=(const Shape &shape) const noexcept
{
    return *this == shape || *this < shape;
}

bool Shape::operator>(const Shape &shape) const noexcept
{
    if (shape.isNull())
        return true;
    if (isNull())
        return false;
    return area() > shape.area();
}

bool Shape::operator>=(const Shape &shape) const noexcept
{
    return !(*this < shape);
}

////// Ellipse //////

Ellipse::Ellipse(double x, double y, double z, double majorAxis, double minorAxis) noexcept
    : Shape(new EllipseData(x, y, z, majorAxis, minorAxis))
{
}

double Ellipse::majorAxis() const noexcept
{
    QT_GET_D
    return d->majorAxis;
}

void Ellipse::setMajorAxis(double majorAxis) noexcept
{
    QT_SET_D
    d->majorAxis = majorAxis;
}

double Ellipse::minorAxis() const noexcept
{
    QT_GET_D
    return d->majorAxis;
}

void Ellipse::setMinorAxis(double minorAxis) noexcept
{
    QT_SET_D
    d->minorAxis = minorAxis;
}

////// Triangle //////

Triangle::Triangle(double x, double y, double z, double side1, double side2, double angle) noexcept
    : Shape(new TriangleData(x, y, z, side1, side2, angle))
{
}

double Triangle::side1() const noexcept
{
    QT_GET_D
    return d->side1;
}

void Triangle::setSide1(double side1) noexcept
{
    QT_SET_D
    d->side1 = side1;
}

double Triangle::side2() const noexcept
{
    QT_GET_D
    return d->side2;
}

void Triangle::setSide2(double side2) noexcept
{
    QT_SET_D
    d->side2 = side2;
}

double Triangle::angle() const noexcept
{
    QT_GET_D
    return d->angle;
}

void Triangle::setAngle(double angle) noexcept
{
    QT_SET_D
    d->angle = angle;
}

////// AbstractParallelogram //////

double AbstractParallelogram::side1() const noexcept
{
    QT_GET_D
    return d->side1;
}

void AbstractParallelogram::setSide1(double side1) noexcept
{
    QT_SET_D
    d->side1 = side1;
}

double AbstractParallelogram::side2() const noexcept
{
    QT_GET_D
    return d->side2;
}

void AbstractParallelogram::setSide2(double side2) noexcept
{
    QT_SET_D
    d->side2 = side2;
}

////// Rectangle //////

Rectangle::Rectangle(double x, double y, double z, double width, double height) noexcept
    : AbstractParallelogram(new RectangleData(x, y, z, width, height))
{
}

////// Parallelogram //////

Parallelogram::Parallelogram(double x, double y, double z, double width, double height, double angle) noexcept
    : AbstractParallelogram(new ParallelogramData(x, y, z, width, height, angle))
{
}

double Parallelogram::angle() const noexcept
{
    QT_GET_D
    return d->angle;
}

void Parallelogram::setAngle(double angle) noexcept
{
    QT_SET_D
    d->angle = angle;
}

////// Parallelepiped //////

Parallelepiped::Parallelepiped(double x, double y, double z, double width, double height, double thickness) noexcept
    : Rectangle(new ParallelepipedData(x, y, z, width, height, thickness))
{
}

double Parallelepiped::thickness() const noexcept
{
    QT_GET_D
    return d->thickness;
}

void Parallelepiped::setThickness(double thickness) noexcept
{
    QT_SET_D
    d->thickness = qAbs(thickness);
}

double Parallelepiped::volume() const noexcept
{
    QT_GET_D
    return d->volume();
}

QVariant Parallelepiped::foo() const noexcept
{
    QT_GET_D
    return d->foo;
}

void Parallelepiped::setFoo(const QVariant &foo) noexcept
{
    QT_SET_D
    d->foo = foo;
}
