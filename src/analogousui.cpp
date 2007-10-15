#include "analogousui.h"

AnalogousUi::AnalogousUi(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    connect(this, SIGNAL(setAnalogousColorsCount(int)), analogousColorsCountSpinbox, SLOT(setValue(int)));
    connect(analogousColorsCountSpinbox, SIGNAL(valueChanged(int)), SIGNAL(analogousColorsCountChanged(int)));
    connect(this, SIGNAL(setAngle(double)), angleSpinBox, SLOT(setValue(double)));
    connect(angleSpinBox, SIGNAL(valueChanged(double)), SIGNAL(angleChanged(double)));
    connect(this, SIGNAL(setIncludeInput(bool)), includeInputCheckBox, SLOT(setChecked(bool)));
    connect(includeInputCheckBox, SIGNAL(clicked(bool)), SIGNAL(includeInputChanged(bool)));
}

AnalogousUiController::AnalogousUiController(QObject *parent)
    : QObject(parent)
{
}

void AnalogousUiController::connectToModelAndView(QObject *model, QWidget *view)
{
    connect(model, SIGNAL(analogousColorsCountChanged(int)), view, SIGNAL(setAnalogousColorsCount(int)));
    connect(view, SIGNAL(analogousColorsCountChanged(int)), model, SLOT(setAnalogousColorsCount(int)));
    connect(model, SIGNAL(angleChanged(double)), view, SIGNAL(setAngle(double)));
    connect(view, SIGNAL(angleChanged(double)), model, SLOT(setAngle(double)));
    connect(model, SIGNAL(includeInputChanged(bool)), view, SIGNAL(setIncludeInput(bool)));
    connect(view, SIGNAL(includeInputChanged(bool)), model, SLOT(setIncludeInput(bool)));
}
