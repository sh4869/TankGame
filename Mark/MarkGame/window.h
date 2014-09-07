#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE
class GameArea;

class Window : public QWidget{
  Q_OBJECT

  public:
	Window();

  private:
    GameArea *gameArea;
};

#endif 

