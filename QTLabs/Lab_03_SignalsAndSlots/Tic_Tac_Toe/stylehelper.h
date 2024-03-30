#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    static QString getStartButtonsStyle();
    static QString getMainWidgetStyle();
    static QString getLeftButtonStyle();
    static QString getLeftButtonActiveStyle();
    static QString getRightButtonStyle();
    static QString getRightButtonActiveStyle();
    static QString getGroupBoxStyle();

    static QString getBlankButtonStyle();
    static QString getCrossNormalStyle();
    static QString getCrossVictoryStyle();
    static QString getCrossLossStyle();

    static QString getCircleNormalStyle();
    static QString getCircleVictoryStyle();
    static QString getCircleLossStyle();

    static QString getNormalMessageStyle();
    static QString getWinMessageStyle();
    static QString getLossMessageStyle();
    static QString getDrawMessageStyle();
};

#endif // STYLEHELPER_H
