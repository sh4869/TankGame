#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QGraphicsView>
#include <QFont>
#include <QKeyEvent>

#define SKIPKEY 4
#define NOMKEY 0
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
    QString idStr;
    int keymode,ver;
    void addLoginNum(int num);
    int idNums[6];
    bool ableInput;

protected:
    void keyPressEvent(QKeyEvent *);

private:
    bool idLogincheck(int id);
    void skipAllow();
    void skipCheck(bool check);
    void idLogin();
    void startGame();
    bool idCheck();
};

#endif // MENUWINDOW_H
