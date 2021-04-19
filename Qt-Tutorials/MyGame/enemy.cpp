#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "enemy.h"
#include "game.h"
extern Game * game;
Enemy::Enemy()
{
     // posição aleatoria
     int random_number = rand() % 700;
     setPos(random_number,0);
     // desenhar o inimigo
     //setRect(0,0,100,100);
      setPixmap(QPixmap("://images/enemyShip.png"));

     //movimentação
     QTimer * timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this, SLOT(move()));
     timer->start(50);
}
void Enemy::move()
{
     setPos(x(),y()+5);
     if(pos().y() > 600)
     {
     scene()->removeItem(this);
     delete this;
     qDebug()<<"Enemy removed";
     game->health->decrease();
     }
}
