#include "markgame.h"
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Markgame *markgame = new Markgame();
    markgame->show();
    /*
    Menu *menu = new Menu();
    menu->show();
    */
    return a.exec();
}
