#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class Window : public QWidget{
  Q_OBJECT

public:
	Window();

private:
	QLabel *testLabel;
};

#endif 

