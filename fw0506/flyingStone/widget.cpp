#include "widget.h"
double Widget::d(double x1,double y1,double x2,double y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
Widget::Widget(QWidget *parent) :
    QWidget(parent),ui(new Ui::Widget),p(0)
{
    ui->setupUi(this);
    QPixmap iconR(":/new/prefix1/image/iconR.jpg");
    QPixmap iconB(":/new/prefix1/image/iconB.png");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,iconB);
    setPalette(palette);
    setWindowIcon(iconR);
    t=startTimer(delta_t);
}
Widget::~Widget()
{
    delete ui;
    killTimer(t);
}
void Widget::draw_night()
{
    QPainter painter(this);
    if(w.blood>=w.full_blood/2&&w.blood<=w.full_blood/4*3)
    {
        QBrush brush(QColor(10+w.blood,205-w.blood,297-w.blood));
        painter.setBrush(brush);
    }
    if(w.blood<=w.full_blood/4)
    {
        QBrush brush(QColor(110,150-w.blood,242-w.blood));
        painter.setBrush(brush);
    }
    painter.drawRect(0, 0, 1550, 750);
    ui->label_4->setText("Night(The whale is dangerous!Do not try to cross the arc from behind.)");
}
void Widget::draw_fog()
{
    QPainter painter(this);
    QPen pen(QColor(255,255,255));//white
    QBrush brush(QColor(250-w.blood,250-w.blood,250-w.blood));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, 1550, 750);
    ui->label_4->setText("Fog(Watch out the invisible attacks!)");
}
void Widget::draw_background()
{
    ui->label_5->setText((QString)((to_string((clock()-t)/1000))+'s').c_str());
    if((w.blood<=w.full_blood/4)||(w.blood<=w.full_blood/4*3&&w.blood>=w.full_blood/2))
    {
        draw_night();
    }
    else if(w.blood<w.full_blood/2&&w.blood>w.full_blood/4)
    {
        draw_fog();
    }
    update();
}
void Widget::draw_stars()
{
    QPainter painter(this);
    for(star& s:stars)
    {
        painter.setPen(s.pen);
        painter.setBrush(s.brush);
        painter.drawEllipse(s.x,s.y,s.r,s.r);
    }
    update();
}
void Widget::draw_whale()
{
    QPainter painter(this);
    painter.setPen(w.pen);
    painter.setBrush(w.brush);
    painter.drawConvexPolygon(w.pts);
    update();
}
void Widget::draw_myself()
{
    QPainter painter(this);
    painter.setPen(p.pen);
    painter.setBrush(p.brush);
    painter.drawEllipse(p.x,p.y,2*p.r,2*p.r);
    update();
}
void Widget::draw_rect()
{
    QPainter painter(this);
    painter.fillRect(w.blood_rect, w.blood_brush);
    painter.fillRect(p.full_blood_rect, p.blood_brush);
    painter.eraseRect(p.to_erase_blood_rect);
    painter.fillRect(p.full_resource_rect, p.resource_brush);
    painter.eraseRect(p.to_erase_resource_rect);
    update();
}
void Widget::draw_waves()
{
    if((w.blood<=w.full_blood/4)||(w.blood<=w.full_blood/4*3&&w.blood>=w.full_blood/2))
    {
        QPainter painter(this);
        painter.setPen(wave::pen);
        for(wave& k:w.waves)
        {
            painter.drawArc(k.rect,16*k.startAngle,16*k.spanAngle);
        }
    }

}
void Widget::draw_guns()
{
    QPainter painter(this);
    painter.setPen(gun::pen);
    painter.setBrush(gun::brush);
    for(gun& k:p.guns)
    {
        painter.drawEllipse(k.x,k.y,2*gun::r,2*gun::r);
    }
    update();
}
void Widget::star_update()
{
    if(star::number<30)
    {
        star::number=sizeof(stars)/sizeof(star);
        for(star& s:stars)
        {
            s.create();
        }
    }
}
void Widget::eat()
{
     for(star& s:stars)
     {
         double distance=d(p.x+p.r,p.y+p.r,s.x+s.r,s.y+s.r);
         if(gun::number<p.max_resource&&distance<p.r+s.r&&distance>fabs(p.r-s.r))//40
         {
            s.disappear();
            gun temp;
            p.guns.push_back(temp);
            ++gun::number;
         }
     }
}
void Widget::end()
{
    if(w.blood>10000)
    {
        Dialog *d1=new Dialog(clock()-t0);
        d1->show();
        killTimer(t);
        close();
    }
    else if(p.blood>10000)
    {
        Dialog1 *d2=new Dialog1(clock()-t0);
        d2->show();
        killTimer(t);
        close();
    }
}
void Widget::attack_me()
{
    for(wave& k:w.waves)
    {
        double distance=d(p.x+p.r,p.y+p.r,k.x+k.a/2,k.y+k.a/2);
        if(k.x<5000&&distance>p.r+k.a/2&&distance<p.r+k.a/2+wave::delta_r&&p.y+2*p.r>=k.y+k.a/4*3)
        {
            p.attacked();
        }
    }
}
void Widget::attack_whale()
{
    for(short i=0;i<p.guns.size();++i)
    {
        if(p.guns[i].x>=w.x&&p.guns[i].x<w.x+80&&p.guns[i].y<40)
        {
            w.attacked();
//            p.guns.erase(p.guns.begin()+i);
//            break;
        }
        if(w.x>3000)
        {
            break;
        }
    }
}
void Widget::paintEvent(QPaintEvent*)//paint
{
    draw_background();
    draw_stars();
    draw_myself();
    draw_whale();
    draw_rect();
    draw_waves();
    draw_guns();
}
void Widget::timerEvent(QTimerEvent *ev)//timer
{
     if(ev->timerId()==t)
     {
         update();
         p.play();
         w.play();
         star_update();
         eat();
         attack_me();
         attack_whale();
         end();
     }
}
