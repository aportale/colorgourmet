#include "mixtureui.h"

MixtureUi::MixtureUi(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    connect(this, SIGNAL(setStepsCount(int)), stepsCountSpinbox, SLOT(setValue(int)));
    connect(stepsCountSpinbox, SIGNAL(valueChanged(int)), SIGNAL(stepsCountChanged(int)));
    connect(this, SIGNAL(setIncludeInput(bool)), includeInputCheckBox, SLOT(setChecked(bool)));
    connect(includeInputCheckBox, SIGNAL(clicked(bool)), SIGNAL(includeInputChanged(bool)));
}

MixtureUiController::MixtureUiController(QObject *parent)
    : QObject(parent)
{
}

void MixtureUiController::connectToModelAndView(QObject *model, QWidget *view)
{
    connect(model, SIGNAL(stepsCountChanged(int)), view, SIGNAL(setStepsCount(int)));
    connect(view, SIGNAL(stepsCountChanged(int)), model, SLOT(setStepsCount(int)));
    connect(model, SIGNAL(includeInputChanged(bool)), view, SIGNAL(setIncludeInput(bool)));
    connect(view, SIGNAL(includeInputChanged(bool)), model, SLOT(setIncludeInput(bool)));
}
