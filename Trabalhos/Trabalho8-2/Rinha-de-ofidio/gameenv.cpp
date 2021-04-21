#include "gameenv.h"

#include <stdlib.h>
#include <QGraphicsTextItem>
#include <QMediaPlaylist>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>
void GameEnv::clean(){
    // criar scene
    //if(scene)
     scene = new QGraphicsScene();
     // fixar o tamanho em 800x600, que é infinito por definição
     scene->setSceneRect(0, 0, 900, 700);
     //scene->setBackgroundBrush(QBrush(QImage("://images/starBackground.png")));
     // visualizar o objeto scene (cenario)
     setScene(scene);
     //desabilitar as barras de rolagem
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     // fixar o tamanho
     setFixedSize(900, 700);
}
GameEnv::GameEnv(QWidget *parent)
{
    ready = false;
    timer = new QTimer();
    clean();
    player = new Snake();
    enemy = new Snake();
    rodada = 0;
    tipo = { "nomal", "nomal", "nomal", "boss" };

    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(move()));
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::newGame,this,""));
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::agent,this,state,inimigoA));
}
void GameEnv::newGame(string a){
    player->ready = ready;
    enemy->ready = ready;
    if((player->isVivo && !enemy->isVivo)|| rodada == 0)
    {
        cout << "Novo Jogo"<<endl;
        player->reset();
        enemy->reset();

        //delete scene;
         //clean();

        // definir o tamanho do jogador 100 x 100
        player->setRect(0,0,50,50);
        enemy->setRect(0,0,100,100);
        // definir a posição padrão do jogador para ser em baixo da tela
        // por definição a visualização é centralizada para pegar todos os objetos

        player->setPos(rand() % 600 + 32 , rand() % 500 + 32);

        enemy->setPos(rand() % 600 + 32 , rand() % 500 + 32);

        // colocar o foco no jogador
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        inimigoA = tipo.at(rodada%3);
        rodada++;
        ready = false;
    }
    if(!player->isVivo) {
        ready = false;
        timer->stop();
        hide();
    }
}
void GameEnv::gameExecution(int r){
    ready = false;
    rodada = r;
    player->reset();
    enemy->reset();
    //clean();
    scene->addItem(enemy);
    scene->addItem(player);
    gameExecution();
}
void GameEnv::gameExecution()
{


     // adicionar o jogador no cenario
     // criar inimigos


     timer->start(50);

     //QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

     show();

}
