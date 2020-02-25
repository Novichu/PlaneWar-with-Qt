#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"
#include"config.h"
class HeroPlane
{
public:
    HeroPlane();

    //子弹
    void shoot();
    void setPosition(int x,int y);
    int randomIntPlane();
    //飞机资源
    QPixmap m_Plane;
    int m_X;
    int m_Y;
    //飞机边框
    QRect m_Rect;
    //子弹
    Bullet m_bullets[BULLET_NUM];

    int m_recorder;//计数器

};

#endif // HEROPLANE_H
