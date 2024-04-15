#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QColor>
#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MainWindow(const MainWindow& other) = delete;
    MainWindow& operator =(const MainWindow& other) = delete;
    MainWindow(MainWindow&& other) = delete;
    MainWindow& operator =(MainWindow&& other) = delete;

    void dotsColorInitialization();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;
    int dots_;
    QVector<QVector<QColor>> plazma_;
    void fillPlazma(int x1, int y1, int x2, int y2);
};

#endif // MAINWINDOW_H
