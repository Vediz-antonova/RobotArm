#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>

#include "line.h"

class Rectangle : public QGraphicsItem
{
private:
    bool setStartCoordinates = false;

public:
    Rectangle();
    int x0, y0, x, y;
    Line line1, line2, line3, line4;

    void draw(QPainter *painter);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // RECTANGLE_H
