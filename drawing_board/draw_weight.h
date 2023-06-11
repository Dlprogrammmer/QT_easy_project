#ifndef DRAW_WEIGHT_H
#define DRAW_WEIGHT_H

#include <QWidget>
#include<QMouseEvent>
class draw_weight : public QWidget
{
    Q_OBJECT
public:
    explicit draw_weight(QWidget *parent = nullptr);
public:
    void mousePressEvent(QMouseEvent *event);
public slots:
signals:
    void i(QMouseEvent *event);
public:

private:
        int x1,x2,y1,y2;
};

#endif // DRAW_WEIGHT_H
