#include <QPropertyAnimation>
#include <QWidget>

class MarkGamePrivate{
  public:
	MarkGamePrivate()
	  :movingAreaSize(QSize(1000,856)),horizontalOffset(8){
	  }
	QSize movingAreaSize;
	int horizontalOffset;
};
