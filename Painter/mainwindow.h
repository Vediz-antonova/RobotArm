#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>

#include <figure.h>
#include <triangle.h>
#include <circle.h>
#include <line.h>
#include <square.h>
#include <rectangle.h>
#include <rhombus.h>

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

private slots:
    void on_TriangleButton_clicked();
    // void on_CircleButton_clicked();
    void on_LineButton_clicked();
    void on_ClearButton_clicked();
    void on_SquareButton_clicked();
    void on_RectangleButton_clicked();
    void on_RhombusButton_clicked();

    void updateCenterDisplay(QString newX, QString newY);
    void infoFigure(Figure* figure);

    void on_pushButton_clicked();

private:
    Figure* figure;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer* timer;
    QLabel *label;
};
#endif // MAINWINDOW_H
