#include "widget.h"
#include "ui_widget.h"
#include"QMessageBox"
#include"QDateTime""
Widget::Widget(QWidget *parent,QString name)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myname=name;
    this->port=9999;
    this->udpSocket=new QUdpSocket(this);
    //绑定端口
    //ShareAddress允许其他服务器连接到相同的地址和端口
    //ReuseAddressHint重新连接服务器
    udpSocket->bind(this->port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        sendMsg(Msg);
    });
}

void Widget::sendMsg(Msgtype type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream<<type<<this->getName();
    switch(type)
    {
    case Msg:
        if(this->ui->msgtextEdit->toPlainText()=="")
        {
            QMessageBox::warning(this,"警告","发送内容不能为空");
            return ;
        }
        stream<<this->getMsg();
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    //Broadcast广播
    udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
}

QString Widget::getName()
{
    return this->myname;
}

QString Widget::getMsg()
{
    QString msg=ui->msgtextEdit->toHtml();//返回输入内容
    ui->msgtextEdit->clear();//将内容清空
    ui->msgtextEdit->setFocus();//设置光标
    return msg;
}

void Widget::ReceiveMessage()
{
    qint64 size=udpSocket->pendingDatagramSize();
    int mysize=static_cast<int>(size);
    QByteArray *array=new QByteArray(mysize,0);
    udpSocket->readDatagram(array->data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int msgtype;
    stream>>msgtype;
    QString name,msg;
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    switch(msgtype)
    {
    case Msg:
        stream>>name>>msg;
        ui->msgBrowser->setTextColor(Qt::blue);
        ui->msgBrowser->setCurrentFont(QFont("Time New Roma",12));
        ui->msgBrowser->append("["+name="]"+time);
        ui->msgBrowser->append(msg);
        break;
    case UserEnter:
        stream>>name;
        userEnter(name);
        break;
    case UserLeft:
        stream>>name;
        userLeft(name,time);
        break;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *)
{
    emit this->closeWidget();
}

