#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

void MainWindow::on_DrawRobotButton_clicked()
{
    arduino->sendPen(0);
    line->mathForDrawLineWithRobotArm();

    std::vector<double> arrAlpha = line->getAlpha();
    std::vector<double> arrBeta = line->getBeta();

    arduino->sendAngles(arrAlpha[0], arrBeta[0]);
    arduino->sendDelay(10);
    arduino->sendPen(1);

    for(int i = 1; i < arrAlpha.size(); i++){
        arduino->sendAngles(arrAlpha[i], arrBeta[i]);
        arduino->sendDelay(10);
    }

    arduino->sendPen(0);
}
