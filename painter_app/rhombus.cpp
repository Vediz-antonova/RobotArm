#include "rhombus.h"

Rhombus::Rhombus() {
    x0 = 0;
    y0 = 0;
    x = 0;
    y = 0;
}

void Rhombus::draw(QPainter *painter) {
    int sideLength = std::max(std::abs(x0 - x), std::abs(y0 - y));
    int halfSide = sideLength / 2;

    line1.x0 = x0; line1.y0 = y0 + halfSide; line1.x = x0 + halfSide; line1.y = y0;
    line2.x0 = x0 + halfSide; line2.y0 = y0; line2.x = x0 + sideLength; line2.y = y0 + halfSide;
    line3.x0 = x0 + sideLength; line3.y0 = y0 + halfSide; line3.x = x0 + halfSide; line3.y = y0 + sideLength;
    line4.x0 = x0 + halfSide; line4.y0 = y0 + sideLength; line4.x = x0; line4.y = y0 + halfSide;

    line1.update();
    line2.update();
    line3.update();
    line4.update();

    line1.draw(painter);
    line2.draw(painter);
    line3.draw(painter);
    line4.draw(painter);
}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

QRectF Rhombus::boundingRect() const {
    return QRectF(0, 0, 750, 425);
}

void Rhombus::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setStartCoordinates) {
        x0 = event->scenePos().x();
        y0 = event->scenePos().y();
        setStartCoordinates = true;
    }
    else {
        setTransformOriginPoint(event->pos());
    }
}

void Rhombus::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    x = event->scenePos().x();
    y = event->scenePos().y();

    update();
}
