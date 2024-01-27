#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QColorDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    connect(ui->addNode, &QPushButton::clicked, this, &MainWindow::onAddButtonPressed);
    connect(ui->nodeColorButton, &QPushButton::clicked, this, &MainWindow::onNodeColorButtonClicked);
    nodeColor = Qt::lightGray;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddButtonPressed()
{
    // Read value from QLineEdit
    bool ok;
    int value = ui->nodeValueInput->text().toInt(&ok);

    // Check if conversion was successful
    if (ok) {
        // Add value to linked list
        myList.insert_at_back(value);
        updateUI();
    } else {
        // Handle Invalid Input
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer");

    }
}

void MainWindow::onNodeColorButtonClicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Select node color");
    if (color.isValid()) nodeColor = color;
}

void MainWindow::updateUI()
{
    // Clear the Scene
    scene->clear();

    Node<int>* current = myList.getHead();
    int nodeWidth = 50;
    int nodeHeight = 30;
    int horizontalSpacing = 30;
    int verticalSpacing = 50;
    int xPos = 10; // Horizontal position of node
    int yPos = 50; // Vertical position of node
    int viewWidth = ui->graphicsView->width();

    // Node and text styling
    QPen pen(Qt::black);
    pen.setWidth(2);
    QBrush brush(nodeColor);
    QFont font("Arial", 10, QFont::Bold);

    while (current != nullptr) {
        // Create a rectangle item for node
        QGraphicsRectItem* rect = new QGraphicsRectItem(xPos, yPos, nodeWidth, nodeHeight);
        rect->setPen(pen);
        rect->setBrush(brush);
        scene->addItem(rect);

        // Create a text item for node value
        QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(current->data), rect);
        text->setFont(font);
        text->setPos(xPos + (nodeWidth - text->boundingRect().width()) / 2, yPos + (nodeHeight - text->boundingRect().height()) / 2);

        // Arrpw fpr the next node (if not the last node)
        if (current->next != nullptr) {
            if (xPos + nodeWidth + horizontalSpacing + nodeWidth > viewWidth) {
                // Start a new row
                yPos += verticalSpacing;
                xPos = 10 - horizontalSpacing;
            }

            QGraphicsLineItem* line = new QGraphicsLineItem(xPos + nodeWidth, yPos + nodeHeight / 2, xPos + nodeWidth + horizontalSpacing, yPos + nodeHeight / 2);
            line->setPen(pen);
            scene->addItem(line);

            // Draw an arrowhead
            QGraphicsPolygonItem* arrowHead = new QGraphicsPolygonItem();
            QPolygonF arrowPolygon;
            arrowPolygon << QPointF(xPos + nodeWidth + horizontalSpacing, yPos + nodeHeight / 2) << QPointF(xPos + nodeWidth + horizontalSpacing - 10, yPos + nodeHeight / 2 - 5) << QPointF(xPos + nodeWidth + horizontalSpacing - 10, yPos + nodeHeight / 2 + 5);
            arrowHead->setPolygon(arrowPolygon);
            arrowHead->setBrush(brush);
            scene->addItem(arrowHead);
        }

        // Move to next node and update position
        current = current->next;
        xPos += nodeWidth + horizontalSpacing; // Move to the right for next node
    }

    // Resize scene to fit the items
    scene->setSceneRect(scene->itemsBoundingRect());
}
