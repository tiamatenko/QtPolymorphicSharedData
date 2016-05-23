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
    void castTest();
    void checkAndCastTest();
    void variantTest();
    void cleanupTestCase();

private:
    QList<Shape> shapes;
};

void tst_QtPolymorphicImplicitSharedType::initTestCase()
{
    shapes << Ellipse(10.0, 10.0, 10.0, 100.0, 100.0)
           << Triangle(20.0, 20.0, 20.0, 200.0, 200.0, 2.0)
           << Rectangle(30.0, 30.0, 30.0, 300.0, 300.0)
           << Parallelogram(40.0, 40.0, 40.0, 400.0, 400.0, 0.5)
           << Parallelepiped(50.0, 50.0, 50.0, 500.0, 500.0, 500.0);
}

void tst_QtPolymorphicImplicitSharedType::castTest()
{
    for (int i = 0; i < shapes.size(); ++i) {
        Shape shape = shapes.at(i);

        QVERIFY(shape.isValid());
        QVERIFY(!shape.isNull());
        QVERIFY(shape == true);
        QVERIFY(!shape == false);

        switch (i) {
        case 0: { // Ellipse
            QVERIFY(shape.is<Ellipse>());
            QVERIFY(shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Ellipse ellipse = shape.castTo<Ellipse>();
            QVERIFY(ellipse.isValid());
            QVERIFY(!ellipse.isNull());
            QVERIFY(ellipse);
            QVERIFY(!ellipse == false);

            ellipse = Ellipse();
            QVERIFY(!ellipse.isValid());
            QVERIFY(ellipse.isNull());
            QVERIFY(bool(ellipse) == false);
            QVERIFY(!ellipse);
            break;
        }
        case 1: { // Triangle
            QVERIFY(shape.is<Triangle>());
            QVERIFY(shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Triangle triangle = shape.castTo<Triangle>();
            QVERIFY(triangle.isValid());
            QVERIFY(!triangle.isNull());
            QVERIFY(triangle);
            QVERIFY(!triangle == false);

            triangle = Triangle();
            QVERIFY(!triangle.isValid());
            QVERIFY(triangle.isNull());
            QVERIFY(bool(triangle) == false);
            QVERIFY(!triangle);
            break;
        }
        case 2: { // Rectangle
            QVERIFY(shape.is<Rectangle>());
            QVERIFY(shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Rectangle rectangle = shape.castTo<Rectangle>();
            QVERIFY(rectangle.isValid());
            QVERIFY(!rectangle.isNull());
            QVERIFY(rectangle);
            QVERIFY(!rectangle == false);

            rectangle = Rectangle();
            QVERIFY(!rectangle.isValid());
            QVERIFY(rectangle.isNull());
            QVERIFY(bool(rectangle) == false);
            QVERIFY(!rectangle);
            break;
        }
        case 3: { // Parallelogram
            QVERIFY(shape.is<Parallelogram>());
            QVERIFY(shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Parallelogram parallelogram = shape.castTo<Parallelogram>();
            QVERIFY(parallelogram.isValid());
            QVERIFY(!parallelogram.isNull());
            QVERIFY(parallelogram);
            QVERIFY(!parallelogram == false);

            parallelogram = Parallelogram();
            QVERIFY(!parallelogram.isValid());
            QVERIFY(parallelogram.isNull());
            QVERIFY(bool(parallelogram) == false);
            QVERIFY(!parallelogram);
            break;
        }
        case 4: { // Parallelepiped
            QVERIFY(shape.is<Parallelepiped>());
            QVERIFY(shape.canCastTo<Parallelepiped>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());

            Parallelepiped parallelepiped = shape.castTo<Parallelepiped>();
            QVERIFY(parallelepiped.isValid());
            QVERIFY(!parallelepiped.isNull());
            QVERIFY(parallelepiped);
            QVERIFY(!parallelepiped == false);

            parallelepiped = Parallelepiped();
            QVERIFY(!parallelepiped.isValid());
            QVERIFY(parallelepiped.isNull());
            QVERIFY(bool(parallelepiped) == false);
            QVERIFY(!parallelepiped);
            break;
        }
        default:
            break;
        }

        shape = Shape();
        QVERIFY(!shape.isValid());
        QVERIFY(shape.isNull());
        QVERIFY(!shape.canCastTo<Ellipse>());
        QVERIFY(!shape.canCastTo<Triangle>());
        QVERIFY(!shape.canCastTo<Rectangle>());
        QVERIFY(!shape.canCastTo<Parallelogram>());
        QVERIFY(!shape.canCastTo<Parallelepiped>());
        QVERIFY(bool(shape) == false);
        QVERIFY(!shape);
    }
}

void tst_QtPolymorphicImplicitSharedType::checkAndCastTest()
{
    for (int i = 0; i < shapes.size(); ++i) {
        const Shape &shape = shapes.at(i);
        switch (i) {
        case 0: { // Ellipse
            Ellipse ellipse = shape.checkAndCastTo<Ellipse>();
            QVERIFY(ellipse.isValid());
            QVERIFY(!ellipse.isNull());
            QVERIFY(ellipse);
            QVERIFY(!ellipse == false);

            Triangle triangle = shape.checkAndCastTo<Triangle>();
            QVERIFY(!triangle.isValid());
            QVERIFY(triangle.isNull());
            QVERIFY(bool(triangle) == false);
            QVERIFY(!triangle);

            Rectangle rectangle = shape.checkAndCastTo<Rectangle>();
            QVERIFY(!rectangle.isValid());
            QVERIFY(rectangle.isNull());
            QVERIFY(bool(rectangle) == false);
            QVERIFY(!rectangle);

            Parallelogram parallelogram = shape.checkAndCastTo<Parallelogram>();
            QVERIFY(!parallelogram.isValid());
            QVERIFY(parallelogram.isNull());
            QVERIFY(bool(parallelogram) == false);
            QVERIFY(!parallelogram);

            Parallelepiped parallelepiped = shape.checkAndCastTo<Parallelepiped>();
            QVERIFY(!parallelepiped.isValid());
            QVERIFY(parallelepiped.isNull());
            QVERIFY(bool(parallelepiped) == false);
            QVERIFY(!parallelepiped);
            break;
        }
        case 1: { // Triangle
            Triangle triangle = shape.checkAndCastTo<Triangle>();
            QVERIFY(triangle.isValid());
            QVERIFY(!triangle.isNull());
            QVERIFY(triangle);
            QVERIFY(!triangle == false);

            Ellipse ellipse = shape.checkAndCastTo<Ellipse>();
            QVERIFY(!ellipse.isValid());
            QVERIFY(ellipse.isNull());
            QVERIFY(bool(ellipse) == false);
            QVERIFY(!ellipse);

            Rectangle rectangle = shape.checkAndCastTo<Rectangle>();
            QVERIFY(!rectangle.isValid());
            QVERIFY(rectangle.isNull());
            QVERIFY(bool(rectangle) == false);
            QVERIFY(!rectangle);

            Parallelogram parallelogram = shape.checkAndCastTo<Parallelogram>();
            QVERIFY(!parallelogram.isValid());
            QVERIFY(parallelogram.isNull());
            QVERIFY(bool(parallelogram) == false);
            QVERIFY(!parallelogram);

            Parallelepiped parallelepiped = shape.checkAndCastTo<Parallelepiped>();
            QVERIFY(!parallelepiped.isValid());
            QVERIFY(parallelepiped.isNull());
            QVERIFY(bool(parallelepiped) == false);
            QVERIFY(!parallelepiped);
            break;
        }
        case 2: { // Rectangle
            Rectangle rectangle = shape.checkAndCastTo<Rectangle>();
            QVERIFY(rectangle.isValid());
            QVERIFY(!rectangle.isNull());
            QVERIFY(rectangle);
            QVERIFY(!rectangle == false);

            Ellipse ellipse = shape.checkAndCastTo<Ellipse>();
            QVERIFY(!ellipse.isValid());
            QVERIFY(ellipse.isNull());
            QVERIFY(bool(ellipse) == false);
            QVERIFY(!ellipse);

            Triangle triangle = shape.checkAndCastTo<Triangle>();
            QVERIFY(!triangle.isValid());
            QVERIFY(triangle.isNull());
            QVERIFY(bool(triangle) == false);
            QVERIFY(!triangle);

            Parallelogram parallelogram = shape.checkAndCastTo<Parallelogram>();
            QVERIFY(!parallelogram.isValid());
            QVERIFY(parallelogram.isNull());
            QVERIFY(bool(parallelogram) == false);
            QVERIFY(!parallelogram);

            Parallelepiped parallelepiped = shape.checkAndCastTo<Parallelepiped>();
            QVERIFY(!parallelepiped.isValid());
            QVERIFY(parallelepiped.isNull());
            QVERIFY(bool(parallelepiped) == false);
            QVERIFY(!parallelepiped);
            break;
        }
        case 3: { // Parallelogram
            Parallelogram parallelogram = shape.checkAndCastTo<Parallelogram>();
            QVERIFY(parallelogram.isValid());
            QVERIFY(!parallelogram.isNull());
            QVERIFY(parallelogram);
            QVERIFY(!parallelogram == false);

            Ellipse ellipse = shape.checkAndCastTo<Ellipse>();
            QVERIFY(!ellipse.isValid());
            QVERIFY(ellipse.isNull());
            QVERIFY(bool(ellipse) == false);
            QVERIFY(!ellipse);

            Triangle triangle = shape.checkAndCastTo<Triangle>();
            QVERIFY(!triangle.isValid());
            QVERIFY(triangle.isNull());
            QVERIFY(bool(triangle) == false);
            QVERIFY(!triangle);

            Rectangle rectangle = shape.checkAndCastTo<Rectangle>();
            QVERIFY(!rectangle.isValid());
            QVERIFY(rectangle.isNull());
            QVERIFY(bool(rectangle) == false);
            QVERIFY(!rectangle);

            Parallelepiped parallelepiped = shape.checkAndCastTo<Parallelepiped>();
            QVERIFY(!parallelepiped.isValid());
            QVERIFY(parallelepiped.isNull());
            QVERIFY(bool(parallelepiped) == false);
            QVERIFY(!parallelepiped);
            break;
        }
        case 4: { // Parallelepiped
            Parallelepiped parallelepiped = shape.checkAndCastTo<Parallelepiped>();
            QVERIFY(parallelepiped.isValid());
            QVERIFY(!parallelepiped.isNull());
            QVERIFY(parallelepiped);
            QVERIFY(!parallelepiped == false);

            Ellipse ellipse = shape.checkAndCastTo<Ellipse>();
            QVERIFY(!ellipse.isValid());
            QVERIFY(ellipse.isNull());
            QVERIFY(bool(ellipse) == false);
            QVERIFY(!ellipse);

            Triangle triangle = shape.checkAndCastTo<Triangle>();
            QVERIFY(!triangle.isValid());
            QVERIFY(triangle.isNull());
            QVERIFY(bool(triangle) == false);
            QVERIFY(!triangle);

            Rectangle rectangle = shape.checkAndCastTo<Rectangle>();
            QVERIFY(rectangle.isValid());
            QVERIFY(!rectangle.isNull());
            QVERIFY(rectangle);
            QVERIFY(!rectangle == false);

            Parallelogram parallelogram = shape.checkAndCastTo<Parallelogram>();
            QVERIFY(!parallelogram.isValid());
            QVERIFY(parallelogram.isNull());
            QVERIFY(bool(parallelogram) == false);
            QVERIFY(!parallelogram);
            break;
        }
        default:
            break;
        }
    }
}

void tst_QtPolymorphicImplicitSharedType::variantTest()
{
    for (int i = 0; i < shapes.size(); ++i) {
        Shape shape = shapes.at(i);

        QVariant var = QVariant::fromValue(shape);
        QVERIFY(var.canConvert<Shape>());
        QVERIFY(!var.canConvert<Ellipse>());
        QVERIFY(!var.canConvert<Triangle>());
        QVERIFY(!var.canConvert<Rectangle>());
        QVERIFY(!var.canConvert<Parallelogram>());
        QVERIFY(!var.canConvert<Parallelepiped>());

        shape = var.value<Shape>();
        QVERIFY(shape.isValid());
        QVERIFY(!shape.isNull());
        QVERIFY(shape == true);
        QVERIFY(!shape == false);

        switch (i) {
        case 0: { // Ellipse
            QVERIFY(shape.is<Ellipse>());
            QVERIFY(shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Ellipse ellipse = shape.castTo<Ellipse>();
            var = QVariant::fromValue(ellipse);
            QVERIFY(var.canConvert<Ellipse>());
            QVERIFY(!var.canConvert<Shape>());
            QVERIFY(!var.canConvert<Triangle>());
            QVERIFY(!var.canConvert<Rectangle>());
            QVERIFY(!var.canConvert<Parallelogram>());
            QVERIFY(!var.canConvert<Parallelepiped>());

            ellipse = var.value<Ellipse>();
            QVERIFY(ellipse.isValid());
            QVERIFY(!ellipse.isNull());
            QVERIFY(ellipse == true);
            QVERIFY(!ellipse == false);
            QVERIFY(ellipse.is<Ellipse>());
            QVERIFY(ellipse.canCastTo<Ellipse>());
            QVERIFY(!ellipse.canCastTo<Triangle>());
            QVERIFY(!ellipse.canCastTo<Rectangle>());
            QVERIFY(!ellipse.canCastTo<Parallelogram>());
            QVERIFY(!ellipse.canCastTo<Parallelepiped>());
            break;
        }
        case 1: { // Triangle
            QVERIFY(shape.is<Triangle>());
            QVERIFY(shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Triangle triangle = shape.castTo<Triangle>();
            var = QVariant::fromValue(triangle);
            QVERIFY(var.canConvert<Triangle>());
            QVERIFY(!var.canConvert<Shape>());
            QVERIFY(!var.canConvert<Ellipse>());
            QVERIFY(!var.canConvert<Rectangle>());
            QVERIFY(!var.canConvert<Parallelogram>());
            QVERIFY(!var.canConvert<Parallelepiped>());

            triangle = var.value<Triangle>();
            QVERIFY(triangle.isValid());
            QVERIFY(!triangle.isNull());
            QVERIFY(triangle == true);
            QVERIFY(!triangle == false);
            QVERIFY(triangle.is<Triangle>());
            QVERIFY(triangle.canCastTo<Triangle>());
            QVERIFY(!triangle.canCastTo<Ellipse>());
            QVERIFY(!triangle.canCastTo<Rectangle>());
            QVERIFY(!triangle.canCastTo<Parallelogram>());
            QVERIFY(!triangle.canCastTo<Parallelepiped>());
            break;
        }
        case 2: { // Rectangle
            QVERIFY(shape.is<Rectangle>());
            QVERIFY(shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Rectangle rectangle = shape.castTo<Rectangle>();
            var = QVariant::fromValue(rectangle);
            QVERIFY(var.canConvert<Rectangle>());
            QVERIFY(!var.canConvert<Shape>());
            QVERIFY(!var.canConvert<Ellipse>());
            QVERIFY(!var.canConvert<Triangle>());
            QVERIFY(!var.canConvert<Parallelogram>());
            QVERIFY(!var.canConvert<Parallelepiped>());

            rectangle = var.value<Rectangle>();
            QVERIFY(rectangle.isValid());
            QVERIFY(!rectangle.isNull());
            QVERIFY(rectangle == true);
            QVERIFY(!rectangle == false);
            QVERIFY(rectangle.is<Rectangle>());
            QVERIFY(rectangle.canCastTo<Rectangle>());
            QVERIFY(!rectangle.canCastTo<Ellipse>());
            QVERIFY(!rectangle.canCastTo<Triangle>());
            QVERIFY(!rectangle.canCastTo<Parallelogram>());
            QVERIFY(!rectangle.canCastTo<Parallelepiped>());
            break;
        }
        case 3: { // Parallelogram
            QVERIFY(shape.is<Parallelogram>());
            QVERIFY(shape.canCastTo<Parallelogram>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Parallelepiped>());

            Parallelogram parallelogram = shape.castTo<Parallelogram>();
            var = QVariant::fromValue(parallelogram);
            QVERIFY(var.canConvert<Parallelogram>());
            QVERIFY(!var.canConvert<Shape>());
            QVERIFY(!var.canConvert<Ellipse>());
            QVERIFY(!var.canConvert<Triangle>());
            QVERIFY(!var.canConvert<Rectangle>());
            QVERIFY(!var.canConvert<Parallelepiped>());

            parallelogram = var.value<Parallelogram>();
            QVERIFY(parallelogram.isValid());
            QVERIFY(!parallelogram.isNull());
            QVERIFY(parallelogram == true);
            QVERIFY(!parallelogram == false);
            QVERIFY(parallelogram.is<Parallelogram>());
            QVERIFY(parallelogram.canCastTo<Parallelogram>());
            QVERIFY(!parallelogram.canCastTo<Ellipse>());
            QVERIFY(!parallelogram.canCastTo<Triangle>());
            QVERIFY(!parallelogram.canCastTo<Rectangle>());
            QVERIFY(!parallelogram.canCastTo<Parallelepiped>());
            break;
        }
        case 4: { // Parallelepiped
            QVERIFY(shape.is<Parallelepiped>());
            QVERIFY(shape.canCastTo<Parallelepiped>());
            QVERIFY(shape.canCastTo<Rectangle>());
            QVERIFY(!shape.canCastTo<Ellipse>());
            QVERIFY(!shape.canCastTo<Triangle>());
            QVERIFY(!shape.canCastTo<Parallelogram>());

            Parallelepiped parallelepiped = shape.castTo<Parallelepiped>();
            var = QVariant::fromValue(parallelepiped);
            QVERIFY(var.canConvert<Parallelepiped>());
            QVERIFY(!var.canConvert<Shape>());
            QVERIFY(!var.canConvert<Ellipse>());
            QVERIFY(!var.canConvert<Triangle>());
            QVERIFY(!var.canConvert<Rectangle>());
            QVERIFY(!var.canConvert<Parallelogram>());

            parallelepiped = var.value<Parallelepiped>();
            QVERIFY(parallelepiped.isValid());
            QVERIFY(!parallelepiped.isNull());
            QVERIFY(parallelepiped == true);
            QVERIFY(!parallelepiped == false);
            QVERIFY(parallelepiped.is<Parallelepiped>());
            QVERIFY(parallelepiped.canCastTo<Parallelepiped>());
            QVERIFY(parallelepiped.canCastTo<Rectangle>());
            QVERIFY(!parallelepiped.canCastTo<Ellipse>());
            QVERIFY(!parallelepiped.canCastTo<Triangle>());
            QVERIFY(!parallelepiped.canCastTo<Parallelogram>());
            break;
        }
        default:
            break;
        }
    }
}

void tst_QtPolymorphicImplicitSharedType::cleanupTestCase()
{
    shapes.clear();
}

QTEST_MAIN(tst_QtPolymorphicImplicitSharedType)
#include "tst_QtPolymorphicImplicitSharedType.moc"
