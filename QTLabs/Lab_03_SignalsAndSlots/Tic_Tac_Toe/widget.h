#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent* event);

private:
    Ui::Widget *ui;
    void setInterfaceStyle();
    void changeButtonStatus(int num);
    void changeButtonStyle(int row, int column, QString style);
    void configurateGameAreaButtons();
    void setGameAreaButtonStyle();
    void setWinLossSquareStyle(int row, int column, char symbol);
    void start();
    void lockPlayer();
    void computerInGame();
    void checkGameStop();
    void endGame();
    char gameArea[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    char player = '0'; //  either X or 0
    int progress = 0; // the amount of moves
    bool gameStarted = false;
    bool playerLocked = true;
    QTimer* timer;
    bool stop;
    char winner;

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_startButton_clicked();
    void onGameAreaButtonClicked();
    void onComputerSlot();
};
#endif // WIDGET_H
