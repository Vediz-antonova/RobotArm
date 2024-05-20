#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure{
public:
    Square(Figure *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void forPort(){}
};

#endif // SQUARE_H
