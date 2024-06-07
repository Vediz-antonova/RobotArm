#include "arduino_communicator.h"

Arduino_Communicator::Arduino_Communicator(const QString &portName) {
    arduino = new QSerialPort();
    arduino->setPortName(portName);
    arduino->open(QIODevice::WriteOnly);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
}

Arduino_Communicator::~Arduino_Communicator() {
    if (arduino->isOpen()) {
        arduino->close();
    }

    delete arduino;
}

void Arduino_Communicator::sendPen(int statusPen){
    QString setPen = "p " + QString::number(statusPen) + '\n';
    qDebug() << "setPen " << statusPen;
    arduino->write(setPen.toStdString().c_str());
    arduino->waitForBytesWritten(-1);
}

void Arduino_Communicator::sendDelay(int delayNumber){
/*    QString setPen = "d " + QString::number(delayNumber) + '\n';
    qDebug() << "d " << delayNumber;
    arduino->write(setPen.toStdString().c_str());
    arduino->waitForBytesWritten(-1);*/
    QThread::msleep(delayNumber);
}

void Arduino_Communicator::sendAngles(double alpha, double beta) {
    QString angles = "a " + QString::number(alpha) + "\n" + "b " + QString::number(beta) + "\n";
    qDebug() << angles;
    arduino->write(angles.toStdString().c_str());
    arduino->waitForBytesWritten(-1);
}
