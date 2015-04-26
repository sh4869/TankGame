#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QGraphicsView>
#include <QFont>
#include <QKeyEvent>

#define SKIPKEY 4
#define NOMKEY 0

class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    MenuWindow();
    QGraphicsScene *menuScene;
    QGraphicsTextItem *inputidStr;
    QGraphicsPixmapItem *skipAllowImage;
    QGraphicsPixmapItem *successImage;
    QGraphicsPixmapItem *errorImage;
    QTimer *errorDeleteTimer;

    QFont idfont;
    QString idStr;
    int keymode,ver;
    void addLoginNum(int num);
    void skipAllow();
    void skipCheck(bool check);
    void idLogin();
    void resetMenu();
    int idNums[6];
    int idNum;
    bool ableInput;

protected:
    void keyPressEvent(QKeyEvent *);

signals:
    void startGame();

private:
    bool idCheck();

private slots:
    void errorDelete();
};

#endif // MENUWINDOW_H
