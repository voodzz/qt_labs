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
                "   background-color: #928fe3;"
                "   border: 1px solid #333;"
           "}";
}

QString StyleHelper::getLeftButtonActiveStyle() {
    return "QPushButton {"
           "   background: none;"
           "   background-color: #6A66D9;"
           "   border: 1px solid #333;"
           "}";
}

QString StyleHelper::getRightButtonStyle() {
    return "QPushButton {"
           "   background: none;"
           "   background-color: #928fe3;"
           "   border: 1px solid #333;"
           "   border-left: none;"
           "}";
}

QString StyleHelper::getRightButtonActiveStyle() {
    return "QPushButton {"
           "   background: none;"
           "   background-color: #6A66D9;"
           "   border: 1px solid #333;"
           "   border-left: none;"
           "}";
}
