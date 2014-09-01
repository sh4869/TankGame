#include <QtWidgets>
#include <QPainter>
#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
: QWidget(parent)
{
  QLabel *namelabel = new QLabel(tr("Name:"));
  nameline = new QLineEdit;

  QLabel *gameLabel = new QLabel(tr("Game:"));
  gameText = new QTextEdit;

  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(namelabel,0,0);
  mainLayout->addWidget(nameline,0,1);
  mainLayout->addWidget(gameLabel,1,0,Qt::AlignTop);
  mainLayout->addWidget(gameText,1,1);

  setLayout(mainLayout);
  setWindowTitle(tr("Simple na nanika"));
}
