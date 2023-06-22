#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    enum Msgtype{Msg,UserEnter,UserLeft};//枚举 普通信息 用户进入 用户退出
    Widget(QWidget *parent,QString name);
    void sendMsg(Msgtype type);//广播udp信息
    QString getName();//获取名字
    QString getMsg();//获取聊天信息
    void userEnter(QString username);//用户进入
    void userLeft(QString username,QString time);//用户离开
    void ReceiveMessage();//接受UDP信息
    ~Widget();
    void  closeEvent(QCloseEvent*);
signals:
    void closeWidget();

private:
    Ui::Widget *ui;
    QString myname;
    quint16 port;
    QUdpSocket *udpSocket;
};
#endif // WIDGET_H
