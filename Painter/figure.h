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

    std::vector<double> alpha;
    std::vector<double> beta;

public:
    int centerX, centerY;
    int mouseX, mouseY;

    void setAlpha(std::vector<double> value) { alpha = value; }
    std::vector<double> getAlpha() { return alpha; }

    void setBeta(std::vector<double> value) { beta = value; }
    std::vector<double> getBeta() { return beta; }

    Figure(QGraphicsItem *parent = nullptr);

    virtual void draw(QPainter *painter) = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        draw(painter);
        // forPort();
    }
    QRectF boundingRect() const{\
        return QRectF(0, 0, 1111, 305);
    }
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    virtual void forPort() = 0;
};
#endif // FIGURE_H
