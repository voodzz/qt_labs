#include "stylehelper.h"

QString StyleHelper::getStartButtonsStyle() {
    return "QPushButton {"
                  "       background: none;"
                  "       border: 1px solid #333;"
                  "       border-top: none;"
                  "       background-color: #928fe3;"
           "}"
                "QPushButton::hover {"
                "         background-color: #a29fe7"
           "}"
                "QPushButton::pressed {"
                "         background-color:#817edf"
           "}";
}

QString StyleHelper::getMainWidgetStyle() {
    return "QWidget {"
                      "background-image: url(:/icons/icons/bg.png);"
           "}";
}

QString StyleHelper::getLeftButtonStyle() {
    return "QPushButton {"
                "   background: none;"
                "   background: #928fe3 url(:/icons/icons/black_circle_icon.png) no-repeat center center; "
                "   border: 1px solid #333;"
           "}"
           "QPushButton::hover {"
           "         background-color: #a29fe7"
           "}";
}

QString StyleHelper::getLeftButtonActiveStyle() {
    return "QPushButton {"
           "   background: none;"
           "   background: #6A66D9 url(:/icons/icons/black_circle_icon.png) no-repeat center center;"
           "   border: 1px solid #333;"
           "}";
}

QString StyleHelper::getRightButtonStyle() {
    return "QPushButton {"
           "   background: none;"
           "   background: #928fe3 url(:/icons/icons/black_cross_icon.png) no-repeat center center; "
           "   border: 1px solid #333;"
           "   border-left: none;"
           "}"
           "QPushButton::hover {"
           "         background-color: #a29fe7"
           "}";
}

QString StyleHelper::getRightButtonActiveStyle() {
    return "QPushButton {"
           "   background: none;"
           "   background: #6A66D9 url(:/icons/icons/black_cross_icon.png) no-repeat center center;"
           "   border: 1px solid #333;"
           "   border-left: none;"
           "}";
}

QString StyleHelper::getGroupBoxStyle() {
    return "QGroupBox {"
           "background: none;"
           "background-color: #6A66D9;"
           "border: 1px solid #333;"
           "}";
}

QString StyleHelper::getBlankButtonStyle() {
    return "QPushButton {"
           "background: none;"
           "border: none;"
           "background-color: #928fe3;"
           "}"
           "QPushButton::hover {"
           "background-color: #a29fe7;"
           "}";
}

QString StyleHelper::getCrossNormalStyle() {
    return "QPushButton {"
           "background: none;"
           "border:none;"
           "border: 1px solid #6A66D9;"
           "background: #928fe3 url(:/icons/icons/black_cross_for_field.png) no-repeat center center;"
           "}"
           "QPushButton::hover {"
           "background-color: #a29fe7;"
           "}";
}

QString StyleHelper::getCrossVictoryStyle() {
    return "QPushButton {"
           "background: none;"
           "border: none;"
           "border: 1px solid #6A66D9;"
           "background: #00c497 url(:/icons/icons/black_win_cross_for_field.png) no-repeat center center;"
           "}";
}

QString StyleHelper::getCrossLossStyle() {
    return "QPushButton {"
           "background: none;"
           "border: none;"
           "border: 1px solid #6A66D9;"
           "background: #d33c41 url(:/icons/icons/black_loss_cross_for_field.png) no-repeat center center;"
           "}";
}

QString StyleHelper::getCircleNormalStyle() {
    return "QPushButton {"
           "background: none;"
           "border:none;"
           "border: 1px solid #6A66D9;"
           "background: #928fe3 url(:/icons/icons/black_circle_for_field.png) no-repeat center center;"
           "}"
           "QPushButton::hover {"
           "background-color: #a29fe7;"
           "}";
}

QString StyleHelper::getCircleVictoryStyle() {
    return "QPushButton {"
           "background: none;"
           "border: none;"
           "border: 1px solid #6A66D9;"
           "background: #00c497 url(:/icons/icons/black_win_circle_for_field.png) no-repeat center center;"
           "}";
}

QString StyleHelper::getCircleLossStyle() {
    return "QPushButton {"
           "background: none;"
           "border: none;"
           "border: 1px solid #6A66D9;"
           "background: #d33c41 url(:/icons/icons/black_loss_circle_for_field.png) no-repeat center center;"
           "}";
}

QString StyleHelper::getNormalMessageStyle() {
    return "QLabel {"
           "font-family: 'Jura Medium';"
           "font-size: 18px;"
           "background:none;"
           "color:#000000;"
           "}";
}

QString StyleHelper::getWinMessageStyle() {
    return "QLabel {"
           "font-family: 'Jura Medium';"
           "font-size: 18px;"
           "background: #00c497;"
           "color:#000000;"
           "border:1px solid #333;"
           "border-bottom: none;"
           "}";
}

QString StyleHelper::getLossMessageStyle() {
    return "QLabel {"
           "font-family: 'Jura Medium';"
           "font-size: 18px;"
           "background: #d33c41;"
           "color:#000000;"
           "border:1px solid #333;"
           "border-bottom: none;"
           "}";
}

QString StyleHelper::getDrawMessageStyle() {
    return "QLabel {"
           "font-family: 'Jura Medium';"
           "font-size: 18px;"
           "background: #bbbbbb;"
           "color:#000000;"
           "border:1px solid #333;"
           "border-bottom: none;"
           "}";
}
