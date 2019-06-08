#include "wave.h"
const short wave::delta_r=4;
QPen const wave::pen(Qt::blue,delta_r,Qt::SolidLine);
short const wave::hurt=10u;
int const wave::startAngle=-150;//210
int const wave::spanAngle=120;
wave::wave():rect(10000,10000,0,0){}
void wave::recreate(unsigned x,unsigned y)
{
    this->x=x;
    this->y=y;
    a=size0;
    exist=true;
}
void wave::disappear()
{
    x=y=10000u;//-50u
    rect=QRect(10000,10000,0,0);//-a
    exist=false;
}
void wave::grow()
{
    if(exist)
    {
        rect=QRect(x,y,a,a);
        a+=5;
    }
}
