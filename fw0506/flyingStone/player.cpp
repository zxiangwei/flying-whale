#include "player.h"
const float player::r=12.5f;
short const player::max_resource=75;//75;
short const player::delta_x=40;
short const player::delta_y=40;
unsigned const player::full_blood=750u;
QBrush const player::blood_brush(Qt::darkRed);
QBrush const player::resource_brush(Qt::blue);
player::player(short number,unsigned x,unsigned y):
     full_resource_rect(800,800,10*max_resource,15),full_blood_rect(0,800,full_blood,15),
     pen(QColor(255,255,255)),brush(QColor(120,255,222)),number(number),x(x),y(y)
{
    guns.reserve(gun::number);
    for(short i=0;i<max_resource;++i)
    {
        gun temp;
        guns.push_back(temp);
    }
    memset(c,0,sizeof(c));
    switch(number)
    {
    case 0:
        keys[0]='W';
        keys[1]='S';
        keys[2]='A';
        keys[3]='D';
        keys[4]=VK_SPACE;
        break;
    case 1:
        keys[0]=VK_UP;
        keys[1]=VK_DOWN;
        keys[2]=VK_LEFT;
        keys[3]=VK_RIGHT;
        keys[4]=VK_RETURN;
        break;
    }
}
void player::key()
{
    static bool space_flag=true;
    if(clock()-t_key>delta_t)
    {
        for(short i=0;i<sizeof(keys)/sizeof(unsigned char)-1;++i)
        {
            if(GetAsyncKeyState(keys[i]))
            {
                c[i]=true;
            }
        }
        if(space_flag&&GetAsyncKeyState(keys[sizeof(keys)/sizeof(unsigned char)-1]))
        {
            space_flag=false;
            guns_change_number();
        }
        else if(!GetAsyncKeyState(keys[sizeof(keys)/sizeof(unsigned char)-1]))
        {
            space_flag=true;
        }
        t_key=clock();
    }
}
void player::guns_change_number()
{
    if(gun::number>0)
    {
        --gun::number;
        if(gun::usable<gun::number)
        {
            ++gun::usable;
        }
    }
}
void player::shoot()
{
    for(short i=0;i<gun::usable;++i)
    {
        if(guns[i].x>3000)//tu///////((unsigned)-1)/2
        {
            guns[i].create(x,y);
        }
        if(guns[i].y>10000)
        {
            guns.erase(guns.begin()+i);
            --gun::usable;
        }
        guns[i].move();
    }
}
void player::play()
{
    key();    
    player_move();
    memset(c,0,sizeof(c));
    shoot();
    predraw();
}
void player::attacked()
{
    blood-=wave::hurt;
}
void player::player_move()
{
    x+=(c[3]-c[2])*delta_x;
    y-=(c[0]-c[1])*delta_y;
    if(x>10000)
    {
        x=0;
    }
    else if(x>whale_x0)
    {
        x=whale_x0;
    }
    if(y>10000)
    {
        y=0;
    }
    else if(y>800)
    {
        y=800;
    }
}
void player::predraw()
{
    to_erase_blood_rect=QRect(0,800,full_blood-blood,14);
    to_erase_resource_rect=QRect(800,800,10*(max_resource-gun::number),14);
}
