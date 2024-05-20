#ifndef FIGURE_H
#define FIGURE_H

#pragma once
#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>

class Figure : public QGraphicsItem{
private:
    bool setCenter = false;

public:
    int centerX, centerY;
    int mouseX, mouseY;

    Figure(QGraphicsItem *parent = nullptr);

    virtual void draw(QPainter *painter) = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        draw(painter);
        forPort();
    }
    QRectF boundingRect() const{
        // Возвращает ограничивающий прямоугольник
        return QRectF(-100, -100, 1000*625, 1000*450); /// Посмотреть
    }
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    virtual void forPort() = 0;
};
#endif // FIGURE_H
