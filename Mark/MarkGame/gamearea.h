#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QPixmap>
#include <QWidget>

class GameArea : public QWidget{
  Q_OBJECT

  public:
	GameArea(QWidget *parent = 0);

	QSize minimumSizeHint() const;
	QSize sizeHint() const;
  
  protected:
	void paintEvent(QPaintEvent *event);
  private:
	QPixmap pixmap;
};

#endif
