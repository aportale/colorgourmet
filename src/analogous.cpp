#include "analogous.h"
#include "analogousui.h"
#include <QString>

Analogous::Analogous(QObject *parent)
    : ColorTransformation(parent)
{
    m_ui = new AnalogousUi(this);
    setAnalogousColorsCount(4);
    setIncludeInput(true);
    setAngle(15);
}

int Analogous::inputCount() const
{
    return 2 + m_includeInput?1:0;
}

QVector<Color> Analogous::getOutput(const QVector<Color> &input) const
{
    QVector<Color> result;

    if (!input.empty()) {
        Color inputColor = input[0];

        Color workingColor = inputColor.convertToColorSpace(Color::sRgbHsv);
        QVector<double> workingColorComponents = workingColor.components();
        double hueOffset = -((m_analogousColorsCount / 2 + 1) * m_angle);
        workingColorComponents[0] = workingColorComponents[0] + hueOffset;

        for (int i = 0; i < m_analogousColorsCount; i++) {
            double hueValue = workingColorComponents[0];

            if (i == m_analogousColorsCount / 2)
                hueValue += m_angle;

            hueValue += m_angle;
            if (hueValue >= 360)
                hueValue -= 360;
            else if (hueValue <= 0)
                hueValue += 360;
            workingColorComponents[0] = hueValue;
            workingColor.setComponents(workingColorComponents);
            result.append(workingColor.convertToColorSpace(inputColor.colorSpace()));
        }
        if (includeInput())
            result.insert(m_analogousColorsCount / 2, 1, inputColor);
    }

    return result;
}

QString Analogous::name() const
{
    return tr("Analogous");
}

int Analogous::analogousColorsCount() const
{
    return m_analogousColorsCount;
}

void Analogous::setAnalogousColorsCount(int count)
{
    m_analogousColorsCount = count;
    emit analogousColorsCountChanged(m_analogousColorsCount);
    emit outputChanged();
}

double Analogous::angle() const
{
    return m_angle;
}

void Analogous::setAngle(double angle)
{
    m_angle = angle;
    emit angleChanged(m_angle);
    emit outputChanged();
}

bool Analogous::includeInput() const
{
    return m_includeInput;
}

void Analogous::setIncludeInput(bool include)
{
    m_includeInput = include;
    emit includeInputChanged(m_includeInput);
    emit outputChanged();
}
