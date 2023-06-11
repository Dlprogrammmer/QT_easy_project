#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QButtonGroup>
#include<QPainter>
#include<draw_weight.h>
#include<status.h>
#include<qdebug.h>
#include<qpoint.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();
    QPainter painter;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void draw_line();
    void draw_square();
    void draw_circular();
    void draw_string();
    void getstatus();

    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
    status *widget_status;
    QButtonGroup *types;
    draw_weight  *mywidget;
    QPoint startpoint;
    QPoint endpoint;
    static int x1,x2,y1,y2;

    void draw_start();
    void draw_end();
};

#endif // WIDGET_H
