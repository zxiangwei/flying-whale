#include "dialog.h"
#include "ui_dialog.h"
Dialog::Dialog(clock_t t,QWidget *parent) :
    QDialog(parent),ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setFocus();
    ui->label_5->setText((QString)(to_string(t/1000)+'s').c_str());
}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::keyPressEvent(QKeyEvent *){}
