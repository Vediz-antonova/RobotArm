#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DELAY 100

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

void MainWindow::updateCenterDisplay(Line* line) {
    ui->label_x->setText("x: " + QString::number(line->x));
    ui->label_y->setText("y: " + QString::number(line->y));

    ui->label_x0->setText("x0: " + QString::number(line->x0));
    ui->label_y0->setText("y0: " + QString::number(line->y0));
}

void MainWindow::infoCoordinate(Line* line){
    static int oldX = line->x;
    static int oldY = line->y;
    connect(timer, &QTimer::timeout, [this, line]{
        if (line->x != oldX || line->y != oldY) {
            MainWindow::updateCenterDisplay(line);
        }
    });
}

void MainWindow::on_LineButton_clicked()
{
    line = new Line();
    scene->addItem(line);

    infoCoordinate(line);
    rectangle = nullptr;
    square = nullptr;
    rhombus = nullptr;
    triangle = nullptr;
}

void MainWindow::on_RectangleButton_clicked()
{
    rectangle = new Rectangle();
    scene->addItem(rectangle);

    line = nullptr;
    square = nullptr;
    rhombus = nullptr;
    triangle = nullptr;
}

void MainWindow::on_SquareButton_clicked()
{
    square = new Square();
    scene->addItem(square);

    line = nullptr;
    rectangle = nullptr;
    rhombus = nullptr;
    triangle = nullptr;
}

void MainWindow::on_RhombusButton_clicked()
{
    rhombus = new Rhombus();
    scene->addItem(rhombus);

    line = nullptr;
    rectangle = nullptr;
    square = nullptr;
    triangle = nullptr;
}

void MainWindow::on_TriangleButton_clicked()
{
    triangle = new Triangle();
    scene->addItem(triangle);

    line = nullptr;
    rectangle = nullptr;
    square = nullptr;
    rhombus = nullptr;
}

void MainWindow::on_DrawRobotButton_clicked()
{
    arduino->sendPen(0);

    if (line != nullptr) {
        drawLine(line);
    } else if (rectangle != nullptr) {
        drawLine(&rectangle->line1);
        drawLine(&rectangle->line2);
        drawLine(&rectangle->line3);
        drawLine(&rectangle->line4);
    } else if (square != nullptr) {
        drawLine(&square->line1);
        drawLine(&square->line2);
        drawLine(&square->line3);
        drawLine(&square->line4);
    } else if (rhombus != nullptr) {
        drawLine(&rhombus->line1);
        drawLine(&rhombus->line2);
        drawLine(&rhombus->line3);
        drawLine(&rhombus->line4);
    } else if (triangle != nullptr) {
        drawLine(&triangle->line1);
        drawLine(&triangle->line2);
        drawLine(&triangle->line3);
    }

    arduino->sendPen(0);
    arduino->sendDelay(DELAY);
}

void MainWindow::drawLine(Line* line) {
    line->mathForDrawLineWithRobotArm();

    std::vector<double> arrAlpha = line->getAlpha();
    std::vector<double> arrBeta = line->getBeta();

    arduino->sendAngles(arrAlpha[0], arrBeta[0]);
    arduino->sendDelay(DELAY);
    arduino->sendPen(1);
    arduino->sendDelay(DELAY);

    for(int i = 1; i < arrAlpha.size(); i++){
        arduino->sendAngles(arrAlpha[i], arrBeta[i]);
        arduino->sendDelay(DELAY);
    }
}

void MainWindow::on_ClearButton_clicked()
{
    QMessageBox message;
    message.warning(this, "", "Замените лист бумаги");

    QGraphicsScene *scene1 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    scene = scene1;
}

