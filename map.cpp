#include "map.h"
#include"config.h"
#include<QTime>
Map::Map()
{
    QString str=":/res/img_bg_level_"+QString::number(randomInt()+1,10)+".jpg";
    m_map1.load(str);
    m_map2.load(str);

    m_map1_posY=-GAME_HEIGHT;
    m_map2_posY=0;
    //地图滚动
    m_scroll_speed =GAME_SCROLL_SPEED;
}

void Map::mapPosition()
{
    m_map1_posY +=m_scroll_speed;
    if(m_map1_posY>=0)
    {
        m_map1_posY=-GAME_HEIGHT;
    }
    m_map2_posY+=m_scroll_speed;
    if(m_map2_posY>=GAME_HEIGHT)
    {
        m_map2_posY=0;
    }
}

int Map::randomInt()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int n = qrand() % 5;    //随机数
    return  n;
}
