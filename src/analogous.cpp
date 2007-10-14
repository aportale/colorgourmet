#include "analogous.h"
#include "analogousui.h"
#include <QWidget>

Analogous::Analogous(QObject *parent)
    : ColorTransformation(parent)
    , m_analogousColorsCount(4)
{
    m_ui = new AnalogousUi;
    AnalogousUiController *controller = new AnalogousUiController(this);
    controller->connectToModelAndView(this, m_ui);
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

            if (i == (m_analogousColorsCount / 2)) {
                hueValue += m_angle;
                if (includeInput())
                    result.append(inputColor);
            }

            hueValue += m_angle;
            if (hueValue >= 360)
                hueValue -= 360;
            else if (hueValue <= 0)
                hueValue += 360;
            workingColorComponents[0] = hueValue;
            workingColor.setComponents(workingColorComponents);
            result.append(workingColor.convertToColorSpace(inputColor.colorSpace()));
        }
    }

    return result;
}

QWidget *Analogous::ui()
{
    return m_ui;
}

QString Analogous::name() const
{
    return tr("Analogous");
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
