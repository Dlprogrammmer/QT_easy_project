#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qstringlist.h>
#include<qdebug.h>
#include<qfile.h>
#include<qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList header;
    header<<"id";
    header<<"name";
    header<<"score";




    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    num=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_button_clicked()
{
    ui->tableWidget->insertRow(num);
    num++;
}

void MainWindow::on_delete_button_clicked()
{
    QList<QTableWidgetItem *> selected = ui->tableWidget->selectedItems();
    if (!selected.isEmpty())
    {
        int row = selected.at(0)->row();
        ui->tableWidget->removeRow(row);
        num--;
    }
}

void MainWindow::on_write_clicked()
{

    QFile file("data.dat");
        if (!file.open(QIODevice::WriteOnly))
            return;

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_9);

        out << (quint32)ui->tableWidget->rowCount();
        out << (quint32)ui->tableWidget->columnCount();

        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
                QTableWidgetItem* item = ui->tableWidget->item(row, column);
                out << item->text();
            }
        }

        file.close();
}

void MainWindow::on_read_clicked()
{
    QFile file("data.dat");
        if (!file.open(QIODevice::ReadOnly))
            return;

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_9);

        quint32 rowCount;
        quint32 columnCount;
        in >> rowCount;
        in >> columnCount;

        ui->tableWidget->setRowCount(rowCount);
        ui->tableWidget->setColumnCount(columnCount);

        for (int row = 0; row < rowCount; ++row) {
            for (int column = 0; column < columnCount; ++column) {
                QString text;
                in >> text;
                QTableWidgetItem* item = new QTableWidgetItem(text);
                ui->tableWidget->setItem(row, column, item);
            }
        }

        file.close();

}
