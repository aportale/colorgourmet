#include "color.h"
#include <QColor>

Color::Color()
{
    m_colorSpace = sRgb;
    m_components.resize(3);
}

Color::Color(ColorSpace colorSpace, const QVector<double> &components)
    : m_colorSpace(colorSpace)
{
    setComponents(components);
}

void Color::setComponents(const QVector<double> &components)
{
    m_components = components;
}

void Color::setComponentValue(int componentId, double value)
{
    m_components[componentId] = value;
}

double Color::componentValue(int componentId) const
{
    return m_components[componentId];
}

QVector<double> Color::components() const
{
    return m_components;
}

void Color::setName(const QString &name)
{
    m_name = name;
}

QString Color::name() const
{
    return m_name;
}

Color::ColorSpace Color::colorSpace() const
{
    return m_colorSpace;
}

QString Color::colorSpaceName() const
{
    return colorSpaceName(m_colorSpace);
}

QString Color::colorSpaceName(ColorSpace colorSpace)
{
    return 
        colorSpace == sRgb?"sRgb"
        :colorSpace == sRgbHsv?"Hsv"
        :"";
}

QVector<double> Color::pcsColor() const
{
    return QVector<double>();
}

Color Color::convertToColorConversionSpace() const
{
    Color result(*this);
    QColor sourceQColor = QColor::fromRgbF(m_components[0] / 255,
        m_components[1] / 255, m_components[2] / 255);
    if (m_colorSpace == sRgbHsv) {
        sourceQColor = QColor(QColor::fromHsvF(m_components[0] / 360,
            m_components[1] / 255, m_components[2] / 255));
    }

    QVector<double> convertedComponents;
    double r, g, b;
    sourceQColor.getRgbF(&r, &g, &b);
    convertedComponents.append(r * 255);
    convertedComponents.append(g * 255);
    convertedComponents.append(b * 255);
    result.setComponents(convertedComponents);
    result.setColorSpace(sRgb);

    return result;
}

Color Color::convertToColorSpace(ColorSpace targetColorSpace) const
{
    if (targetColorSpace == m_colorSpace)
        return *this;
    else {
        QVector<double> sourceSRgbComponents =
            convertToColorConversionSpace().components();
        QColor sourceQColor(QColor::fromRgbF(sourceSRgbComponents[0] / 255,
            sourceSRgbComponents[1] / 255, sourceSRgbComponents[2] / 255));

        QVector<double> convertedComponents;
        if (targetColorSpace == sRgb) {
            convertedComponents = sourceSRgbComponents;
        } else if (targetColorSpace == sRgbHsv) {
            double h, s, v;
            sourceQColor.getHsvF(&h, &s, &v);
            convertedComponents.append(h * 360);
            convertedComponents.append(s * 255);
            convertedComponents.append(v * 255);
        }
        return Color(targetColorSpace, convertedComponents);
    }
}

QString Color::description() const
{
    return QString("%1: %2 %3 %4")
        .arg(colorSpaceName())
        .arg(int(m_components[0]))
        .arg(int(m_components[1]))
        .arg(int(m_components[2]));
}

QColor Color::displayColor(int displayId) const
{
    Color displayRgb = convertToColorSpace(sRgb);
    QVector<double> displayRgbComponents =
        displayRgb.components();
    QColor displayQColor(QColor::fromRgbF(displayRgbComponents[0] / 255,
        displayRgbComponents[1] / 255, displayRgbComponents[2] / 255));
    return displayQColor;
}

void Color::setColorSpace(ColorSpace colorSpace)
{
    m_colorSpace = colorSpace;
}
