#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    structuresMenu = ui->structuresMenu;
    showLinkedListAction = ui->showLinkedListAction;
    connect(showLinkedListAction, &QAction::triggered, this, &MainWindow::showLinkedList);

    welcomeScreen = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *welcomeLabel = new QLabel("Welcome to DataDive!");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);
    QLabel *instructionLabel = new QLabel("Please select a data structure from the menu above.");
    instructionLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(instructionLabel);
    welcomeScreen->setLayout(layout);

    linkedListWidget = new LinkedListWidget(this);
    stackedWidget = ui->stackedWidget;
    stackedWidget->addWidget(welcomeScreen);
    stackedWidget->addWidget(linkedListWidget);

    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentWidget(welcomeScreen);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLinkedList() {
    stackedWidget->setCurrentWidget(linkedListWidget);
}






