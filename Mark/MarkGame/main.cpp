#include "window.h"

#include <QApplication>

int main(int argc,char *argv[]){
  Q_INIT_RESOURCE(markgame);

  QApplication app(argc,argv);
  Window window;
  window.show();
  return app.exec();
}
