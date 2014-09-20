#include <QPropertyAnimation>
#include <QWidget>

class MarkgamePrivate
{
public:
  MarkgamePrivate()
    :movingAreaSize(QSize(1580,856)),horizontalOffset(8){
  }

  QSize movingAreaSize;
  int horizontalOffset;
  QParallelAnimationGroup* ImageAnimationGroup;
};
