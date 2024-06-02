#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>

#include "line.h"
#include "arduino_communicator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateCenterDisplay(Line* line);
    void infoCoordinate(Line* line);

private slots:
    void on_LineButton_clicked();

    void on_DrawRobotButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer* timer;

    Line* line;
    Arduino_Communicator* arduino = new Arduino_Communicator("COM8");
};
#endif // MAINWINDOW_H
