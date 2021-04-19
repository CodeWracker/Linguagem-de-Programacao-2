#include "player.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("://images/player.png"));
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Laser.mp3"));
}
void Player::move(String decisao)
{
    if (decisao == "Left")
    {
        if (pos().x() - 100 > 0)
            setPos(x() + 10, y());
    }
    if (decisao == "Right")
    {
        if (pos().x() - 100 > 0)
            setPos(x() + 10, y());
    }
    if (decisao == "Up")
    {
        if (pos().x() - 100 > 0)
            setPos(x() + 10, y());
    }
    if (decisao == "Down")
    {
        if (pos().x() - 100 > 0)
            setPos(x() + 10, y());
    }
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        // limite para não sair da tela
        this->move("Left")
    }
    else if (event->key() == Qt::Key_Right)
    {
        // limite para não sair da tela
        this->move("Right")
    }
    else if (event->key() == Qt::Key_Up)
    {
        this->move("Up")
    }
    else if (event->key() == Qt::Key_Down)
    {
        this->move("Down")
    }
}
