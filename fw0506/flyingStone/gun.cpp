#include "gun.h"
QPen const gun::pen(QColor(255,255,255));
QBrush const gun::brush(QColor(120,255,222));
const float gun::r=12.5f;
short const gun::hurt=2;
short const gun::all_resourse=100;
short gun::number=75;
short gun::usable=0;
void gun::create(unsigned x, unsigned y)
{
    this->x=x;
    this->y=y;
}
void gun::move()
{
    y-=20;
}
void gun::save()
{
//    of.open();
//    of<<"number\t"<<number;

}
