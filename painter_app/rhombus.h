#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>

#include "line.h"

class Rhombus : public QGraphicsItem
{
private:
    bool setStartCoordinates = false;

public:
    Rhombus();
    int x0, y0, x, y;
    Line line1, line2, line3, line4;

    void draw(QPainter *painter);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // RHOMBUS_H
