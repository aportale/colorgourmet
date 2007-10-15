#ifndef MIXTUREUI_H
#define MIXTUREUI_H

#include <QWidget>
#include "ui_mixture.h"

class MixtureUi : public QWidget, public Ui::MixtureUi
{
    Q_OBJECT

public:
    MixtureUi(QWidget *parent = 0);

signals:
    void setStepsCount(int steps);
    void stepsCountChanged(int steps);
    void setIncludeInput(bool include);
    void includeInputChanged(bool include);
};

class MixtureUiController : public QObject
{
    Q_OBJECT

public:
    MixtureUiController(QObject *parent = 0);
    void connectToModelAndView(QObject *model, QWidget *view);
};

#endif
