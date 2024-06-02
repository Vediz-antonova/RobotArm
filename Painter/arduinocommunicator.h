#ifndef ARDUINOCOMMUNICATOR_H
#define ARDUINOCOMMUNICATOR_H

#include <QSerialPort>
#include <QDebug>>

class ArduinoCommunicator {
public:
    ArduinoCommunicator(const QString &portName) {
        arduino = new QSerialPort();
        arduino->setPortName(portName);
        arduino->open(QIODevice::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }

    ~ArduinoCommunicator() {
        if (arduino->isOpen()) {
            arduino->close();
        }
        delete arduino;
    }

    void sendPen(int statusPen){
        QString setPen = "p " + QString::number(statusPen) + '\n';
        qDebug() << "setPen " << statusPen;
        arduino->write(setPen.toStdString().c_str());
    }

    void sendAngles(double alpha, double beta) {
        QString angles = "a " + QString::number(alpha) + "\n" + "b " + QString::number(beta) + "\n";
        arduino->write(angles.toStdString().c_str());
    }

private:
    QSerialPort *arduino;
};

#endif // ARDUINOCOMMUNICATOR_H
