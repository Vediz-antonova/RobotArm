#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>

#include "line.h"

class Square : public QGraphicsItem
{
private:
    bool setStartCoordinates = false;

public:
    Square();
    int x0, y0, x, y;
    Line line1, line2, line3, line4;

    void draw(QPainter *painter);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SQUARE_H
