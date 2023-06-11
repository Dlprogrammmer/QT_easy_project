#include "mainwindow.h"
#include "ui_mainwindow.h"


#include<time.h>
#include<QMessageBox>
#include<QPainter>
#include<QKeyEvent>
#include<QtDebug>
int item1[4][4]={
    {0,0,0,0},
    {0,1,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
int item2[4][4]{
    {0,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,0,0}
};
int item3[4][4]{
    {0,0,1,0},
    {0,0,1,0},
    {0,1,1,0},
    {0,0,0,0}
};
int item4[4][4]{
    {0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}
};
int item5[4][4]{
    {0,0,1,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}
};
int item6[4][4]{
    {0,0,0,0},
    {0,0,1,0},
    {0,1,1,1},
    {0,0,0,0}
};
int item7[4][4]{
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,1,0}
};
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitGameFunc(){
for(int i=0;i<AREA_ROW;i++)
{
    for(int j=0;j<AREA_COL;j++){
    game_area[i][j]=0;
    }
}
speed_ms=800;
refresh_ms=30;
srand(time(0));
score=0;
StartGameFunc();
}
void MainWindow::StartGameFunc(){

}
void MainWindow::GameOverFunc(){

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("俄罗斯方块");
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(AREA_COL*BLOCK_SIZE+MARGIN*4+4*BLOCK_SIZE,AREA_ROW*BLOCK_SIZE+MARGIN*2);
    QPixmap bkground(":/new/prefix1/image/background.jpg");
    bkground=bkground.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palatte;
    palatte.setBrush(QPalette::Background,bkground);
    this->setPalette(palatte);
    InitGameFunc();
}
