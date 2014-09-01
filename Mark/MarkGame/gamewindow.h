#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include<QtWidgets>
#include<QPainter>

class QLabel;
class QLineEdit;
class QTextEdit;

class GameWindow : public QWidget{
  Q_OBJECT
  public:
	GameWindow(QWidget *parent = 0);
  private:
	QLineEdit *nameline;
	QTextEdit *gameText;
};

#endif
