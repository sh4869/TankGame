#include <QPropertyAnimation>
#include <QWidget>

class MarkgamePrivate
{
public:
  MarkgamePrivate()//1024 768//1580 856
    :movingAreaSize(QSize(1024,768)),horizontalOffset(8){
  }

  QSize movingAreaSize;
  int horizontalOffset;
  QParallelAnimationGroup* ImageAnimationGroup;
};
