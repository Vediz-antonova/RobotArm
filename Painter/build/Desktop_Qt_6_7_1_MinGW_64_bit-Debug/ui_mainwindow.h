/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *CenterX;
    QLabel *CenterY;
    QGridLayout *gridLayout;
    QPushButton *SquareButton;
    QPushButton *ClearButton;
    QPushButton *RhombusButton;
    QPushButton *TriangleButton;
    QPushButton *RectangleButton;
    QPushButton *LineButton;
    QLabel *label;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(873, 532);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        CenterX = new QLabel(centralwidget);
        CenterX->setObjectName("CenterX");

        horizontalLayout->addWidget(CenterX);

        CenterY = new QLabel(centralwidget);
        CenterY->setObjectName("CenterY");

        horizontalLayout->addWidget(CenterY);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        SquareButton = new QPushButton(centralwidget);
        SquareButton->setObjectName("SquareButton");

        gridLayout->addWidget(SquareButton, 2, 0, 1, 1);

        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName("ClearButton");

        gridLayout->addWidget(ClearButton, 0, 0, 1, 1);

        RhombusButton = new QPushButton(centralwidget);
        RhombusButton->setObjectName("RhombusButton");

        gridLayout->addWidget(RhombusButton, 4, 0, 1, 1);

        TriangleButton = new QPushButton(centralwidget);
        TriangleButton->setObjectName("TriangleButton");

        gridLayout->addWidget(TriangleButton, 3, 0, 1, 1);

        RectangleButton = new QPushButton(centralwidget);
        RectangleButton->setObjectName("RectangleButton");

        gridLayout->addWidget(RectangleButton, 5, 0, 1, 1);

        LineButton = new QPushButton(centralwidget);
        LineButton->setObjectName("LineButton");

        gridLayout->addWidget(LineButton, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 6, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setAutoFillBackground(true);
        graphicsView->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(116, 169, 255);"));

        gridLayout_2->addWidget(graphicsView, 1, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 873, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::BottomToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CenterX->setText(QCoreApplication::translate("MainWindow", "CenterX:", nullptr));
        CenterY->setText(QCoreApplication::translate("MainWindow", "CenterY:", nullptr));
        SquareButton->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        ClearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        RhombusButton->setText(QCoreApplication::translate("MainWindow", "Rhombus", nullptr));
        TriangleButton->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        RectangleButton->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        LineButton->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Click me", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
