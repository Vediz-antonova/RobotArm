#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>

class Line: public QGraphicsItem
{
private:
    bool setStartCoordinates = false;

    std::vector<double> allAlphaAngles;
    std::vector<double> allBetaAngles;

public:
    Line();
    int x0, y0, x, y;

    void draw(QPainter *painter);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    std::vector<double> getAlpha();
    std::vector<double> getBeta();

    void mathForDrawLineWithRobotArm();
};

#endif // LINE_H
