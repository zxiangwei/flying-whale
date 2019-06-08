#ifndef STARS_H
#define STARS_H
#include <QPen>
#include <QBrush>
#include <QColor>
struct star
{
    static QBrush const brush;
    QPen pen;
    static short number;
    static const short r;
    unsigned x;
    unsigned y;
    star();
    void create();
    void disappear();
};
#endif // STARS_H
