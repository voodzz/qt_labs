#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QColor>
#include <QGraphicsScene>
#include <QStack>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_colorsButton_clicked();

    void on_openAction_triggered();

    void on_newAction_triggered();

    void on_blackButton_clicked();

    void on_firstColorButton_clicked();

    void on_secondColorButton_clicked();

    void on_greyButton_clicked();

    void on_darkRedButton_clicked();

    void on_redButton_clicked();

    void on_orangeButton_clicked();

    void on_yellowButton_clicked();

    void on_greenButton_clicked();

    void on_blueButton_clicked();

    void on_indigoButton_clicked();

    void on_purpleButton_clicked();

    void on_saveAsAction_triggered();

    void on_saveAction_triggered();

    void on_actionUndo_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;
    QString currentFile_;
    QStack<QImage> undoStack_;
    QStack<QImage> redoStack_;
};
#endif // MAINWINDOW_H
