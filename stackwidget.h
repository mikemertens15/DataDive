#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include "datastructurewidget.h"
#include "stack.h"

namespace Ui {
    class StackWidget;
}

class StackWidget : public DataStructureWidget
{
    Q_OBJECT

public:
    explicit StackWidget(QWidget *parent = nullptr);
    ~StackWidget();

private slots:
    void onAddButtonClicked() override; // Button will be "Push"
    void onDeleteButtonClicked() override; // Button will be "Pop" and will only remove top

private:
    Ui::StackWidget *ui;
    Stack<int> stack;

    void updateUI() override;
};

#endif // STACKWIDGET_H
