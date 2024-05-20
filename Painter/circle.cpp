#include "circle.h"

Circle::Circle(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Circle::draw(QPainter *painter){
    int r = qMax(mouseX, mouseY);
    painter->drawEllipse(QPointF(centerX, centerY), r, r);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}
