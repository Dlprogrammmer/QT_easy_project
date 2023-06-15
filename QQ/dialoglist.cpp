#include "dialoglist.h"
#include "ui_dialoglist.h"
#include"QToolButton"
#include"qpixmap.h"
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
        QString str=QString(":/image/%1.jpg").arg(iconList.at(i));
        btn->setText(nameList[i]);
        btn->setIcon(QIcon(str));
        btn->setIconSize(QSize(80,80));
        btn->setAutoRaise(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->VLayout->addWidget(btn);
        vToolbtn.push_back(btn);
    }

}

DialogList::~DialogList()
{
    delete ui;
}
