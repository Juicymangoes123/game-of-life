#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton("Button", this);
    int buttonX, buttonY, buttonW, buttonH;
    buttonX = 50;
    buttonY = 50;
    buttonW = 50;
    buttonH = 50;
    button->setGeometry(buttonX, buttonY, buttonW, buttonH);
    for (int i = 0; i < 10; i++) {
        std::cout << MainWindow::success() << "\n";
    }
    int num = 50;
    int thick = 50;
    drawVert(num, thick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::success() {
    return 1;
}

bool MainWindow::drawVert(int num, int thick) {
    QPainter painter(this);
    QPen pen(Qt::black, thick, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    painter.setPen(pen);
    int iterations = this->width()/num;
    std::cout << "Num: " << num << ", thick: " << thick << ", iterations: " << iterations << "\n";
    int startX, startY, lineHeight;
    startX = 70;
    startY = 70;
    lineHeight = 80;
    for (int i = 0; i < iterations; i++) {
        painter.drawLine(startX + i * iterations, startY, startX, startY - lineHeight);
        std::cout << "yes\n";
    }
    return 1;
}
