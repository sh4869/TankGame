#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QGraphicsView>
#include <QFont>
#include <QKeyEvent>

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
    void addLoginNum(int num);
    int idNum;

protected:
    void keyPressEvent(QKeyEvent *);

private:
    bool idLogincheck(int id);
    void skippAllow();
    void idLogin();
    void startGame();
};

#endif // MENUWINDOW_H
