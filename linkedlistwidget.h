#ifndef LINKEDLISTWIDGET_H
#define LINKEDLISTWIDGET_H

#include <QWidget>
#include "datastructurewidget.h"
#include "linkedList.h"

namespace Ui {
class LinkedListWidget;
}

class LinkedListWidget : public DataStructureWidget
{
    Q_OBJECT

public:
    explicit LinkedListWidget(QWidget *parent = nullptr);
    ~LinkedListWidget();

public slots:
    void onAddButtonClicked() override;
    void onDeleteButtonClicked() override;
    void onSearchButtonClicked() override;
    void onResetButtonClicked() override;
    void onSortButtonClicked();

protected:
    void updateUI() override;

private:
    Ui::LinkedListWidget *ui;
    Linked_List<int> myList;
};

#endif // LINKEDLISTWIDGET_H
