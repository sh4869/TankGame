#include<QtWidgets>
#include "gamewindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  GameWindow gamewindow;
  gamewindow.show(); 
  return app.exec();
}
