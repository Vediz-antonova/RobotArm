#include "triangle.h"

Triangle::Triangle() {
    x0 = 0;
    y0 = 0;
    x = 0;
    y = 0;
}

void Triangle::draw(QPainter *painter) {
    line1.x0 = x0; line1.y0 = y0; line1.x = x; line1.y = y0;
    line2.x0 = x; line2.y0 = y0; line2.x = x0; line2.y = y;
    line3.x0 = x0; line3.y0 = y; line3.x = x0; line3.y = y0;

    line1.update();
    line2.update();
    line3.update();

    line1.draw(painter);
    line2.draw(painter);
    line3.draw(painter);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

QRectF Triangle::boundingRect() const {
    return QRectF(0, 0, 750, 425);
}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setStartCoordinates) {
        x0 = event->scenePos().x();
        y0 = event->scenePos().y();
        setStartCoordinates = true;
    }
    else {
        setTransformOriginPoint(event->pos());
    }
}

void Triangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    x = event->scenePos().x();
    y = event->scenePos().y();

    update();
}
