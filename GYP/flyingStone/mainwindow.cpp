#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include "ui_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
    ui->textEdit->setFocus();
    ui->pushButton->setDefault(false);
    ui->pushButton->setAutoDefault(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     Widget*wid=new Widget;
     wid->show();
    close();
}

void MainWindow::on_actionhelp_triggered()
{
    ui->textEdit->setText("There are 3 pattens.1.Day(The  whale is wandering around.Key mobile game levals,the key box shooting. When the resource is sufficient,it's unnecessary to eat.)"
                          "2.Night(The whale is dangerous!Do not try to cross the arc .) "
                          "3.Fog(Watch out the invisible attacks!)");
    ui->textEdit->setVisible(true);
    ui->textEdit->setEnabled(false);
}
//void MainWindow::keyPressEvent(QKeyEvent *){}

void MainWindow::on_actionthe_story_of_whale_triggered()
{
    ui->textEdit->setText("During your journey,you pass by a silent village.A villager told you that when it's foggy, there is an evil whale flying in the sky."
                          "Many people heard its scary cry,and vanished from the world. "
                          "Now the whale will appear!");
    ui->textEdit->setVisible(true);
    ui->textEdit->setEnabled(false);
}
