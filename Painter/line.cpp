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
    double segmentSize = 5 / 0.18;

    double lineLength = std::sqrt(std::pow(mouseX, 2) + std::pow(mouseY, 2));

    int segmentsCount = lineLength / segmentSize;

    std::vector<double> arrAlpha;
    std::vector<double> arrBeta;

    // double angle = mouseX != 0 ? atan(mouseY/mouseX) : 0;
    // double segmentX = segmentSize * cos(angle);
    // double segmentY = segmentSize * sin(angle);

    for (int i = -1; i < segmentsCount; ++i) {
        double segmentEndX =  centerX + (mouseX * (i + 1) / segmentsCount);
        double segmentEndY =  centerY + (mouseY * (i + 1) / segmentsCount);

        // double segmentEndX =  centerX + segmentX * i;
        // double segmentEndY =  centerY + segmentY * i;

        // Вычисляем полярный радиус
        double polarRadius = std::sqrt(std::pow(segmentEndX /*+ 100/0.18*/, 2) + std::pow(305 - segmentEndY, 2));
            //polarRadius = fmod(polarRadius, 54.6);

        // Вычисляем углы альфа и бета
        double alpha = std::acos(segmentEndX / polarRadius) * 180 / M_PI;
        double beta = std::acos((polarRadius - 55/0.18) / (160/0.18)) * 180 / M_PI;

        qDebug() << "Alpha: " << alpha;
        qDebug() << "Beta: " << beta;

        arrAlpha.push_back(alpha);
        arrBeta.push_back(beta);
    }

    setAlpha(arrAlpha);
    setBeta(arrBeta);
}
