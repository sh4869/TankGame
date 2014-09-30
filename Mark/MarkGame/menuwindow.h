#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QGraphicsView>
#include <QFont>

class MenuWindow : public QWidget
{
public:
    MenuWindow();
    QGraphicsScene *menuScene;
    QGraphicsTextItem *inputidStr;
    QGraphicsPixmapItem *skkipAllowImage;
    QGraphicsPixmapItem *idSuccessImage;
    QGraphicsPixmapItem *iderrorImage;
    QFont idfont;
    int keymode;
    void startLogin();

private:
    bool idLogincheck(int id);
    void skippAllow();
    void idLogin();
    void startGame();
};

#endif // MENUWINDOW_H
