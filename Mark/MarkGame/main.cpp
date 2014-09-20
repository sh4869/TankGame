#include "markgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Markgame *markgame = new Markgame();
    markgame->show();

    return a.exec();
}
