#include "analogousui.h"
#include "analogous.h"
#include "undostack.h"

AnalogousColorsCountCommand::AnalogousColorsCountCommand(Analogous *analogous, int count, QUndoCommand *parent)
: QUndoCommand(parent)
, m_analogous(analogous)
, m_oldCount(analogous->analogousColorsCount())
, m_count(count)
{
    setText(Analogous::tr("Set amount of analog colors to %1").arg(count));
}

void AnalogousColorsCountCommand::undo()
{
    m_analogous->setAnalogousColorsCount(m_oldCount);
}

void AnalogousColorsCountCommand::redo()
{
    m_analogous->setAnalogousColorsCount(m_count);
}

AnalogousAngleCommand::AnalogousAngleCommand(Analogous *analogous, double angle, QUndoCommand *parent)
: QUndoCommand(parent)
, m_analogous(analogous)
, m_oldAngle(analogous->angle())
, m_angle(angle)
{
    setText(Analogous::tr("Set angle analog colors to %1").arg(angle));
}

void AnalogousAngleCommand::undo()
{
    m_analogous->setAngle(m_oldAngle);
}

void AnalogousAngleCommand::redo()
{
    m_analogous->setAngle(m_angle);
}

AnalogousUi::AnalogousUi(Analogous *analogous, QWidget *parent)
    : QWidget(parent)
    , m_analogous(analogous)
{
    setupUi(this);
    connect(analogous, SIGNAL(analogousColorsCountChanged(int)),
        analogousColorsCountSpinbox, SLOT(setValue(int)));
    connect(analogous, SIGNAL(angleChanged(double)),
        angleSpinBox, SLOT(setValue(double)));
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
