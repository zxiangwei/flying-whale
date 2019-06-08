#include "widget.h"
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow m;
    //m.show();

    MainWindow*w1=new  MainWindow;
    w1->show();

    //Widget w;
    //w.show();

    return a.exec();
}
