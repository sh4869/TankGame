#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QKeyEvent>
#include "menuwindow.h"
#include "markgame.h"
#include "scorewindow.h"

#define MENUKEY 0
#define GAMEKEY 1
#define SCOREKEY 2
#define SKIPKEY 4

class GameMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameMainWindow();
    MenuWindow *menuWindow;
    Markgame *markgame;
    ScoreWindow *scoreWindow;

private slots:
    void setGameWindow();
    void showResult();

protected:
    void keyPressEvent(QKeyEvent *);

private:
    int keymode;
    void backMenu();
};

#endif // GAMEMAINWINDOW_H
