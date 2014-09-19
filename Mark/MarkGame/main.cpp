#include "markgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    markgame w;
    w.show();

    return a.exec();
}
