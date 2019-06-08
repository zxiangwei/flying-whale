#ifndef PLAYER_H
#define PLAYER_H
#include <whale.h>
#include "gun.h"
#include "wave.h"
#include <vector>
#include <windows.h>
#include <ctime>
#include <QRect>
#include <memory.h>
using std::vector;
extern unsigned const whale_x0;
class player
{
    const short delta_t=45;
    short number;
    bool c[4];
    unsigned char keys[5];
    clock_t t_key=clock();
    static short const delta_x;
    static short const delta_y;
    void key();
    void shoot();
    void player_move();
    void predraw();
public:
    static QBrush const blood_brush;
    static QBrush const resource_brush;
    QRect const full_blood_rect;
    QRect const full_resource_rect;
    QRect to_erase_blood_rect;
    QRect to_erase_resource_rect;
    QBrush brush;
    QPen pen;
    static const unsigned full_blood;
    static const float r;
    unsigned x;
    unsigned y;
    unsigned blood=full_blood;
    vector<gun> guns;
    static const short max_resource;
    player(short number,unsigned x=20,unsigned y=20);
    void play();
    void attacked();
    void guns_change_number();
};
#endif // PLAYER_H
