#ifndef ANALOGOUSUI_H
#define ANALOGOUSUI_H

#include <QWidget>
#include "ui_analogous.h"

class AnalogousUi : public QWidget, public Ui::AnalogousUi
{
    Q_OBJECT

public:
    AnalogousUi(QWidget *parent = 0);

signals:
    void setAngle(double angle);
    void angleChanged(double angle);
    void setIncludeInput(bool include);
    void includeInputChanged(bool include);
};

class AnalogousUiController : public QObject
{
    Q_OBJECT

public:
    AnalogousUiController(QObject *parent = 0);
    void connectToModelAndView(QObject *model, QWidget *view);
};

#endif
