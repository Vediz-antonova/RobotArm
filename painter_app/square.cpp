#include "square.h"

Square::Square() {
    x0 = 0;
    y0 = 0;
    x = 0;
    y = 0;
}

void Square::draw(QPainter *painter) {
    line1.x0 = x0; line1.y0 = y0; line1.x =x; line1.y = y0;
    line2.x0 = x; line2.y0 = y0; line2.x =x; line2.y = y;
    line3.x0 = x; line3.y0 = y; line3.x =x0; line3.y = y;
    line4.x0 = x0; line4.y0 = y; line4.x =x0; line4.y = y0;

    line1.update();
    line2.update();
    line3.update();
    line4.update();

    line1.draw(painter);
    line2.draw(painter);
    line3.draw(painter);
    line4.draw(painter);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

QRectF Square::boundingRect() const {
    return QRectF(0, 0, 750, 425);
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setStartCoordinates) {
        x0 = event->scenePos().x();
        y0 = event->scenePos().y();
        setStartCoordinates = true;
    }
    else {
        setTransformOriginPoint(event->pos());
    }
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    int sideLength = std::max(std::abs(x0 - event->scenePos().x()), std::abs(y0 - event->scenePos().y()));
    x = x0 + sideLength;
    y = y0 + sideLength;

    if(event->scenePos().x() < x0) {
        x = x0 - sideLength;
    }
    if(event->scenePos().y() < y0) {
        y = y0 - sideLength;
    }

    update();
}

