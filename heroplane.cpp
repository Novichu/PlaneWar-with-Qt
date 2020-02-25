#include "heroplane.h"
#include<QTime>
#include"config.h"

HeroPlane::HeroPlane()
{

    //飞机
    QString str=":/res/hero.png";
    if(randomIntPlane()==0)
    {

    }
    else{
        str=":/res/hero2.png";
    }
    m_Plane.load(str);

    m_X=(GAME_WIDTH-m_Plane.width())/2;
    m_Y=GAME_HEIGHT-m_Plane.height();
    //初始化矩阵
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);

    m_recorder=0;
}

void HeroPlane::shoot()
{
    m_recorder++;
    if(m_recorder<BULLET_INTERVAL)
    {
        return;
    }
    m_recorder=0;

    for (int i=0;i<BULLET_NUM;i++) {
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free=false;//设置子弹
            m_bullets[i].m_X=m_X+m_Rect.width()/2-10;
            m_bullets[i].m_Y=m_Y-25;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_Rect.moveTo(m_X,m_Y);
}

int HeroPlane::randomIntPlane()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int n = qrand() % 2;    //随机数
    return  n;
}
