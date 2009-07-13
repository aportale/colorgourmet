#include "colorsourceui.h"

ColorSourceUi::ColorSourceUi(QWidget *parent)
: QWidget(parent)
{
    setupUi(this);
}

void ColorSourceUi::setComponents(double component0, double component1, double component2, double component3)
{
    Q_UNUSED(component3)
    component0SpinBox->setValue(component0);
    component1SpinBox->setValue(component1);
    component2SpinBox->setValue(component2);
    //    component3SpinBox->setValue(component3);
}

void ColorSourceUi::on_component0SpinBox_valueChanged(double value)
{
    emit componentChanged(0, value);
}

void ColorSourceUi::on_component1SpinBox_valueChanged(double value)
{
    emit componentChanged(1, value);
}

void ColorSourceUi::on_component2SpinBox_valueChanged(double value)
{
    emit componentChanged(2, value);
}

void ColorSourceUi::on_component3SpinBox_valueChanged(double value)
{
    emit componentChanged(3, value);
}

ColorSourceUiController::ColorSourceUiController(QObject *parent)
: QObject(parent)
{
}

void ColorSourceUiController::connectToModelAndView(QObject *model, QWidget *view)
{
    Q_ASSERT(model);
    connect(view, SIGNAL(componentChanged(int, double)), model, SLOT(setColorComponent(int, double)));
    connect(model, SIGNAL(colorChanged(const Color &)), SLOT(handleModelColorChanged(const Color &)));
    connect(this, SIGNAL(colorChanged(double, double, double, double)), view, SLOT(setComponents(double, double, double, double)));
}

void ColorSourceUiController::handleModelColorChanged(const Color &color)
{
    QVector <double>components = color.components();
    components.resize(4);
    emit colorChanged(components[0], components[1], components[2], components[3]);
}
