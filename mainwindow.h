#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QAction>
#include <QMenuBar>
#include "linkedlistwidget.h"

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
    void showLinkedList();

private:
    Ui::MainWindow *ui;
    QMenu *structuresMenu;
    QAction *showLinkedListAction;
    QStackedWidget *stackedWidget;
    QWidget *welcomeScreen;
    LinkedListWidget* linkedListWidget;
};
#endif // MAINWINDOW_H
