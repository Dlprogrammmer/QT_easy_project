#include "dialoglist.h"
#include "ui_dialoglist.h"
#include"QToolButton"
#include"qpixmap.h"
#include"widget.h"
#include"QMessageBox""
DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{

    ui->setupUi(this);
    setWindowTitle("QQ 2023");
    setWindowIcon(QIcon(":/image/qq.jpg"));
    QList<QString> nameList;
    nameList<<"蔡徐坤"<<"薇恩"<<"盲僧"<<"永恩";
    QList<QString> iconList;
    iconList<<"1"<<"2"<<"3"<<"4";
    QVector<QToolButton*> vToolbtn;
    for(int i=0;i<4;i++){
        QToolButton * btn=new QToolButton;
        //加载图标
        QString str=QString(":/image/%1.jpg").arg(iconList.at(i));
        //设置网名
        btn->setText(nameList[i]);
        //设置图片
        btn->setIcon(QIcon(str));
        btn->setIconSize(QSize(50,50));
        //设置为透明
        btn->setAutoRaise(true);
        //设置显示格式
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->VLayout->addWidget(btn);
        vToolbtn.push_back(btn);
        IsShow.push_back(false);
    }
    for(int i=0;i<4;i++)
    {
        connect(vToolbtn[i],&QToolButton::clicked,[=](){
            if(IsShow[i]){
                QMessageBox::warning(this,"警告","该聊天已打开");
                return;
            }
            IsShow[i]=true;
            Widget *widget=new Widget(nullptr,vToolbtn[i]->text());
            widget->setWindowIcon(vToolbtn[i]->icon());
            widget->setWindowTitle(vToolbtn[i]->text());
            widget->show();
            connect(widget,&Widget::closeWidget,this,[=]{
                IsShow[i]=false;
            });
        });
    }

}

DialogList::~DialogList()
{
    delete ui;
}
