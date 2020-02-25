#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QTimer>
#include"map.h"
#include"heroplane.h"
#include"bullet.h"
#include"enemyplane.h"
#include"bomb.h"
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();
    QTimer m_Timer;//定时器
    void initScene();
    void playGame();
    void updatePosition();

    void paintEvent(QPaintEvent *);//绘制
    void mouseMoveEvent(QMouseEvent *);
    Map m_map;
    HeroPlane m_hero;
    //敌机
    enemyPlane m_enemys[ENEMY_MUN];
    void enemyToScene();
    int m_enemyRecorder;
    int randomIntX();//
    //
    void collisonDetection();
    //
    Bomb m_bombs[BOMB_NUM];
//    Bullet temp_Bullet;
    //

};

#endif // MAINSCENE_H
