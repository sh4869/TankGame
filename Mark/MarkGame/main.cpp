#include "markgame.h"
#include "scorewindow.h"
#include "menuwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	/*    
    Markgame *markgame = new Markgame();
	markgame->move(0 , 0);//
	markgame->resize(1024 , 768);//
    markgame->show();
    */	
    /*
    ScoreWindow *scoreWindow = new ScoreWindow();
	scoreWindow->move(0,0);
	scoreWindow->resize(1024,768);
    scoreWindow->show();
    */
    MenuWindow *menuWindow = new MenuWindow();
    menuWindow->show();
    return a.exec();
}
