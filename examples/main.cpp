/****************************************************************************
** main.cpp
**
** Copyright (c) 2015-2016, Korobov Sergiy.
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

#include <QCoreApplication>
#include <QDebug>

#include "Shape.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Ellipse ellipse1;
    Ellipse ellipse2(ellipse1);
    Ellipse ellipse3(ellipse2);
    Ellipse ellipse4(0.0, 0.0, 0.0, 100.0, 100.0);
    Ellipse ellipse5 = ellipse4;
    qSwap(ellipse3, ellipse5);
    ellipse3.setX(50);
    ellipse3.setY(50);
    ellipse3.setZ(50);
    ellipse4.setMinorAxis(200.0);
    ellipse4.setMajorAxis(200.0);

    Triangle triangle1;
    Triangle triangle2(triangle1);
    Triangle triangle3(triangle2);
    Triangle triangle4(50.0, 50.0, 0.0, 100.0, 100.0, 2.0);
    Triangle triangle5(triangle4);
    triangle3 = triangle4;
    triangle3.setX(50);
    triangle3.setY(50);
    triangle3.setZ(50);
    triangle4.setSide1(200.0);
    triangle4.setSide2(200.0);
    triangle4.setAngle(M_PI / 2);

    Rectangle rect1;
    Rectangle rect2(rect1);
    Rectangle rect3(rect2);
    Rectangle rect4(100.0, 100.0, 0.0, 300.0, 200.0);
    Rectangle rect5(rect4);
    rect3 = rect4;
    rect3.setX(50);
    rect3.setY(50);
    rect3.setZ(50);
    rect4.detach();
    rect4.setWidth(100.0);
    rect4.setHeight(100.0);

    rect3.setX(100.0);
    rect3.setY(200.0);
    rect4.setX(300.0);
    rect4.setY(400.0);

    rect5.detach();

    qInfo() << "rect1 is" << (rect1 == rect2 ? "equal" : "not equal") << "rect2";
    qInfo() << "rect2 is" << (rect2 == rect3 ? "equal" : "not equal") << "rect3";
    qInfo() << "rect3 is" << (rect3 == rect4 ? "equal" : "not equal") << "rect4";
    qInfo() << "rect4 is" << (rect4 == rect5 ? "equal" : "not equal") << "rect5";
    qInfo() << "rect3 is" << (rect3 == rect5 ? "equal" : "not equal") << "rect5";

    Parallelogram pr1;
    Parallelogram pr2(pr1);
    Parallelogram pr3(pr2);
    Parallelogram pr4(100.0, 100.0, 0.0, 300.0, 200.0, 0.5);
    Parallelogram pr5(pr4);
    pr3 = pr4;
    pr3.setX(50);
    pr3.setY(50);
    pr3.setZ(50);
    pr4.detach();
    pr4.setSide1(100.0);
    pr4.setSide2(100.0);

    pr3.setX(100.0);
    pr3.setY(200.0);
    pr4.setX(300.0);
    pr4.setY(400.0);

    qInfo() << "pr3 is" << (pr3 == pr4 ? "equal" : "not equal") << "pr4";
    qInfo() << "rect3 is" << (rect3 != pr4 ? "not equal" : "equal") << "pr4";

    Parallelepiped prl1;
    Parallelepiped prl2(prl1);
    Parallelepiped prl3(prl2);
    Parallelepiped prl4(100.0, 100.0, 0.0, 300.0, 200.0, 100.0);
    Parallelepiped prl5(prl4);

    prl3 = prl4;
    prl3.setX(50);
    prl3.setY(50);
    prl3.setZ(50);
    prl4.detach();
    prl4.setSide1(100.0);
    prl4.setSide2(100.0);

    prl3.setX(100.0);
    prl3.setY(200.0);
    prl4.setX(300.0);
    prl4.setY(400.0);
    prl4.setThickness(200.0);
    prl5.setThickness(300.0);

    prl3.setFoo("Foo");
    prl4.setFoo(12345);
    prl5.setFoo(12.3344);

    qInfo("Test shape list");

    QList<Shape> shapes;
    shapes << ellipse1 << ellipse2 << ellipse3 << ellipse4 << ellipse5;
    shapes << triangle1 << triangle2 << triangle3 << triangle4 << triangle5;
    shapes << rect1 << rect2 << rect3 << rect4 << rect5;
    shapes << pr1 << pr2 << pr3 << pr4 << pr5;
    shapes << prl1 << prl2 << prl3 << prl4 << prl5;

    qSort(shapes);

    qInfo() << "Shape size is:" << sizeof(Shape) << sizeof(QVariant) << sizeof(QSharedPointer<Shape>) << sizeof(Shape*);
    qInfo() << "QTypeInfo<Shape>::isLarge:" << (QTypeInfo<Shape>::isLarge);
    qInfo() << "QTypeInfo<QVariant>::isLarge:" << (QTypeInfo<QVariant>::isLarge);

    foreach (const Shape &shape, shapes) {
        if (shape.canCastTo<Ellipse>())
            qInfo() << "Shape can be converted to Ellipse";
        if (shape.canCastTo<Triangle>())
            qInfo() << "Shape can be converted to Triangle";
        if (shape.canCastTo<AbstractParallelogram>())
            qInfo() << "Shape can be converted to AbstractParallelogram";
        if (shape.canCastTo<Rectangle>())
            qInfo() << "Shape can be converted to Rectangle";
        if (shape.canCastTo<Parallelogram>())
            qInfo() << "Shape can be converted to Parallelogram";
        if (shape.canCastTo<AxonometricObject>())
            qInfo() << "Shape can be converted to AxonometricObject";
        if (shape.canCastTo<Parallelepiped>())
            qInfo() << "Shape can be converted to Parallelepiped";

        if (shape) {
            shape.printInfo();
            qInfo() << "Area of" << shape.metaTypeName() << "is:" << shape.area();
            if (shape.canCastTo<AxonometricObject>()) {
                const AxonometricObject &aobj = shape.castTo<Parallelepiped>();
                qInfo() << "Volume of" << shape.metaTypeName() << "is:" << aobj.volume();
                qInfo() << "Foo of" << shape.metaTypeName() << "is:" << aobj.foo();
            }
        }

        if (shape.is<Ellipse>()) {
            const Ellipse &ellipse = shape.castTo<Ellipse>();
            qInfo() << "Ellipse's area is:" << ellipse.area();
        } else if (shape.is<Triangle>()) {
            const Triangle &triangle = shape.castTo<Triangle>();
            qInfo() << "Triangle's area is:" << triangle.area();
        } else if (shape.is<Rectangle>()) {
            const Rectangle &rect = shape.castTo<Rectangle>();
            qInfo() << "Rectangle's area is:" << rect.area();
        } else if (shape.is<Parallelogram>()) {
            const Parallelogram &pr = shape.castTo<Parallelogram>();
            qInfo() << "Parallelogram's area is:" << pr.area();
        } else if (shape.is<Parallelepiped>()) {
            const Parallelepiped &prl = shape.castTo<Parallelepiped>();
            qInfo() << "Parallelepiped's area is:" << prl.area() << "volume:" << prl.volume() << "foo:" << prl.foo();
        } else if (!shape) {
            qInfo() << "Shape is null";
        }
    }

    qInfo("Test variant list");

    QVariantList vars;

    vars << ellipse1 << ellipse2 << ellipse3 << ellipse4 << ellipse5;
    vars << triangle1 << triangle2 << triangle3 << triangle4 << triangle5;
    vars << rect1 << rect2 << rect3 << rect4 << rect5;
    vars << pr1 << pr2 << pr3 << pr4 << pr5;
    vars << prl1 << prl2 << prl3 << prl4 << prl5;

    foreach (const QVariant &var, vars) {
        if (!var.canConvert<Shape>())
            continue;
        const Shape &shape = var.value<Shape>();
        if (shape.canCastTo<Ellipse>())
            qInfo() << "Shape can be converted to Ellipse";
        if (shape.canCastTo<Triangle>())
            qInfo() << "Shape can be converted to Triangle";
        if (shape.canCastTo<AbstractParallelogram>())
            qInfo() << "Shape can be converted to AbstractParallelogram";
        if (shape.canCastTo<Rectangle>())
            qInfo() << "Shape can be converted to Rectangle";
        if (shape.canCastTo<Parallelogram>())
            qInfo() << "Shape can be converted to Parallelogram";
        if (shape.canCastTo<AxonometricObject>())
            qInfo() << "Shape can be converted to AxonometricObject";
        if (shape.canCastTo<Parallelepiped>())
            qInfo() << "Shape can be converted to Parallelepiped";

        if (shape) {
            shape.printInfo();
            qInfo() << "Area of" << shape.metaTypeName() << "is:" << shape.area();
            if (shape.canCastTo<AxonometricObject>()) {
                const AxonometricObject &aobj = shape.castTo<Parallelepiped>(); // there is no way to cast like shape.castTo<AxonometricObject>()
                qInfo() << "Volume of" << shape.metaTypeName() << "is:" << aobj.volume();
                qInfo() << "Foo of" << shape.metaTypeName() << "is:" << aobj.foo();
            }
        }

        if (!shape)
            qInfo() << "Shape is null";

        if (shape.is<Ellipse>()) {
            Ellipse ellipse = shape.castTo<Ellipse>();
            qInfo() << "Ellipse's area is:" << ellipse.area();
        } else if (shape.is<Triangle>()) {
            Triangle triangle = shape.castTo<Triangle>();
            qInfo() << "Triangle's area is:" << triangle.area();
        } else if (shape.is<Rectangle>()) {
            Rectangle rect = shape.castTo<Rectangle>();
            qInfo() << "Rectangle's area is:" << rect.area();
        } else if (shape.is<Parallelogram>()) {
            Parallelogram pr = shape.castTo<Parallelogram>();
            qInfo() << "Parallelogram's area is:" << pr.area();
        } else if (shape.is<Parallelepiped>()) {
            Parallelepiped prl = shape.castTo<Parallelepiped>();
            qInfo() << "Parallelogram's area is:" << prl.area() << "volume:" << prl.volume() << "foo:" << prl.foo();
        }
    }
}
