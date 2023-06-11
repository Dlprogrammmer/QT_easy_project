#include "draw_weight.h"
#include<QMouseEvent>
#include<QPoint>
#include<QDebug>
draw_weight::draw_weight(QWidget *parent) : QWidget(parent)
{

}
void draw_weight::mousePressEvent(QMouseEvent *event){
    qDebug()<<"oo"<<endl;
}
