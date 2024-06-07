#ifndef ARDUINO_COMMUNICATOR_H
#define ARDUINO_COMMUNICATOR_H

#include <QSerialPort>
#include <QDebug>>
#include <QThread>

class Arduino_Communicator
{
public:
    Arduino_Communicator(const QString &portName);
    ~Arduino_Communicator();

    void sendPen(int statusPen);
    void sendDelay(int delayNumber);
    void sendAngles(double alpha, double beta);

private:
    QSerialPort *arduino;
};

#endif // ARDUINO_COMMUNICATOR_H
