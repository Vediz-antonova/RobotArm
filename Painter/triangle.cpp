#include "triangle.h"
#include <QPolygon>

Triangle::Triangle(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Triangle::draw(QPainter *painter){
    QPolygon polygon;
    polygon << QPoint(centerX, centerY - mouseY)
            << QPoint(centerX - mouseX / 2, centerY + mouseY / 2)
            << QPoint(centerX + mouseX / 2, centerY + mouseY / 2);
    painter->drawPolygon(polygon);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}
