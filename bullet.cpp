#include "bullet.h"
#include<QTime>
#include<QImage>
Bullet::Bullet()
{
    //子弹
    QString pixmap_url =":/res/bullet_"+QString::number(randomIntBullet()+8,10)+".png";

    m_Bullet.load(pixmap_url);

    m_X=GAME_WIDTH/2-m_Bullet.width()/2;
    m_Y=GAME_HEIGHT;

    m_Free=true;
    m_Speed=BULLET_RATE;//子弹的速度
    //子弹的框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    if (m_Free)
    {
        return;
    }
    m_Y-=m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_Y<=-m_Rect.height())
    {
        m_Free=true;
    }

}

int Bullet::randomIntBullet()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int n = qrand() % 7;    //随机数
    return  n;
}
