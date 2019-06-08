#ifndef GUN_H
#define GUN_H
#include <QPen>
#include <QColor>
#include <QBrush>
#include <fstream>
//using std::ifstream;
using std::ofstream;
class gun
{
    static const short all_resourse;
//    ofstream of;
//    ifstream if;
public:
    static const float r;
    static QPen const pen;
    static QBrush const brush;
    static short number;
    static short usable;
    static const short hurt;
    unsigned x=5000;
    unsigned y=5000;
    void create(unsigned x, unsigned y);
    void move();
    void save();
    friend ofstream& operator <<(ofstream& of,gun& g);
};
#endif // GUN_H
