#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    linkedListWidget = new LinkedListWidget(this);
    // stackedWidget->addWidget(linkedListWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}






