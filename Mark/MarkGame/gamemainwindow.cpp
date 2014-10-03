#include "gamemainwindow.h"
#include <QMainWindow>

GameMainWindow::GameMainWindow() : QMainWindow(0)
{
    /*
    keymode = MENUKEY;
    menuWindow = new MenuWindow();
    markgame = new Markgame();
    setCentralWidget(menuWindow);
    QObject::connect(menuWindow,SIGNAL(startGame()),this,SLOT(setGameWindow()));
    */
    setMenu();
}

void GameMainWindow::setGameWindow(){
    markgame = new Markgame();
    QObject::connect(markgame,SIGNAL(finishGame()),this,SLOT(showResult()));
    setCentralWidget(markgame);
    markgame->startgame(menuWindow->idNum);
    keymode = GAMEKEY;
}

void GameMainWindow::showResult(){
    scoreWindow = new ScoreWindow();
    setCentralWidget(scoreWindow);
    scoreWindow->changeScore(markgame->score,markgame->id);
    keymode = SCOREKEY;
    markgame->score = 0;
    markgame->id = 0;
}

void GameMainWindow::setMenu(){
    keymode = MENUKEY;
    menuWindow = new MenuWindow();
    //menuWindow->resetMenu();
    fprintf(stderr,"Menu\n");
    QObject::connect(menuWindow,SIGNAL(startGame()),this,SLOT(setGameWindow()));
    setCentralWidget(menuWindow);
}

void GameMainWindow::keyPressEvent(QKeyEvent *event){
    switch(keymode){

    /* MenuWindow Keyboard Focus*/
    case MENUKEY:
        if(event->key() >  0x29 && event->key() < 0x40){
            menuWindow->addLoginNum(event->key() - 0x30);
            fprintf(stderr,"%d",event->key());
        }
        switch(event->key()){
        case Qt::Key_Plus:
            menuWindow->skipAllow();
            keymode = SKIPKEY;
            break;
        case Qt::Key_Backspace:
            menuWindow->addLoginNum(-1);
            break;
        case Qt::Key_Enter:
            menuWindow->idLogin();
            break;
        }
        break;
    case GAMEKEY:
        if(event->key() > 0x29 && event->key() < 0x37){
            markgame->hitBall(event->key() - 0x30);
        }else if(event->key() == Qt::Key_Minus){
            markgame->gamefinish();
        }
        break;
    case SCOREKEY:
        if(event->key() == Qt::Key_Enter){
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
