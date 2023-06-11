#include "draw_widget.h"
#include<QWidget>
class draw_widget : public QWidget
{
    Q_OBJECT

public:
    draw_widget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

draw_widget::draw_widget(QWidget *parent)
    : QWidget(parent)
{
    // constructor code here
}

void draw_widget::mousePressEvent(QMouseEvent *event)
{
    // mouse press event code here
}
