#include "markgame.h"
#include "menu.h"
#include "scorewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    Markgame *markgame = new Markgame();
	markgame->move(0 , 0);//
	markgame->resize(1024 , 768);//
    markgame->show();

    Menu *menu = new Menu();
    menu->show();
    */
    ScoreWindow *scoreWindow = new ScoreWindow();
    scoreWindow->show();

    return a.exec();
}
