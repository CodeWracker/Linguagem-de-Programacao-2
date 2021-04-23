#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include "food.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QString>
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
     vector<QString> tipo;
     QString inimigoAgent;
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
     void agent(Estado estado,QString inimigo){
         cout << "AAA"<<endl;
         cout << inimigoAgent.toStdString()<<endl;
         if(ready){

             if(inimigoAgent == "Normal"){
                 agentNormal(state);
             }else{
                 agentBoss(state);
             }
         }
     }
     void agentNormal( Estado estado){

         if(estado.food.at(0)->y() > enemy->myBody.at(0)->y()){
             enemy->move("Down");
             return;
         }else{
             if(estado.food.at(0)->y() < enemy->myBody.at(0)->y()){
                enemy->move("Up");
                return;
             }
             else{
                 if(estado.food.at(0)->x() > enemy->myBody.at(0)->x()){
                    enemy->move("Right");
                    return;
                 }
             }
         }
         enemy->move("Left");
     }
     void agentBoss( Estado estado){
         cout <<"Enemy"<<endl;
         enemy->move("Up");
     }

};

#endif // GAME_H
