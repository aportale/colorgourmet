#include "colorsource.h"

ColorSourceUi::ColorSourceUi(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
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
    connect(view, SIGNAL(componentChanged(int, qreal)), model, SLOT(setColorComponent(int, qreal)));
}

ColorSource::ColorSource(QObject *parent)
    : ColorTransformation(parent)
{
}

int ColorSource::inputCount() const
{
    return 0;
}

QVector<Color> ColorSource::getOutput(const QVector<Color> &input) const
{
    Q_UNUSED(input)
    QVector<Color> result;
    result.append(color());
    return result;
}

QWidget *ColorSource::ui()
{
    ColorSourceUiController *controller = new ColorSourceUiController(this);
    ColorSourceUi *ui = new ColorSourceUi;
    controller->connectToModelAndView(this, ui);
    return ui;
}

QString ColorSource::name() const
{
    return tr("RGB Color");
}

void ColorSource::setColor(const Color &color)
{
    m_color = color;
    emit outputChanged();
}

void ColorSource::setColorComponent(int componentId, qreal value)
{
    m_color.setComponentValue(componentId, value);
    emit outputChanged();
}

Color ColorSource::color() const
{
    return m_color;
}
