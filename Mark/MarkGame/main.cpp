#include "markgame.h"
#include "menu.h"
#include "scorewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    Markgame *markgame = new Markgame();
    markgame->show();

    Menu *menu = new Menu();
    menu->show();
    */
    ScoreWindow *scoreWindow = new ScoreWindow();
    scoreWindow->show();

    return a.exec();
}
