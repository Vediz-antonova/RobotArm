#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_TriangleButton_clicked(){
    Triangle *tr = new Triangle();
    scene->addItem(tr);
    infoFigure(tr);
}

// void MainWindow::on_CircleButton_clicked(){
//     Circle *cr = new Circle();
//     scene->addItem(cr);
//     infoFigure(cr);
// }

void MainWindow::on_LineButton_clicked(){
    Line *ln = new Line();
    scene->addItem(ln);
    infoFigure(ln);

    figure = dynamic_cast<Figure*>(ln);
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

void MainWindow::on_pushButton_clicked()
{
    Line* line = dynamic_cast<Line*>(figure);
    line->forPort();

    std::vector<double> arrAlpha = line->getAlpha();
    std::vector<double> arrBeta = line->getBeta();
    ArduinoCommunicator arduino("COM3");
    while(!arrAlpha.empty()){
        arduino.sendPen(0);
        double alpha = arrAlpha[0];
        double beta = arrBeta[0];
        arduino.sendAngles(alpha, beta);

        arrAlpha.erase(arrAlpha.begin());
        arrBeta.erase(arrBeta.begin());
    }
    arduino.sendPen(1);
    line->setAlpha(arrAlpha);
    line->setBeta(arrBeta);
}
