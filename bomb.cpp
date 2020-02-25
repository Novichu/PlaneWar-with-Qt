#include "bomb.h"

Bomb::Bomb()
{
    for (int i=1;i<8;i++) {
        QString str=QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }
    m_X=0;
    m_Y=0;
    m_Free=true;
    m_index=0;
    m_recorder=0;
}

void Bomb::updateInfo()
{
    if(m_Free)
    {
        return;
    }
    m_recorder++;
    //没用完不能切换
    if(m_recorder<BOMB_INTERVAL)
    {
        return;
    }
    m_recorder=0;
    m_index++;
    if(m_index>BOMB_MAX-1)
    {
        m_index=0;
        m_Free=true;
    }
}
