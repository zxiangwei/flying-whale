#include "star.h"
short star::number=50;
short const star::r=15;
QBrush const star::brush=QBrush(QColor(255,255,255));
star::star():pen(QColor(255,255,255))
{//srand(time(nullptr));
    create();
}
void star::create()
{
    pen=QPen(QColor(rand()%255,rand()%255,rand()%255));
    x=rand()%1500;
    y=80+rand()%600;
}
void star::disappear()
{
    x=y=-50;
    --star::number;
}
