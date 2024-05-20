#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <triangle.h>
#include <circle.h>
#include <line.h>
#include <square.h>
#include <rectangle.h>
#include <rhombus.h>
#include <hexagon.h>
#include <star.h>

#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer(this);
    timer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCenterDisplay(QString newX, QString newY) {
    ui->CenterX->setText("CenterX: " + newX);
    ui->CenterY->setText("CenterY: " + newY);
}

void MainWindow::infoFigure(Figure* figure){
    static int oldX = figure->centerX;
    static int oldY = figure->centerY;
    connect(timer, &QTimer::timeout, [this, figure]{
        if (figure->centerX != oldX || figure->centerY != oldY) {
            MainWindow::updateCenterDisplay(QString::number(figure->centerX), QString::number(figure->centerY));
            oldX = figure->centerX;
            oldY = figure->centerY;
        }
    });
}

void MainWindow::on_StarButton_clicked(){
    Star *st = new Star(5);
    scene->addItem(st);
    infoFigure(st);
}

void MainWindow::on_TriangleButton_clicked(){
    Triangle *tr = new Triangle();
    scene->addItem(tr);
    infoFigure(tr);
}

void MainWindow::on_CircleButton_clicked(){
    Circle *cr = new Circle();
    scene->addItem(cr);
    infoFigure(cr);
}

void MainWindow::on_LineButton_clicked(){
    Line *ln = new Line();
    scene->addItem(ln);
    infoFigure(ln);

    figure->mouseX = ln->mouseX;
    figure->mouseY = ln->mouseY;
    figure->centerX = ln->centerX;
    figure->centerY = ln->centerY;
}

void MainWindow::on_ClearButton_clicked(){
    QMessageBox message;
    message.warning(this, "", "Замените лист бумаги");

    QGraphicsScene *scene1 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    scene = scene1;
}

void MainWindow::on_SquareButton_clicked(){
    Square *sq = new Square();
    scene->addItem(sq);
    infoFigure(sq);
}

void MainWindow::on_RectangleButton_clicked(){
    Rectangle *rec = new Rectangle();
    scene->addItem(rec);
    infoFigure(rec);
}

void MainWindow::on_RhombusButton_clicked(){
    Rhombus *rh = new Rhombus();
    scene->addItem(rh);
    infoFigure(rh);
}

void MainWindow::on_HexagonButton_clicked(){
    Hexagon *hg = new Hexagon();
    scene->addItem(hg);
    infoFigure(hg);
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "MouseX: " << figure->mouseX;
    qDebug() << "CenterX: " << figure->centerX;
    double length = qSqrt((figure->centerX - figure->mouseX) * (figure->centerX - figure->mouseX) + (figure->centerY - figure->mouseY) * (figure->centerY - figure->mouseY));
    double Oy = fabs(figure->centerY - figure->mouseY);
    double Ox = fabs(figure->centerX - figure->mouseX);
    double sinA = Oy / length;
    double cosA = Ox / length;
    int n = ceil(length / 2);

    double* x = new double[n + 1];
    double* y = new double[n + 1];
    double* polar = new double[n + 1];

    x[0] = figure->centerX;
    for (int i = 1; i < n; i++) {
        x[i] = x[i - 1] + 2 * cosA;
    }
    x[n] = figure->mouseX;
    y[0] = figure->centerY;
    for (int i = 1; i < n; i++) {
        y[i] = y[i - 1] + 2 * sinA;
    }
    y[n] = figure->mouseY;

    for(int i = 0; i < n + 1; i++){
        polar[i] = qSqrt(x[i] * x[i] + y[i] * y[i]);
    }

    double* alpha = new double[n + 1];
    double* beta = new double[n + 1];

    for(int i = 0; i < n + 1; i++){
        alpha[i] = acos(x[i] / polar[i]);
        beta[i] = acos((polar[i] - 55) / 160);
    }

    for(int i = 0; i < n + 1; i++){
        qDebug() << "Alpha: " << alpha[i] * 180 / 3.1415923565798932;
        qDebug() << "Beta: " << beta[i] * 180 / 3.1415923565798932 << "\n";
    }


}

