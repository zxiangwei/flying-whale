#ifndef COORD_H
#define COORD_H
#include "math.h"
struct coord
{
    unsigned x;
    unsigned y;
    void operator+(coord& c);
    void operator-(coord& c);
    coord(unsigned x,unsigned y);
    unsigned distance(coord& c);
};
#endif // COORD_H
