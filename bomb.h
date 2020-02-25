#ifndef BOMB_H
#define BOMB_H

#include"config.h"
#include<QPixmap>
#include<QVector>
class Bomb
{
public:
    Bomb();
    QVector<QPixmap>m_pixArr;
    int m_X;
    int m_Y;


    bool m_Free;
    int m_recorder;
    int m_index;
    void updateInfo();
};

#endif // BOMB_H
