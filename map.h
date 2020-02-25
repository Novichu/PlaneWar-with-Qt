#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class Map
{
public:
    Map();

    //初始化地图
    QPixmap m_map1;
    QPixmap m_map2;

    int m_map1_posY;
    int m_map2_posY;
    int m_scroll_speed;
    void mapPosition();
    int randomInt();
};

#endif // MAP_H
