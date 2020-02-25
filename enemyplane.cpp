#include "enemyplane.h"
#include<QTime>
//#include<qDebug>
enemyPlane::enemyPlane()
{
    QString pixmap_url =":/res/img-plane_"+QString::number(randomIntEnemy(),10)+".png";
    m_enemy.load(pixmap_url);
//    qDebug()<<pixmap_url;
    m_X=0;
    m_Y=0;
    //敌机的速度
    m_Free=true;
    m_Speed=ENEMY_SPEED;
    //框
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);
}

void enemyPlane::updatePosition()
{
    if(m_Free)
    {
        return;
    }
    m_Y+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //超出屏幕则重置
    if(m_Y>=GAME_HEIGHT+m_Rect.height())
    {
        m_Free=true;
    }
}

int enemyPlane::randomIntEnemy()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int n = qrand() % 7;    //随机数
    return  n;
}
