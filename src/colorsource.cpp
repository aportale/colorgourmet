#include "colorsource.h"
#include "colorsourceui.h"

ColorSource::ColorSource(QObject *parent)
    : ColorTransformation(parent)
{
    ColorSourceUiController *controller = new ColorSourceUiController(this);
    m_ui = new ColorSourceUi;
    controller->connectToModelAndView(this, m_ui);
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

QString ColorSource::name() const
{
    return tr("RGB Color");
}

void ColorSource::setColor(const Color &color)
{
    m_color = color;
    emit colorChanged(color);
    emit outputChanged();
}

void ColorSource::setColorComponent(int componentId, double value)
{
    m_color.setComponentValue(componentId, value);
    emit outputChanged();
}

Color ColorSource::color() const
{
    return m_color;
}
