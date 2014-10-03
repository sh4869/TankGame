#include "gamemainwindow.h"
#include <QMainWindow>
#include <QtWidgets>
#include <QPixmap>
#include <QMediaPlaylist>

GameMainWindow::GameMainWindow() : QMainWindow(0)
{
    setMusic();
    setMenu();
}

void GameMainWindow::setMusic(){
    menuMusic = new QMediaPlayer();
    menuplaylist = new QMediaPlaylist();
    menuplaylist->addMedia(QUrl("qrc:///material/menu.mp3"));
    menuMusic->setPlaylist(menuplaylist);
    menuplaylist->setCurrentIndex(0);

    gameMusic = new QMediaPlayer();
    gameplaylist = new QMediaPlaylist();
    gameplaylist->addMedia(QUrl("qrc:///material/game.mp3"));
    gameMusic->setPlaylist(gameplaylist);
    gameMusic->setVolume(15);
    gameplaylist->setCurrentIndex(0);

    scoreMusic = new QMediaPlayer();
    scoreplaylist = new QMediaPlaylist();
    scoreplaylist->addMedia(QUrl("qrc:///material/score.mp3"));
    scoreMusic->setPlaylist(scoreplaylist);
    scoreplaylist->setCurrentIndex(0);
}

void GameMainWindow::setGameWindow(){
    menuMusic->stop();
    gameMusic->play();
    markgame = new Markgame();
    QObject::connect(markgame,SIGNAL(finishGame()),this,SLOT(showResult()));
    setCentralWidget(markgame);
    markgame->startgame();
    keymode = GAMEKEY;
    fprintf(stderr,"GAME\n");
}

void GameMainWindow::showResult(){
    gameMusic->stop();
    scoreMusic->play();
    scoreWindow = new ScoreWindow();
    setCentralWidget(scoreWindow);
    fprintf(stderr,"Score\n");
    scoreWindow->changeScore(markgame->score);
    keymode = SCOREKEY;
    markgame->score = 0;
}

void GameMainWindow::setMenu(){
    scoreMusic->stop();
    menuMusic->play();
    keymode = MENUKEY;
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(":/material/menu.png"));
    fprintf(stderr,"Menu\n");
    setCentralWidget(imageLabel);
    this->resize(1024,768);
}

void GameMainWindow::keyPressEvent(QKeyEvent *event){
    switch(keymode){

    /* MenuWindow Keyboard Focus*/
    case MENUKEY:
        if(event->key() == Qt::Key_C){
            setGameWindow();
        }
        break;
    case GAMEKEY:
        if(event->key() > 64 && event->key() < 71){
            fprintf(stderr,"%d",event->key());
            markgame->hitBall(event->key() - 63);
        }else if(event->key() == Qt::Key_Asterisk){
            markgame->gamefinish();
        }
        break;
    case SCOREKEY:
        if(event->key() == Qt::Key_Space){
            setMenu();
        }
        break;
    case SKIPKEY:
        if(event->key() == Qt::Key_Enter){
            menuWindow->skipCheck(true);
        }else if(event->key() == Qt::Key_Backspace){
            menuWindow->skipCheck(false);
            keymode = MENUKEY;
        }
        break;
    }
}
