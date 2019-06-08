#ifndef WAVE_H
#define WAVE_H
#include <QRectF>
#include <QPen>
#include <QColor>
class wave
{
    const unsigned size0=80u;
    bool exist=false;
public:
    static QPen const pen;
    QRectF rect;
    unsigned x=-50;
    unsigned y=-50;
    unsigned a=size0;
    static const int startAngle;
    static const int spanAngle;
    static const short delta_r;
    static const short hurt;
    void recreate(unsigned x,unsigned y);
    void disappear();
    void grow();
    wave();
};
#endif // WAVE_H
