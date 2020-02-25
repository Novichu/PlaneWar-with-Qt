#include "mainscene.h"
#include"config.h"
#include<QIcon>
#include<QPainter>
#include<QMouseEvent>
#include<QTime>
#include <QDebug>
#include<QSound>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    playGame();
    this->setMouseTracking(true);//设置自动跟随鼠标
    m_enemyRecorder=0;
}

MainScene::~MainScene()
{

}
void MainScene::initScene()
{
    //窗口修改
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(":/res/app.ico"));
    //定时器
    m_Timer.setInterval(GAME_RATE);

}

void MainScene::playGame()
{
    QSound::play(BACKGROUD);
    m_Timer.start();

    connect(&m_Timer,&QTimer::timeout,[=](){
        //enemy
        enemyToScene();
        //更新坐标
        updatePosition();
        //绘制
        update();
        //碰撞
        collisonDetection();
    });

}

void MainScene::updatePosition()
{
    m_map.mapPosition();//地图刷新
    //子弹
    m_hero.shoot();
    for (int i=0;i<BULLET_NUM;i++) {
        if(!m_hero.m_bullets[i].m_Free)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }
//    temp_Bullet.m_Free=false;
//    temp_Bullet.updatePosition();
    //敌机随机出现
    for (int i=0;i<ENEMY_MUN;i++) {
        if(!m_enemys[i].m_Free)
        {
            m_enemys[i].updatePosition();
        }
    }
    //bomb
    for (int i=0;i<BOMB_NUM;) {
        if(!m_bombs[i].m_Free)
        {
            m_bombs[i].updateInfo();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
    //绘制子弹

    for (int i=0;i<BULLET_NUM;i++) {
        if(!m_hero.m_bullets[i].m_Free)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }
    }
    //    painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);
    //绘制敌机
    for (int i=0;i<ENEMY_MUN;i++) {
        if(!m_enemys[i].m_Free)
        {
           painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);

        }
    }
    //bomb
    for (int i=0;i<BOMB_NUM;) {
        if(!m_bombs[i].m_Free)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{

    int x=event->x()-m_hero.m_Rect.width()/2;
    int y=event->y()-m_hero.m_Rect.height()/2;

    if(x<=0)
    {
        x=0;
    }
    if(x>=GAME_WIDTH-m_hero.m_Rect.width())
    {
        x=GAME_WIDTH-m_hero.m_Rect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=GAME_HEIGHT-m_hero.m_Rect.height())
    {
        y=GAME_HEIGHT-m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);

}

void MainScene::enemyToScene()
{
    m_enemyRecorder++;
    if(m_enemyRecorder<ENEMY_INTERVAL)
    {

        return;//未被收回

    }
    m_enemyRecorder=0;

    for (int i=0;i<ENEMY_MUN;i++) {
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free=false;
            m_enemys[i].m_X=randomIntX()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y=-m_enemys[i].m_Rect.height();
            break;
        }
    }

}

int MainScene::randomIntX()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
      //随机数
    return  qrand();
}

void MainScene::collisonDetection()
{
    for (int i=0;i<ENEMY_MUN;i++) {
        if(m_enemys[i].m_Free)
        {
            continue;
        }
        for (int j=0;j<BULLET_NUM;j++) {
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free=m_hero.m_bullets[j].m_Free=true;

                for (int k=0;k<BOMB_NUM;k++) {
                    if(m_bombs[k].m_Free)
                    {
                        QSound::play(BOMBSOUND);
                        m_bombs[k].m_Free=false;
                        m_bombs[k].m_X=m_enemys[i].m_X;
                        m_bombs[k].m_Y=m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }



}
