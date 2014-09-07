#include "gamearea.h"

#include <QPainter>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

QSize GameArea::minimumSizeHint() const
{
  return QSize(100,100);
}

QSize GameArea::sizeHint() const
{
  return QSize(400,400);
}

