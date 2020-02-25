#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define GAME_TITLE "PlaneWar"
#define GAME_RES_PATH "./plane.rcc"
//==============飞机属性
#define GAME_SCROLL_SPEED 2
#define GAME_RATE 10
//==============子弹属性
#define BULLET_RATE 5
#define BULLET_NUM 30
#define BULLET_INTERVAL 20
//==============敌机属性
#define ENEMY_SPEED 5
#define ENEMY_MUN 20

#define ENEMY_INTERVAL 30
//==============爆炸
#define BOMB_PATH ":/res/bomb-%1.png"
#define BOMB_NUM 20
#define BOMB_MAX 7
#define BOMB_INTERVAL 20
//==============音效
#define BACKGROUD ":/res/bg.wav"
#define BOMBSOUND ":/res/bomb.wav"
#endif // CONFIG_H
