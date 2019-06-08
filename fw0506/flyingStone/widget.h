#ifndef WIDGET_H
#define WIDGET_H
#include <QObject>//timer
#include <QPixmap>//add background
#include <QPalette>
#include <QPainter>
#include <QTimerEvent>//timer
#include <QWidget>
#include <cmath>
#include "ui_widget.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "dialog1.h"
#include "ui_dialog1.h"
#include "whale.h"
#include "star.h"
#include "wave.h"
#include "gun.h"
#include "player.h"
namespace Ui
{
    class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    clock_t t0=clock();
    Ui::Widget *ui;
    const short delta_t=50;
    short t;//timer
    whale w;
    player p;
    star stars[50];
    double d(double x1,double y1,double x2,double y2);
    void draw_whale();
    void draw_stars();
    void draw_night();
    void draw_fog();
    void draw_background();
    void draw_rect();
    void draw_myself();
    void draw_waves();
    void draw_guns();
    void eat();
    void attack_me();
    void attack_whale();
    void end();
    void star_update();
    void paintEvent(QPaintEvent*);//paint
    virtual void timerEvent(QTimerEvent*ev);//timer
};
#endif // WIDGET_H
