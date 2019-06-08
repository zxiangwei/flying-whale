#include "coord.h"
coord::coord(unsigned x,unsigned y):
    x(x),y(y){}
unsigned coord::distance(coord& c)
{
    return sqrt((this->x-c.x)*(this->x-c.x)+(this->y-c.y)*(this->y-c.y));
}
void coord::operator +(coord& c)
{
    x+=c.x;
    y+=c.y;
}
void coord::operator -(coord& c)
{
    x-=c.x;
    y-=c.y;
}
