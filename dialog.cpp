#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <windows.h>
#include <ctime>
#include <QPainter>
#include <QPen>

Dialog::Dialog(clock_t t,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
//    while(!GetAsyncKeyState(VK_RETURN))
//    {
//        Sleep(100000);
//    }
    ui->setupUi(this);
    QString s=(QString)(std::to_string((clock()-t)/1000)+'s').c_str();
    ui->lineEdit->setText(s);
    //ui->lineEdit->setBackgroundRole(
    ui->lineEdit->setEnabled(false);
//    QPainter paint(this);
//    QPen pen(QColor(255,0,0));
//    paint.setPen(pen);
//    paint.drawText(300,300,s);
    //ui->lineEdit->setTextMargins();
    //ui->buttonBox->setShortcutAutoRepeat(Qt::Key_Return);
    //ui->buttonBox->setShortcutAutoRepeat(Qt::Key_Enter);
    //ui->buttonBox->setShortcutAutoRepeat(Qt::Key_Space,false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{

}
