#include "line.h"

Line::Line() {
    x0 = 0;
    y0 = 0;
    x = 0;
    y = 0;
}

void Line::draw(QPainter *painter){
    painter->drawLine(QPointF(x0, y0), QPointF(x, y));
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    draw(painter);
}

QRectF Line::boundingRect() const{
    return QRectF(0, 0, 750, 425);
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setStartCoordinates) {
        x0 = event->scenePos().x();
        y0 = event->scenePos().y();
        setStartCoordinates = true;
    }
    else {
        setTransformOriginPoint(event->pos());
    }
}

void Line::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    x = event->scenePos().x();
    y = event->scenePos().y();

    update();
}

std::vector<double> Line::getAlpha() {
    return allAlphaAngles;
}

std::vector<double> Line::getBeta() {
    return allBetaAngles;
}

void Line::mathForDrawLineWithRobotArm() {
    allAlphaAngles = std::vector<double>{};
    allBetaAngles = std::vector<double>{};

    double segmentSize = 1 * PPM;
    double lineLength = std::sqrt(std::pow(x - x0, 2) + std::pow(y - y0, 2));

    int segmentsCount = lineLength / segmentSize;
    qDebug() << "Segments " << segmentsCount;


    for (int i = -1; i < segmentsCount; ++i) {
        double segmentEndX =  translateXToMm(x0 + ((x - x0) * (i + 1) / segmentsCount));
        double segmentEndY =  translateYToMm(y0 + ((y - y0) * (i + 1) / segmentsCount));

        double polarRadius = std::sqrt(std::pow(segmentEndX, 2) + std::pow(segmentEndY, 2));

        double alpha = std::acos(segmentEndX / polarRadius) * 180 / M_PI;
        double beta = std::acos((polarRadius - 45) / 160) * 180 / M_PI;

        qDebug() << "R: " << polarRadius << "  Alpha: " << alpha;

        qDebug() << "EndX: " << segmentEndX << "    EndY: " << segmentEndY;
        qDebug() << "Alpha: " << alpha << "    Beta: " << beta << '\n';

        allAlphaAngles.push_back(alpha);
        allBetaAngles.push_back(beta);
    }
}

double Line::translateXToMm(double x) {
    return x / PPM - 75;
}

double Line::translateYToMm(double y) {
    return 175 - y / PPM;
}
