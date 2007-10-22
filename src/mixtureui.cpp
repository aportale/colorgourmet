#include "mixtureui.h"
#include "mixture.h"
#include "mixturecommands.h"
#include "undostack.h"

MixtureUi::MixtureUi(Mixture *mixture, QWidget *parent)
    : QWidget(parent)
    , m_mixture(mixture)
{
    setupUi(this);
    connect(mixture, SIGNAL(stepsCountChanged(int)),
        stepsCountSpinbox, SLOT(setValue(int)));
    connect(mixture, SIGNAL(includeInputChanged(bool)),
        includeInputCheckBox, SLOT(setChecked(bool)));
}

void MixtureUi::on_stepsCountSpinbox_valueChanged(int value)
{
    if (m_mixture->stepsCount() != value)
        UndoStack::instance()->push(new MixtureStepsCountCommand(m_mixture, value));
}

void MixtureUi::on_includeInputCheckBox_clicked(bool checked)
{

}