#ifndef MIXTUREUI_H
#define MIXTUREUI_H

#include <QWidget>
#include "ui_mixture.h"

class Mixture;

class MixtureUi : public QWidget, public Ui::MixtureUi
{
    Q_OBJECT

public:
    MixtureUi(Mixture *mixture, QWidget *parent = 0);

public slots:
   void on_stepsCountSpinbox_valueChanged(int value);
   void on_includeInputCheckBox_clicked(bool checked);

private:
    Mixture *m_mixture;
};

#endif
