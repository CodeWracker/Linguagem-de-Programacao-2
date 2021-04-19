#include <QGraphicsTextItem>
#include <QMediaPlaylist>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>
#include "game.h"
#include "enemy.h"

Menu()
{
     GameEnv a = new GameEnv;
     int i = 0;
     vector<string> tipo = [ "nomal", "nomal", "nomal", "boss" ] while (a.gameExecution(tipo.at(i % 3)) == 0)
     {
          i++;
     }
     GameOver.show()
         i = 13
}

void agentNormal(jogador, estado){
    //verifica o estado e toma a decisão
    decisao = "Left" jogador.move(decisao)

} Game::GameEnv(QWidget *parent)
{
     // criar scene
     scene = new QGraphicsScene();
     // fixar o tamanho em 800x600, que é infinito por definição
     scene->setSceneRect(0, 0, 800, 600);
     scene->setBackgroundBrush(QBrush(QImage("://images/starBackground.png")));
     // visualizar o objeto scene (cenario)
     setScene(scene);
     //desabilitar as barras de rolagem
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     // fixar o tamanho
     setFixedSize(800, 600);
     // criar o jogador
}

int GameEnv::gameExecution(string inimigo)
{
     player = new Player();
     enemy = new Player();
     // definir o tamanho do jogador 100 x 100
     //player->setRect(0,0,100,100);
     // definir a posição padrão do jogador para ser em baixo da tela
     // por definição a visualização é centralizada para pegar todos os objetos
     player->setPos(400, 500);
     // colocar o foco no jogador
     player->setFlag(QGraphicsItem::ItemIsFocusable);
     player->setFocus();
     // adicionar o jogador no cenario
     scene->addItem(player);
     // criar inimigos
     QTimer *timer = new QTimer();
     if ("nomal")
     {
          QObject::connect(timer, SIGNAL(timeout()), player, SLOT(agentNormal(enemy, state)));
     }
     else
     {
          QObject::connect(timer, SIGNAL(timeout()), player, SLOT(agentBoss(enemy, state)));
     }
     QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
     timer->start(500);
     show();
     while (player.isVivo && enemy.isVivo)
     {
     }

     if (player.isVivo)
          return 0 return 1
}
