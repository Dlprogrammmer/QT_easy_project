#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

const int AREA_ROW=20;
const int AREA_COL=12;
const int MARGIN=5;
const int BLOCK_SIZE=25;
enum Direction{
  UP,DOWN,LEFT,RIGHT,SPACE
};
struct Border{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};
struct block_point{
    int pos_x,pos_y;
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public:
    void InitGameFunc();
    void StartGameFunc();
    void GameOverFunc();
    void ResetBlock();
    void BlockMove(Direction dir);
    void BlockRotate(int block[4][4]);
    void CreateBlock(int block[4][4],int block_id);
private:
    int game_area[AREA_ROW][AREA_COL];
    int cur_block[4][4];
    int next_block[4][4];
    block_point block_pos;
    Border cur_border;
    int score;
    int game_timer;
    int paint_timer;
    int speed_ms;
    int refresh_ms;

};
#endif // MAINWINDOW_H
