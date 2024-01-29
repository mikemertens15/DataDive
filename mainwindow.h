#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "linkedList.h"

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
    void highlightNode(int data, QColor color);
    void updateUI();

public slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onSearchButtonClicked();
    void onResetButtonClicked();
    void onNodeVisited(int data);
    void onNodeFound(int data);

private slots:
    void onNodeColorButtonClicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Linked_List<int> myList;
    QColor nodeColor;
};
#endif // MAINWINDOW_H
