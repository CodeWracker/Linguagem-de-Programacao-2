#include "snake.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include <stdlib.h>
#include <iostream>
#include <QPointF >
using namespace std;
//#include "bullet.h"
//#include "enemy.h"

#include "food.h"
Snake::Snake(){{}}
Snake::Snake(string t)
{
    tipo = t;
    //
    isVivo = true;
    ready = false;
    BodyPart * p = new BodyPart();
    p->lastAction = "Left";
    QString image;
    if(tipo == "normal")
        image = "://images/NormalLeft.png";
    if(tipo == "boss")
        image = "://images/BossLeft.png";
    else
        image = "://images/PlayerLeft.png";
     p->setPixmap(QPixmap( image  ) );
     p->setPos(floor(32 * (rand()%20)) , floor(32 * (rand()%20)));
     myBody.push_back(p);



    /*
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Laser.mp3"));*/
}
void Snake::die(){
    cout << "Morri"<<endl;
    isVivo = false;
}
void Snake::move(string decisao)
{
    if(!ready) return;
    vector<string> ant;
    isVivo = myBody.at(0)->move(decisao);
    for (BodyPart* part: myBody){
        cout << part->pos().x() << ";" <<part->pos().y()<<"("<<part->lastAction<<")" << " - ";
    }
    cout << endl;
    for (size_t i = myBody.size()-1; i>0;i--){
          myBody.at(i)->setPos(myBody.at(i-1)->pos());

        }
    myBody.at(0)->lastAction = decisao;

    QList<QGraphicsItem *> colliding_item = myBody.at(0)->collidingItems();
    for(int i = 0, n = colliding_item.size(); i < n; i++){
        if(typeid(*(colliding_item[i])) == typeid(BodyPart)){
            bool achou = true;
            for (BodyPart* part: myBody){
                if(part == colliding_item[i]){
                    achou = false;
                }
            }
            if(achou)
                die();

            }

        }



}
void Snake::addNew(){
    string lastA = myBody.at(myBody.size()-1)->lastAction;
    QPointF lastP = myBody.at(myBody.size()-1)->pos();
    BodyPart* p = new BodyPart();
   QString image;
   if(tipo == "normal")
       image = "://images/NormalBody.png";
   if(tipo == "boss")
       image = "://images/BossBody.png";
   else
       image = "://images/PlayerBody.png";
    p->setPixmap(QPixmap( image  ) );
    //p->setRect(0,0,32,32);
    p->setPos(lastP);
    p->lastAction = lastA;
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    myBody.push_back(p);


}

