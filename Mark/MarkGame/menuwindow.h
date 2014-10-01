#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QGraphicsView>
#include <QFont>
#include <QKeyEvent>

#define SKIPKEY 4

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
    void skipAllow();
    void skipCheck(bool check);
    void idLogin();
    void startGame();
};

#endif // MENUWINDOW_H
