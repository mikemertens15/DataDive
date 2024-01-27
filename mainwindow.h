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
    void updateUI();

public slots:
    void onAddButtonPressed();

private slots:
    void onNodeColorButtonClicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Linked_List<int> myList;
    QColor nodeColor;
};
#endif // MAINWINDOW_H
