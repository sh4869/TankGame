#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QtGui>
#include <QObject>

class MovableGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
   Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
  QTimeLine *timeline;
  MovableGraphicsPixmapItem( const QPixmap& pixmap,QGraphicsItem* parent = 0)
   : QObject(), QGraphicsPixmapItem(pixmap){
  timeline = new QTimeLine(200,this);
  }

private slots:
};
