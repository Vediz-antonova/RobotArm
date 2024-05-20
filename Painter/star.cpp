#include "star.h"

Star::Star(int n, Figure *parent) : Figure(parent){
    size = n;
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Star::draw(QPainter *painter){
    QPolygon polygon;
    int radios = qMax(mouseX, mouseY);
    for (int i = 0; i < size * 2; ++i) {
        double angle = 360 / (size * 2) * i;  // Угол в градусах
        double radian = qDegreesToRadians(angle);  // Угол в радианах
        int currentRadios = (i % 2 == 0) ? radios : radios / 2;
        int dx = currentRadios * cos(radian);
        int dy = currentRadios * sin(radian);
        polygon << QPoint(centerX + dx, centerY + dy);
    }
    painter->drawPolygon(polygon);
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}
