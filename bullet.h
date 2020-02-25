#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>
#include<QRect>
#include"config.h"
class Bullet
{
public:
    Bullet();

    void updatePosition();
    int randomIntBullet();
    QPixmap m_Bullet;

    //定义子弹
    int m_X;
    int m_Y;

    int m_Speed;
    bool m_Free;//设置子弹闲置

    QRect m_Rect;//子弹框
};

#endif // BULLET_H
