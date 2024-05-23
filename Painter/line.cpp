#include "line.h"

Line::Line(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Line::draw(QPainter *painter){
    painter->drawLine(QPointF(centerX, centerY), QPointF(mouseX+centerX, mouseY+centerY));
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Line::forPort() {
    int segmentSize = 3 * 0.26;

    double lineLength = std::sqrt(std::pow(mouseX - centerX, 2) + std::pow(mouseY - centerY, 2));

    int segmentsCount = lineLength / segmentSize;

    for (int i = 0; i < segmentsCount; ++i) {
        double segmentEndX = centerX + (mouseX - centerX) * (i + 1) / segmentsCount;
        double segmentEndY = centerY + (mouseY - centerY) * (i + 1) / segmentsCount;

        // Вычисляем полярный радиус
        double polarRadius = std::sqrt(std::pow(segmentEndX, 2) + std::pow(segmentEndY, 2));

        // Вычисляем углы альфа и бета
        double alpha = std::acos(segmentEndX / polarRadius) * 180 / M_PI; // переводим радианы в градусы
        double beta = std::acos((polarRadius - 55) / 160) * 180 / M_PI; // переводим радианы в градусы

        qDebug() << "Alpha: " << alpha;
        qDebug() << "Beta: " << beta;
    }
}
