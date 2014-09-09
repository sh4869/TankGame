#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QPixmap>
#include <QWidget>
#include <QTimer>

class GameArea : public QWidget{
  Q_OBJECT

  public:
	GameArea(QWidget *parent = 0);

	QSize minimumSizeHint() const;
	QSize sizeHint() const;
  public slots:
	void reloadAnimation();
  
  protected:
	void paintEvent(QPaintEvent *event);
  private:
	QPixmap kan;
	QPixmap taoreta;
	QPointF points[6];
	int pointnum;
};

#endif
