#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QObject>//timer
#include<vector>
#include <ctime>

using namespace std;

struct A
{
    int a,b;
};
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    int x,y;
    int x1,y1;
    int  c;//key
    int t1;//timer
    int k;//Whale
    int hurt;
    int MyHurt;
    int used;
    int WhaleDie;
    vector<A>v;
    vector<A>vv;
    clock_t t=clock();
     void draw();
     void draw1();
     void star();
     void success();
     void WhiteWhale();
     void WhaleBlood();
     void HurtSuccess();
     void KillWhale();
     void Attack();
     void FailAvoid();
     void MyResource();
     void Idie();
     void Night();
     void Fog();
protected:
    void paintEvent(QPaintEvent* ev);//paint
   //virtual void keyPressEvent(QKeyEvent*ev);//key
    void key();
    virtual void timerEvent(QTimerEvent*ev);//timer

};

#endif // WIDGET_H
