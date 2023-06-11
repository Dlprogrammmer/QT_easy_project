#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QMouseEvent>
#include<QWidget>
#include<status.h>
#include<QButtonGroup>
#include<QColor>
#include<QMouseEvent>
#include<draw_weight.h>
#include<qdebug.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->board->installEventFilter(this);
    ui->board->setStyleSheet("background-color:rgb(255,255,255)");
    Widget::types=new QButtonGroup(this);
    types->addButton(ui->draw_line,0);
    types->addButton(ui->draw_square,1);
    types->addButton(ui->draw_circular,2);
    types->addButton(ui->draw_string,3);
    ui->draw_line->setChecked(1);
    ui->line_r->setRange(0,255);
    ui->line_g->setRange(0,255);
    ui->line_b->setRange(0,255);
    ui->brush_r->setRange(0,255);
    ui->brush_g->setRange(0,255);
    ui->brush_b->setRange(0,255);
}
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->board&& event->type() == QEvent::MouseButtonPress)//发生绘图事件，且是在widget上发生的
        {

        getstatus();
        draw_start();
        return true;
        }
    else if(watched == ui->board&& event->type() == QEvent::MouseButtonRelease)
    {
        draw_end();
    }
    else
        return false;
}
void Widget::getstatus(){
    this->widget_status=new status(ui->line_wide->value(),types->checkedId(),ui->lineEdit->text(),ui->line_r->value(),ui->line_g->value(),ui->line_g->value(),ui->brush_r->value(),ui->brush_g->value(),ui->brush_b->value());
    return ;
}
void Widget::draw_start(){
    QPoint starPoint=this->startpoint;
    int x1=starPoint.x();
    int y1=starPoint.y();
    getstatus();

    return;
}
void Widget::draw_end(){
    switch (widget_status->type) {
    case 1:{
        QPainter painter(this->ui->board);
        painter.setPen(QPen(QColor(widget_status->draw_r,widget_status->draw_g,widget_status->draw_b),widget_status->wide,Qt::SolidLine,Qt::RoundCap));
        QBrush drawbrush((QColor(widget_status->brush_r,widget_status->brush_g,widget_status->brush_b)),Qt::SolidPattern);
        if(ui->checkBox->isChecked())
            QBrush drawbrush(Qt::white,Qt::SolidPattern);
        painter.setBrush(drawbrush);
         painter.drawLine(100,70,100,500);
    }

    case 2:
        painter.drawRect(170,70,100,50);
    case 3:
        painter.drawEllipse(170,200,100,200);
    default:;
    }
    return;
}
void Widget::draw_line(){

}
void Widget::draw_square(){

}
void Widget::draw_circular(){

}
void Widget::draw_string(){

}
void Widget::mousePressEvent(QMouseEvent *event){
     startpoint=event->pos();
}
void Widget::mouseMoveEvent(QMouseEvent *event){
    endpoint=event->pos();
}
void Widget::mouseReleaseEvent(QMouseEvent *event){
    endpoint=event->pos();
}
Widget::~Widget()
{
    delete ui;
}



