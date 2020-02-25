#ifndef ENENMYPLANE_H
#define ENENMYPLANE_H
#include"config.h"
#include"QPixmap"
#include"QRect"
class enemyPlane
{
public:
    enemyPlane();
    void updatePosition();
    int randomIntEnemy();
    QPixmap m_enemy;
    //定义位置
    int m_X;
    int m_Y;

    int m_Speed;
    bool m_Free;//设置敌机闲置

    QRect m_Rect;//敌机框
};

#endif // ENENMYPLANE_H
