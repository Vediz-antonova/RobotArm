#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QMessageBox>

#include "line.h"
#include "rectangle.h"
#include "square.h"
#include "rhombus.h"
#include "triangle.h"
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

    void drawLine(Line* line);

private slots:
    void on_LineButton_clicked();
    void on_RectangleButton_clicked();
    void on_SquareButton_clicked();
    void on_RhombusButton_clicked();
    void on_TriangleButton_clicked();

    void on_DrawRobotButton_clicked();

    void on_ClearButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer* timer;

    Line* line = nullptr;
    Rectangle* rectangle = nullptr;
    Square* square = nullptr;
    Rhombus* rhombus = nullptr;
    Triangle* triangle = nullptr;
    Arduino_Communicator* arduino = new Arduino_Communicator("COM9");
};
#endif // MAINWINDOW_H
