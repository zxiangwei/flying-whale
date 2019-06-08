#include "dialog1.h"
#include "ui_dialog1.h"
#include <windows.h>

Dialog1::Dialog1(clock_t t,QWidget *parent) :
    QDialog(parent),ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    ui->label->setFocus();
    ui->label_5->setText((QString)(to_string(t/1000)+'s').c_str());
}
Dialog1::~Dialog1()
{
    delete ui;
}
void Dialog1::keyPressEvent(QKeyEvent *){}
