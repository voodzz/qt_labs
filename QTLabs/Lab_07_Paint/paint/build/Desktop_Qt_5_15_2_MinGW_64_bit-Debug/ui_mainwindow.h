/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_7;
    QPushButton *darkRedButton;
    QPushButton *firstColorButton;
    QPushButton *greenButton;
    QPushButton *purpleButton;
    QPushButton *indigoButton;
    QPushButton *greyButton;
    QPushButton *redButton;
    QPushButton *orangeButton;
    QLabel *label_3;
    QPushButton *blackButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *yellowButton;
    QPushButton *secondColorButton;
    QPushButton *blueButton;
    QGridLayout *gridLayout_6;
    QPushButton *rectangleButton;
    QPushButton *ellipseButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QGridLayout *gridLayout_5;
    QPushButton *dropperButton;
    QPushButton *fillButton;
    QPushButton *eraserButton;
    QPushButton *penButton;
    QPushButton *textButton;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuFile;
    QMenu *menuCLock;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1136, 640);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 500));

        gridLayout_2->addWidget(graphicsView, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        darkRedButton = new QPushButton(centralwidget);
        darkRedButton->setObjectName(QString::fromUtf8("darkRedButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(darkRedButton->sizePolicy().hasHeightForWidth());
        darkRedButton->setSizePolicy(sizePolicy1);
        darkRedButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(darkRedButton, 0, 4, 1, 1);

        firstColorButton = new QPushButton(centralwidget);
        firstColorButton->setObjectName(QString::fromUtf8("firstColorButton"));
        sizePolicy1.setHeightForWidth(firstColorButton->sizePolicy().hasHeightForWidth());
        firstColorButton->setSizePolicy(sizePolicy1);
        firstColorButton->setMaximumSize(QSize(80, 90));
        firstColorButton->setCheckable(true);

        gridLayout_7->addWidget(firstColorButton, 0, 0, 2, 1);

        greenButton = new QPushButton(centralwidget);
        greenButton->setObjectName(QString::fromUtf8("greenButton"));
        sizePolicy1.setHeightForWidth(greenButton->sizePolicy().hasHeightForWidth());
        greenButton->setSizePolicy(sizePolicy1);
        greenButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(greenButton, 1, 3, 1, 1);

        purpleButton = new QPushButton(centralwidget);
        purpleButton->setObjectName(QString::fromUtf8("purpleButton"));
        sizePolicy1.setHeightForWidth(purpleButton->sizePolicy().hasHeightForWidth());
        purpleButton->setSizePolicy(sizePolicy1);
        purpleButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(purpleButton, 1, 6, 1, 1);

        indigoButton = new QPushButton(centralwidget);
        indigoButton->setObjectName(QString::fromUtf8("indigoButton"));
        sizePolicy1.setHeightForWidth(indigoButton->sizePolicy().hasHeightForWidth());
        indigoButton->setSizePolicy(sizePolicy1);
        indigoButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(indigoButton, 1, 5, 1, 1);

        greyButton = new QPushButton(centralwidget);
        greyButton->setObjectName(QString::fromUtf8("greyButton"));
        sizePolicy1.setHeightForWidth(greyButton->sizePolicy().hasHeightForWidth());
        greyButton->setSizePolicy(sizePolicy1);
        greyButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(greyButton, 0, 3, 1, 1);

        redButton = new QPushButton(centralwidget);
        redButton->setObjectName(QString::fromUtf8("redButton"));
        sizePolicy1.setHeightForWidth(redButton->sizePolicy().hasHeightForWidth());
        redButton->setSizePolicy(sizePolicy1);
        redButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(redButton, 0, 5, 1, 1);

        orangeButton = new QPushButton(centralwidget);
        orangeButton->setObjectName(QString::fromUtf8("orangeButton"));
        sizePolicy1.setHeightForWidth(orangeButton->sizePolicy().hasHeightForWidth());
        orangeButton->setSizePolicy(sizePolicy1);
        orangeButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(orangeButton, 0, 6, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_3, 2, 0, 1, 7);

        blackButton = new QPushButton(centralwidget);
        blackButton->setObjectName(QString::fromUtf8("blackButton"));
        sizePolicy1.setHeightForWidth(blackButton->sizePolicy().hasHeightForWidth());
        blackButton->setSizePolicy(sizePolicy1);
        blackButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(blackButton, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 0, 7, 2, 1);

        yellowButton = new QPushButton(centralwidget);
        yellowButton->setObjectName(QString::fromUtf8("yellowButton"));
        sizePolicy1.setHeightForWidth(yellowButton->sizePolicy().hasHeightForWidth());
        yellowButton->setSizePolicy(sizePolicy1);
        yellowButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(yellowButton, 1, 2, 1, 1);

        secondColorButton = new QPushButton(centralwidget);
        secondColorButton->setObjectName(QString::fromUtf8("secondColorButton"));
        sizePolicy1.setHeightForWidth(secondColorButton->sizePolicy().hasHeightForWidth());
        secondColorButton->setSizePolicy(sizePolicy1);
        secondColorButton->setMaximumSize(QSize(80, 90));
        secondColorButton->setCheckable(true);

        gridLayout_7->addWidget(secondColorButton, 0, 1, 2, 1);

        blueButton = new QPushButton(centralwidget);
        blueButton->setObjectName(QString::fromUtf8("blueButton"));
        sizePolicy1.setHeightForWidth(blueButton->sizePolicy().hasHeightForWidth());
        blueButton->setSizePolicy(sizePolicy1);
        blueButton->setMaximumSize(QSize(45, 45));

        gridLayout_7->addWidget(blueButton, 1, 4, 1, 1);


        gridLayout->addLayout(gridLayout_7, 0, 2, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        rectangleButton = new QPushButton(centralwidget);
        rectangleButton->setObjectName(QString::fromUtf8("rectangleButton"));
        sizePolicy1.setHeightForWidth(rectangleButton->sizePolicy().hasHeightForWidth());
        rectangleButton->setSizePolicy(sizePolicy1);
        rectangleButton->setMinimumSize(QSize(30, 30));
        rectangleButton->setMaximumSize(QSize(45, 30));
        rectangleButton->setCheckable(true);

        gridLayout_6->addWidget(rectangleButton, 1, 1, 1, 1);

        ellipseButton = new QPushButton(centralwidget);
        ellipseButton->setObjectName(QString::fromUtf8("ellipseButton"));
        sizePolicy1.setHeightForWidth(ellipseButton->sizePolicy().hasHeightForWidth());
        ellipseButton->setSizePolicy(sizePolicy1);
        ellipseButton->setMinimumSize(QSize(30, 30));
        ellipseButton->setMaximumSize(QSize(45, 30));
        ellipseButton->setCheckable(true);

        gridLayout_6->addWidget(ellipseButton, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 0, 0, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 3, 0, 1, 2);


        gridLayout->addLayout(gridLayout_6, 0, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        dropperButton = new QPushButton(centralwidget);
        dropperButton->setObjectName(QString::fromUtf8("dropperButton"));
        sizePolicy1.setHeightForWidth(dropperButton->sizePolicy().hasHeightForWidth());
        dropperButton->setSizePolicy(sizePolicy1);
        dropperButton->setMinimumSize(QSize(30, 30));
        dropperButton->setMaximumSize(QSize(45, 30));
        dropperButton->setCheckable(true);

        gridLayout_5->addWidget(dropperButton, 1, 1, 1, 1);

        fillButton = new QPushButton(centralwidget);
        fillButton->setObjectName(QString::fromUtf8("fillButton"));
        sizePolicy1.setHeightForWidth(fillButton->sizePolicy().hasHeightForWidth());
        fillButton->setSizePolicy(sizePolicy1);
        fillButton->setMinimumSize(QSize(30, 30));
        fillButton->setMaximumSize(QSize(45, 30));
        fillButton->setCheckable(true);

        gridLayout_5->addWidget(fillButton, 0, 1, 1, 1);

        eraserButton = new QPushButton(centralwidget);
        eraserButton->setObjectName(QString::fromUtf8("eraserButton"));
        sizePolicy1.setHeightForWidth(eraserButton->sizePolicy().hasHeightForWidth());
        eraserButton->setSizePolicy(sizePolicy1);
        eraserButton->setMinimumSize(QSize(30, 30));
        eraserButton->setMaximumSize(QSize(45, 30));
        eraserButton->setCheckable(true);

        gridLayout_5->addWidget(eraserButton, 1, 0, 1, 1);

        penButton = new QPushButton(centralwidget);
        penButton->setObjectName(QString::fromUtf8("penButton"));
        sizePolicy1.setHeightForWidth(penButton->sizePolicy().hasHeightForWidth());
        penButton->setSizePolicy(sizePolicy1);
        penButton->setMinimumSize(QSize(30, 30));
        penButton->setMaximumSize(QSize(45, 30));
        penButton->setCheckable(true);

        gridLayout_5->addWidget(penButton, 0, 0, 1, 1);

        textButton = new QPushButton(centralwidget);
        textButton->setObjectName(QString::fromUtf8("textButton"));
        sizePolicy1.setHeightForWidth(textButton->sizePolicy().hasHeightForWidth());
        textButton->setSizePolicy(sizePolicy1);
        textButton->setMinimumSize(QSize(60, 30));
        textButton->setMaximumSize(QSize(92, 30));
        textButton->setToolTipDuration(-1);
        textButton->setCheckable(true);

        gridLayout_5->addWidget(textButton, 2, 0, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 3, 0, 1, 2);


        gridLayout->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1136, 25));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCLock = new QMenu(menubar);
        menuCLock->setObjectName(QString::fromUtf8("menuCLock"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuCLock->menuAction());
        menubar->addAction(menuAbout->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        darkRedButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\242\321\221\320\274\320\275\320\276-\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        darkRedButton->setText(QString());
#if QT_CONFIG(tooltip)
        firstColorButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\206\320\262\320\265\321\202", nullptr));
#endif // QT_CONFIG(tooltip)
        firstColorButton->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 1", nullptr));
#if QT_CONFIG(tooltip)
        greenButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\321\221\320\275\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        greenButton->setText(QString());
#if QT_CONFIG(tooltip)
        purpleButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        purpleButton->setText(QString());
#if QT_CONFIG(tooltip)
        indigoButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\264\320\270\320\263\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        indigoButton->setText(QString());
#if QT_CONFIG(tooltip)
        greyButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        greyButton->setText(QString());
#if QT_CONFIG(tooltip)
        redButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        redButton->setText(QString());
#if QT_CONFIG(tooltip)
        orangeButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\236\321\200\320\260\320\275\320\266\320\265\320\262\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        orangeButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202\320\260", nullptr));
#if QT_CONFIG(tooltip)
        blackButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\247\321\221\321\200\320\275\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        blackButton->setText(QString());
#if QT_CONFIG(tooltip)
        yellowButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\226\321\221\320\273\321\202\321\213\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        yellowButton->setText(QString());
#if QT_CONFIG(tooltip)
        secondColorButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        secondColorButton->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 2", nullptr));
#if QT_CONFIG(tooltip)
        blueButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\273\321\203\320\261\320\276\320\271", nullptr));
#endif // QT_CONFIG(tooltip)
        blueButton->setText(QString());
#if QT_CONFIG(tooltip)
        rectangleButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
#endif // QT_CONFIG(tooltip)
        rectangleButton->setText(QString());
#if QT_CONFIG(tooltip)
        ellipseButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
#endif // QT_CONFIG(tooltip)
        ellipseButton->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\263\321\203\321\200\321\213", nullptr));
#if QT_CONFIG(tooltip)
        dropperButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\270\320\277\320\265\321\202\320\272\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        dropperButton->setText(QString());
#if QT_CONFIG(tooltip)
        fillButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\273\320\270\320\262\320\272\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        fillButton->setText(QString());
#if QT_CONFIG(tooltip)
        eraserButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\233\320\260\321\201\321\202\320\270\320\272", nullptr));
#endif // QT_CONFIG(tooltip)
        eraserButton->setText(QString());
#if QT_CONFIG(tooltip)
        penButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\200\320\260\320\275\320\264\320\260\321\210", nullptr));
#endif // QT_CONFIG(tooltip)
        penButton->setText(QString());
#if QT_CONFIG(tooltip)
        textButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202", nullptr));
#endif // QT_CONFIG(tooltip)
        textButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\203\321\200\320\274\320\265\320\275\321\202\321\213", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menuCLock->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
