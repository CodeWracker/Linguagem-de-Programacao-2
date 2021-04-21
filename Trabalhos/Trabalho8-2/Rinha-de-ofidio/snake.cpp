#include "snake.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
//#include "bullet.h"
//#include "enemy.h"

Snake::Snake(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    //setPixmap(QPixmap("://images/player.png"));
    isVivo = true;
    ready = false;
    lastMove = "Left";
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
    lastMove = decisao;
 //cout << pos().x()<<" // "<<pos().y()<<endl;
    if (decisao == "Left")
     {
     // limite para não sair da tela
         if(pos().x()-10 > 32)
            setPos(x()-10,y());
         else{
             setPos(32,y());
             die();
         }
      }
     if (decisao == "Right")
     {
     // limite para não sair da tela
         if(pos().x() + 10 < (800-32) )
            setPos(x()+10,y());
         else{
             setPos((800-32),y());
             die();
         }
     }
     if (decisao == "Up")
     {
         if(pos().y()-10>32)
            setPos(x(),y()-10);
         else{
             setPos(x(),32);
             die();
         }
     }
      if (decisao == "Down")
     {
          if(pos().y()+10<(600-32))
            setPos(x(),y()+10);
          else{
              setPos(x(),(600-32));
              die();
          }
     }



}
void Snake::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        // limite para não sair da tela
        this->move("Left");
    }
    else if (event->key() == Qt::Key_Right)
    {
        // limite para não sair da tela
        this->move("Right");
    }
    else if (event->key() == Qt::Key_Up)
    {
        this->move("Up");
    }
    else if (event->key() == Qt::Key_Down)
    {
        this->move("Down");
    }
}
