#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include "food.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include <iostream>
using namespace std;

class Estado{
public:
    Estado(){};
    ~Estado(){}
    vector<Food*> food;

};

class GameEnv: public QGraphicsView
{
public:
    GameEnv(QWidget *parent = 0);
     QGraphicsScene *scene;
     void clean();
public:
     void gameExecution();
     void gameExecution(int r);
     void newGame(string a);
     Snake *player;
     Snake *enemy;
     Estado state;
     vector<string> tipo;
     string inimigoA;
     int rodada;
     QTimer *timer;
     bool ready;
     void refresh();
     void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event){
        if(ready) player->addNew();
        ready = true;

    }
     /*int state = {
               "Food" : [ 0, 1 ];
                "Player" : [ [ 1, 1 ], [ 1, 2 ] ],
                "Enemy" : [ [ 0, 0 ], [ 1, 0 ] ]
            }*/
public :
    void movePlayer(string a){
        player->move();
    }
     void agent(Estado estado,string inimigo){
         if(ready){
             if(inimigo == "Nomal"){
                 agentNormal(estado);
             }else{
                 agentBoss(estado);
             }
         }
     }
     void agentNormal( Estado estado){
         //cout <<"Enemy"<<endl;
         enemy->move("Up");
     }
     void agentBoss( Estado estado){
         //cout <<"Enemy"<<endl;
         enemy->move("Up");
     }

};

#endif // GAME_H
