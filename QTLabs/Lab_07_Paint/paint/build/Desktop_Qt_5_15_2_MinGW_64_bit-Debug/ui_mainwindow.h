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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
    QGridLayout *gridLayout;
    QFrame *line;
    QFrame *line_2;
    QPushButton *blackButton;
    QFrame *line_4;
    QPushButton *yellowButton;
    QPushButton *colorsButton;
    QFrame *line_3;
    QLabel *label_4;
    QPushButton *greyButton;
    QPushButton *eraserButton;
    QPushButton *secondColorButton;
    QPushButton *textButton;
    QLabel *label_5;
    QPushButton *indigoButton;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *greenButton;
    QPushButton *darkRedButton;
    QPushButton *orangeButton;
    QFrame *line_5;
    QPushButton *rectangleButton;
    QPushButton *fillerButton;
    QPushButton *blueButton;
    QLabel *label;
    QPushButton *ellipseButton;
    QComboBox *thicknessComboBox;
    QLabel *label_7;
    QLabel *label_6;
    QPushButton *redButton;
    QPushButton *firstColorButton;
    QPushButton *dropperButton;
    QPushButton *purpleButton;
    QPushButton *penButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuFile;
    QMenu *menuCLock;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1136, 693);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/paint-palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(0);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 2, 4, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 5, 4, 1);

        blackButton = new QPushButton(centralwidget);
        blackButton->setObjectName(QString::fromUtf8("blackButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(blackButton->sizePolicy().hasHeightForWidth());
        blackButton->setSizePolicy(sizePolicy);
        blackButton->setMaximumSize(QSize(45, 45));
        blackButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(blackButton, 0, 11, 3, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 0, 21, 4, 1);

        yellowButton = new QPushButton(centralwidget);
        yellowButton->setObjectName(QString::fromUtf8("yellowButton"));
        sizePolicy.setHeightForWidth(yellowButton->sizePolicy().hasHeightForWidth());
        yellowButton->setSizePolicy(sizePolicy);
        yellowButton->setMaximumSize(QSize(45, 45));
        yellowButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 242, 2);"));

        gridLayout->addWidget(yellowButton, 0, 16, 3, 1);

        colorsButton = new QPushButton(centralwidget);
        colorsButton->setObjectName(QString::fromUtf8("colorsButton"));
        sizePolicy.setHeightForWidth(colorsButton->sizePolicy().hasHeightForWidth());
        colorsButton->setSizePolicy(sizePolicy);
        colorsButton->setMaximumSize(QSize(79, 45));

        gridLayout->addWidget(colorsButton, 0, 22, 2, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 10, 4, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(8);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 8, 1, 1);

        greyButton = new QPushButton(centralwidget);
        greyButton->setObjectName(QString::fromUtf8("greyButton"));
        sizePolicy.setHeightForWidth(greyButton->sizePolicy().hasHeightForWidth());
        greyButton->setSizePolicy(sizePolicy);
        greyButton->setMaximumSize(QSize(45, 45));
        greyButton->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 120, 120);"));

        gridLayout->addWidget(greyButton, 0, 12, 3, 1);

        eraserButton = new QPushButton(centralwidget);
        eraserButton->setObjectName(QString::fromUtf8("eraserButton"));
        sizePolicy.setHeightForWidth(eraserButton->sizePolicy().hasHeightForWidth());
        eraserButton->setSizePolicy(sizePolicy);
        eraserButton->setMaximumSize(QSize(45, 30));
        eraserButton->setLayoutDirection(Qt::LeftToRight);
        eraserButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/eraser.png);"));
        eraserButton->setCheckable(true);

        gridLayout->addWidget(eraserButton, 1, 0, 1, 1);

        secondColorButton = new QPushButton(centralwidget);
        secondColorButton->setObjectName(QString::fromUtf8("secondColorButton"));
        sizePolicy.setHeightForWidth(secondColorButton->sizePolicy().hasHeightForWidth());
        secondColorButton->setSizePolicy(sizePolicy);
        secondColorButton->setMaximumSize(QSize(45, 45));
        secondColorButton->setCheckable(true);

        gridLayout->addWidget(secondColorButton, 0, 9, 2, 1);

        textButton = new QPushButton(centralwidget);
        textButton->setObjectName(QString::fromUtf8("textButton"));
        textButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/text.png);"));
        textButton->setCheckable(true);

        gridLayout->addWidget(textButton, 3, 0, 1, 2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 9, 1, 1);

        indigoButton = new QPushButton(centralwidget);
        indigoButton->setObjectName(QString::fromUtf8("indigoButton"));
        sizePolicy.setHeightForWidth(indigoButton->sizePolicy().hasHeightForWidth());
        indigoButton->setSizePolicy(sizePolicy);
        indigoButton->setMaximumSize(QSize(45, 45));
        indigoButton->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 72, 204);"));

        gridLayout->addWidget(indigoButton, 0, 19, 3, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 4, 8, 1, 15);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 4, 3, 1, 2);

        greenButton = new QPushButton(centralwidget);
        greenButton->setObjectName(QString::fromUtf8("greenButton"));
        sizePolicy.setHeightForWidth(greenButton->sizePolicy().hasHeightForWidth());
        greenButton->setSizePolicy(sizePolicy);
        greenButton->setMaximumSize(QSize(45, 45));
        greenButton->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 177, 76);"));

        gridLayout->addWidget(greenButton, 0, 17, 3, 1);

        darkRedButton = new QPushButton(centralwidget);
        darkRedButton->setObjectName(QString::fromUtf8("darkRedButton"));
        sizePolicy.setHeightForWidth(darkRedButton->sizePolicy().hasHeightForWidth());
        darkRedButton->setSizePolicy(sizePolicy);
        darkRedButton->setMaximumSize(QSize(45, 45));
        darkRedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 0, 21);"));

        gridLayout->addWidget(darkRedButton, 0, 13, 3, 1);

        orangeButton = new QPushButton(centralwidget);
        orangeButton->setObjectName(QString::fromUtf8("orangeButton"));
        sizePolicy.setHeightForWidth(orangeButton->sizePolicy().hasHeightForWidth());
        orangeButton->setSizePolicy(sizePolicy);
        orangeButton->setMaximumSize(QSize(45, 45));
        orangeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 127, 39);"));

        gridLayout->addWidget(orangeButton, 0, 15, 3, 1);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 0, 7, 4, 1);

        rectangleButton = new QPushButton(centralwidget);
        rectangleButton->setObjectName(QString::fromUtf8("rectangleButton"));
        sizePolicy.setHeightForWidth(rectangleButton->sizePolicy().hasHeightForWidth());
        rectangleButton->setSizePolicy(sizePolicy);
        rectangleButton->setMaximumSize(QSize(45, 45));
        rectangleButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/rectangle.png);"));
        rectangleButton->setCheckable(true);

        gridLayout->addWidget(rectangleButton, 0, 4, 4, 1);

        fillerButton = new QPushButton(centralwidget);
        fillerButton->setObjectName(QString::fromUtf8("fillerButton"));
        sizePolicy.setHeightForWidth(fillerButton->sizePolicy().hasHeightForWidth());
        fillerButton->setSizePolicy(sizePolicy);
        fillerButton->setMaximumSize(QSize(45, 30));
        fillerButton->setLayoutDirection(Qt::LeftToRight);
        fillerButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/paint.png);"));
        fillerButton->setCheckable(true);

        gridLayout->addWidget(fillerButton, 0, 1, 1, 1);

        blueButton = new QPushButton(centralwidget);
        blueButton->setObjectName(QString::fromUtf8("blueButton"));
        sizePolicy.setHeightForWidth(blueButton->sizePolicy().hasHeightForWidth());
        blueButton->setSizePolicy(sizePolicy);
        blueButton->setMaximumSize(QSize(45, 45));
        blueButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 162, 232);"));

        gridLayout->addWidget(blueButton, 0, 18, 3, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 4, 0, 1, 2);

        ellipseButton = new QPushButton(centralwidget);
        ellipseButton->setObjectName(QString::fromUtf8("ellipseButton"));
        sizePolicy.setHeightForWidth(ellipseButton->sizePolicy().hasHeightForWidth());
        ellipseButton->setSizePolicy(sizePolicy);
        ellipseButton->setMaximumSize(QSize(45, 45));
        ellipseButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/ellipse.png);"));
        ellipseButton->setCheckable(true);

        gridLayout->addWidget(ellipseButton, 0, 3, 4, 1);

        thicknessComboBox = new QComboBox(centralwidget);
        thicknessComboBox->addItem(QString());
        thicknessComboBox->addItem(QString());
        thicknessComboBox->addItem(QString());
        thicknessComboBox->addItem(QString());
        thicknessComboBox->setObjectName(QString::fromUtf8("thicknessComboBox"));
        sizePolicy.setHeightForWidth(thicknessComboBox->sizePolicy().hasHeightForWidth());
        thicknessComboBox->setSizePolicy(sizePolicy);
        thicknessComboBox->setMaximumSize(QSize(53, 45));
        thicknessComboBox->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(thicknessComboBox, 0, 6, 4, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 4, 6, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 3, 22, 1, 1);

        redButton = new QPushButton(centralwidget);
        redButton->setObjectName(QString::fromUtf8("redButton"));
        sizePolicy.setHeightForWidth(redButton->sizePolicy().hasHeightForWidth());
        redButton->setSizePolicy(sizePolicy);
        redButton->setMaximumSize(QSize(45, 45));
        redButton->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 28, 36);"));

        gridLayout->addWidget(redButton, 0, 14, 3, 1);

        firstColorButton = new QPushButton(centralwidget);
        firstColorButton->setObjectName(QString::fromUtf8("firstColorButton"));
        sizePolicy.setHeightForWidth(firstColorButton->sizePolicy().hasHeightForWidth());
        firstColorButton->setSizePolicy(sizePolicy);
        firstColorButton->setMaximumSize(QSize(45, 45));
        firstColorButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));
        firstColorButton->setCheckable(true);

        gridLayout->addWidget(firstColorButton, 0, 8, 2, 1);

        dropperButton = new QPushButton(centralwidget);
        dropperButton->setObjectName(QString::fromUtf8("dropperButton"));
        sizePolicy.setHeightForWidth(dropperButton->sizePolicy().hasHeightForWidth());
        dropperButton->setSizePolicy(sizePolicy);
        dropperButton->setMaximumSize(QSize(45, 30));
        dropperButton->setLayoutDirection(Qt::LeftToRight);
        dropperButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/dropper.png);"));
        dropperButton->setCheckable(true);

        gridLayout->addWidget(dropperButton, 1, 1, 1, 1);

        purpleButton = new QPushButton(centralwidget);
        purpleButton->setObjectName(QString::fromUtf8("purpleButton"));
        sizePolicy.setHeightForWidth(purpleButton->sizePolicy().hasHeightForWidth());
        purpleButton->setSizePolicy(sizePolicy);
        purpleButton->setMaximumSize(QSize(45, 45));
        purpleButton->setStyleSheet(QString::fromUtf8("background-color: rgb(163, 73, 164);"));

        gridLayout->addWidget(purpleButton, 0, 20, 2, 1);

        penButton = new QPushButton(centralwidget);
        penButton->setObjectName(QString::fromUtf8("penButton"));
        sizePolicy.setHeightForWidth(penButton->sizePolicy().hasHeightForWidth());
        penButton->setSizePolicy(sizePolicy);
        penButton->setMaximumSize(QSize(45, 30));
        penButton->setLayoutDirection(Qt::LeftToRight);
        penButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/brush.png);"));
        penButton->setCheckable(true);

        gridLayout->addWidget(penButton, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(0, 500));
        graphicsView->setFont(font);

        gridLayout_2->addWidget(graphicsView, 2, 0, 1, 3);

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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Paint", nullptr));
        blackButton->setText(QString());
        yellowButton->setText(QString());
        colorsButton->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 1", nullptr));
        greyButton->setText(QString());
        eraserButton->setText(QString());
        secondColorButton->setText(QString());
        textButton->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 2", nullptr));
        indigoButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\263\321\203\321\200\321\213", nullptr));
        greenButton->setText(QString());
        darkRedButton->setText(QString());
        orangeButton->setText(QString());
        rectangleButton->setText(QString());
        fillerButton->setText(QString());
        blueButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", nullptr));
        ellipseButton->setText(QString());
        thicknessComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1px", nullptr));
        thicknessComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "3px", nullptr));
        thicknessComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "5px", nullptr));
        thicknessComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "8px", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265\n"
"\321\206\320\262\320\265\321\202\320\276\320\262", nullptr));
        redButton->setText(QString());
        firstColorButton->setText(QString());
        dropperButton->setText(QString());
        purpleButton->setText(QString());
        penButton->setText(QString());
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
