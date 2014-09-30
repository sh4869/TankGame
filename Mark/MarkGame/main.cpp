#include "markgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Markgame *markgame = new Markgame();
	markgame->move(0 , 0);//
	markgame->resize(1024 , 768);//
    markgame->show();

    return a.exec();
}
