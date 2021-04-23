#include "gameenv.h"

#include <stdlib.h>
#include <QGraphicsTextItem>
#include <QMediaPlaylist>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>

#include <QKeyEvent>
void GameEnv::clean(){
    // criar scene
    //if(scene)
     scene = new QGraphicsScene();
     // fixar o tamanho em 800x600, que é infinito por definição
     scene->setSceneRect(0, 0, 704, 704);
     setScene(scene);
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     // fixar o tamanho
     setFixedSize(704, 704);
}
void GameEnv::keyPressEvent(QKeyEvent *event)
{
    string dec;
    if (event->key() == Qt::Key_Left)
    {
        // limite para não sair da tela
        dec = "Left";
    }
    else if (event->key() == Qt::Key_Right)
    {
        dec = "Right";
    }
    else if (event->key() == Qt::Key_Up)
    {
        dec = "Up";
    }
    else if (event->key() == Qt::Key_Down)
    {
        dec = "Down";
    }
    if(dec != player->myBody.at(0)->lastAction)
        player->move(dec);
}
GameEnv::GameEnv(QWidget *parent)
{

    ready = false;
    timer = new QTimer();
    clean();
    musicBg = new QMediaPlayer(this);
    scene->setBackgroundBrush(QBrush(QImage("://images/GameBackground.png")));
    player = new Snake();
    enemy = new Snake();
    rodada = 0;
    tipo = { "Normal", "Normal", "Boss" };
    state.food.push_back(new Food());
    state.food.push_back(new Food());
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::movePlayer,this,""));
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::newGame,this,""));
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::agent,this,state,inimigoAgent));
}
void GameEnv::newGame(string a){
    player->ready = ready;
    enemy->ready = ready;
    refresh();
    if((player->isVivo && !enemy->isVivo))
    {
        cout << "Novo Jogo"<<endl;
        QMediaPlayer * music = new QMediaPlayer(this);
        music->setMedia(QUrl("qrc:/GameWin.wav"));
        music->play();
        rodada++;
        gameExecution(rodada);
        return;
    }
    if(!player->isVivo) {
        ready = false;
        QMediaPlayer * music = new QMediaPlayer(this);
        music->setMedia(QUrl("qrc:/GameOver.wav"));
        music->play();
        timer->stop();
        hide();
        return;
    }
    for(size_t j = 0; j<state.food.size();j++){
        QList<QGraphicsItem *> colliding_item = state.food.at(j)->collidingItems();
        for(int i = 0; i< colliding_item.size(); i++){
            if(typeid (*(colliding_item[i])) == typeid(BodyPart)){
                delete state.food.at(j);
                QMediaPlayer * music = new QMediaPlayer(this);
                music->setMedia(QUrl("qrc:/Eat.wav"));
                music->play();
                state.food.at(j) = new Food();
                bool achou = false;
                for(BodyPart* part : player->myBody){
                    if(part == colliding_item[i]) achou = true;
                }
                if(achou) player->addNew();
                else enemy->addNew();
            }
        }
    }






    refresh();

}
void GameEnv::refresh(){

    QList<QGraphicsItem *>  tel = scene->items();
    for(Food* foo : state.food){
        bool achou = false;
        for (QGraphicsItem* i : tel){
            if(foo == i) achou = true;
        }
        if(!achou)
        scene->addItem(foo);
    }
    for(BodyPart* part: player->myBody){
        bool achou = false;
        for (QGraphicsItem* i : tel){
            if(part == i) achou = true;
        }
        if(!achou)
        scene->addItem(part);
    }
    for(BodyPart* part: enemy->myBody){
        bool achou = false;
        for (QGraphicsItem* i : tel){
            if(part == i) achou = true;
        }
        if(!achou)
        scene->addItem(part);
    }
}
void GameEnv::gameExecution(int r){
    ready = false;

    rodada = r;
    delete player;
    delete enemy;
    player = new Snake("Player");
    inimigoAgent = tipo.at(rodada%3);
    enemy = new Snake(inimigoAgent);
    refresh();
    //clean();
    delete musicBg;
    musicBg = new QMediaPlayer(this);
    musicBg->setMedia(QUrl("qrc:/Game"+inimigoAgent+".mp3"));
    musicBg->play();
    gameExecution();
}
void GameEnv::gameExecution()
{


     // adicionar o jogador no cenario
     // criar inimigos


     timer->start(250);

     //QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

     show();

}
