#include "figure.h"
#include <iostream>
#include <QPainter>
#include <QPolygon>

Figure::Figure(QGraphicsItem *parent2) : QGraphicsItem(parent2) {
    setCenter = false;
    setFlag(QGraphicsItem::ItemIsFocusable, true);
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setCenter) {
        centerX = event->scenePos().x();
        centerY = event->scenePos().y();
        setCenter = true;
    }
    else {
        setTransformOriginPoint(event->pos());
    }
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    mouseX = event->scenePos().x() - centerX;
    mouseY = event->scenePos().y() - centerY;

    update();
}
