#ifndef WHALE_H
#define WHALE_H
#include "gun.h"
#include "wave.h"
#include <QPolygon>
#include <QRect>
const unsigned whale_x0=1800u;
class whale
{
    const unsigned y=30u;
    void predraw();
    void attack();
    void move();
public:
    static const float r;
    static QBrush const blood_brush;
    QRect blood_rect;
    QPolygon pts;
    static QPen const pen;
    QBrush brush;
    static unsigned const full_blood;
    unsigned x=whale_x0;
    wave waves[5];
    unsigned blood=full_blood;
    void attacked();
    void play();
};
#endif // WHALE_H
