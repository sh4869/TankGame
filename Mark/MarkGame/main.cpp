#include "markgame.h"

#include <QApplication>

int main(int argc,char *argv[]){
  Q_INIT_RESOURCE(markgame);

  QApplication app(argc,argv);
  MarkGame *markgame = new MarkGame();
  markgame->show();
  return app.exec();
}
