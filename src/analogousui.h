#ifndef ANALOGOUSUI_H
#define ANALOGOUSUI_H

#include <QWidget>
#include "ui_analogous.h"

class Analogous;

class AnalogousUi : public QWidget, public Ui::AnalogousUi
{
    Q_OBJECT

public:
    AnalogousUi(Analogous *analogous, QWidget *parent = 0);

public slots:
    void on_analogousColorsCountSpinbox_valueChanged(int value);
    void on_angleSpinBox_valueChanged(double value);
    void on_includeInputCheckBox_clicked(bool checked);

private:
    Analogous *m_analogous;
};

#endif
