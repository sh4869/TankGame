#include "markgame.h"
#include "scorewindow.h"
#include "menuwindow.h"
#include "gamemainwindow.h"
#include <QApplication>
#include <QSql>
#include <QtSql>
#include <QtSql/QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameMainWindow *mainWindow = new GameMainWindow();
    mainWindow->show();

    return a.exec();


}
