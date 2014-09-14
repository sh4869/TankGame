#include "markgame.h"

#include <QApplication>

int main(int argc,char *argv[]){
  Q_INIT_RESOURCE(markgame);

  QApplication app(argc,argv);
  GameArea gamearea;
  gamearea.show();
  return app.exec();
}
