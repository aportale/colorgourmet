#include "analogousui.h"
#include "analogous.h"
#include "analogouscommands.h"
#include "undostack.h"

AnalogousUi::AnalogousUi(Analogous *analogous, QWidget *parent)
    : QWidget(parent)
    , m_analogous(analogous)
{
    setupUi(this);
    connect(analogous, SIGNAL(analogousColorsCountChanged(int)),
        analogousColorsCountSpinbox, SLOT(setValue(int)));
    connect(analogous, SIGNAL(angleChanged(double)),
        angleSpinBox, SLOT(setValue(double)));
    connect(analogous, SIGNAL(includeInputChanged(bool)),
        includeInputCheckBox, SLOT(setChecked(bool)));
}

void AnalogousUi::on_analogousColorsCountSpinbox_valueChanged(int value)
{
    if (m_analogous->analogousColorsCount() != value)
        UndoStack::instance()->push(new AnalogousColorsCountCommand(m_analogous, value));
}

void AnalogousUi::on_angleSpinBox_valueChanged(double value)
{
    if (m_analogous->angle() > value + 0.001 || m_analogous->angle() < value - 0.001)
        UndoStack::instance()->push(new AnalogousAngleCommand(m_analogous, value));
}

void AnalogousUi::on_includeInputCheckBox_clicked(bool checked)
{
    UndoStack::instance()->push(new AnalogousIncludeInputCommand(m_analogous, checked));
}
