#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();
    img = new resim(this);

    img->setGeometry(50, 50, 600, 600);
    img->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    img->cizCember(ui->lineEdit->text().toInt());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Resimi Kaydet","/home/vahit");
    img->Kaydet(path);
}

void MainWindow::on_pushButton_3_clicked()
{
    img->cizCemberBresenham(ui->lineEdit->text().toInt());
}

void MainWindow::on_pushButton_4_clicked()
{
    img->cizDaire(ui->lineEdit->text().toInt());
}

void MainWindow::on_pushButton_5_clicked()
{
    img->sinavSorusu();
}

void MainWindow::on_pushButton_6_clicked()
{
    img->imageYerlestirme();
}

void MainWindow::on_pushButton_7_clicked()
{
    img->poligon();
}

void MainWindow::on_pushButton_8_clicked()
{
    img->doldurAlan();
}

void MainWindow::on_pushButton_9_clicked()
{
    img->icIceDaire();
}

void MainWindow::on_pushButton_10_clicked()
{
    img->koseliDaire();
}
