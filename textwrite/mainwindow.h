#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qfile.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_write_clicked();

    void on_read_clicked();

private:
    Ui::MainWindow *ui;
    int num;
    QFile files;
};
#endif // MAINWINDOW_H
