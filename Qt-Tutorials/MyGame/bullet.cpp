//#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include <QTimer>
#include <QDebug>
#include <QList>
#include "bullet.h"
#include "game.h"
#include "enemy.h"
// declaração da variavel do tipo extern
// indica que essa variavel já foi declarada em algum outro arquivo do projeto
extern Game * game;
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
     // desenhar o tiro
     // desenhar o tiro
     //setRect(0,0,10,50);
     setPixmap(QPixmap("://images/laserRed.png"));
     // conectar o timer com o movimento
     QTimer * timer = new QTimer();
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     // inicializar o timer
     timer->start(50);
 }
void Bullet::move()
{
    // verificação de colisão:
     // se tiro atingiu o nimigo
     QList<QGraphicsItem *> colliding_item = collidingItems();
     for(int i = 0, n = colliding_item.size(); i < n; i++)
     {
     if(typeid(*(colliding_item[i]))== typeid(Enemy))
     {
     game->score->increase();
     scene()->removeItem(colliding_item[i]);
     scene()->removeItem(this);
     delete colliding_item[i];
     delete this;
     return;
     }
     }

     // movimentação do tiro
     setPos(x(),y()-10);
     if(pos().y() < -10)
     {
     scene()->removeItem(this);
     delete this;
     qDebug()<<"Bullet removed";
     }
}

