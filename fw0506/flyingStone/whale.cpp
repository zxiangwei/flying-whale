#include "whale.h"
const unsigned whale::full_blood=100u;
QPen const whale::pen(QColor(120,100,222));
QBrush const whale::blood_brush(Qt::darkRed);
void whale::attack()
{
    if(blood<=full_blood/4*3)//<< >>
    {
        for(short i=0;i<sizeof(waves)/sizeof(wave);++i)
        {
            if((i+1)*whale_x0/(sizeof(waves)/sizeof(wave)+1)==x)
            {
               waves[i].recreate(x,y);
            }
        }
        if(x==whale_x0)
        {
            for(wave& k:waves)
            {
                k.disappear();
            }
        }
        for(wave& k:waves)
        {
            k.grow();
        }
    }
}
void whale::move()
{
//  a=(x-5)%whale_x0;
    x-=5;
    if(x>10000)
    {
        x=whale_x0;
    }
}
void whale::attacked()
{
    blood-=gun::hurt;
}
void whale::play()
{
    move();
    predraw();
    attack();
}
void whale::predraw()
{
    brush=QBrush(QColor(250-blood,100+blood,155+blood));
    pts.setPoints(12,
                  x,20,
                  10+x,10,
                  30+x,10,
                  40+x,20,
                  50+x,20,
                  60+x,0,
                  70+x,10,
                  80+x,10,
                  60+x,20,
                  50+x,30,
                  20+x,40,
                  10+x,30); //第一个参数表示3个点，后面是三个点坐标
    blood_rect=QRect(x+full_blood-blood,50,blood,10);
}
