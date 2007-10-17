#ifndef COLORSOURCEUI_H
#define COLORSOURCEUI_H

#include <QObject>
#include "ui_colorsource.h"
#include "color.h"

class ColorSourceUi : public QWidget, public Ui::ColorSourceUi
{
    Q_OBJECT

public:
    ColorSourceUi(QWidget *parent = 0);

signals:
    void componentChanged(int componentId, double value);

public slots:
    void setComponents(double component0, double component1, double component2, double component3);

private slots:
    void on_component0SpinBox_valueChanged(double value);
    void on_component1SpinBox_valueChanged(double value);
    void on_component2SpinBox_valueChanged(double value);
    void on_component3SpinBox_valueChanged(double value);
};

class ColorSourceUiController : public QObject
{
    Q_OBJECT

public:
    ColorSourceUiController(QObject *parent = 0);
    void connectToModelAndView(QObject *model, QWidget *view);

signals:
    void colorChanged(double component0, double component1, double component2, double component3);

private slots:
    void handleModelColorChanged(const Color &color);
};

#endif
