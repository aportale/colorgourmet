#include "mixture.h"

Mixture::Mixture(QObject *parent)
    : ColorTransformation(parent)
    , m_includeInput(true)
    , m_steps(4)
{
}

int Mixture::inputCount() const
{
    return 2;
}

QVector<Color> Mixture::getOutput(const QVector<Color> &input) const
{
    QVector<Color> result;
    if (input.count() == inputCount()) { 
        if (m_includeInput)
            result.append(input[0]);

        Color leftColor = input[0].convertToColorSpace(Color::sRgbHsv);
        Color rightColor = input[1].convertToColorSpace(Color::sRgbHsv);

        double hRightColor = rightColor.components()[0];
        double hLeftColor = leftColor.components()[0];
        double hDifference = (hRightColor - hLeftColor);
        if (hDifference > 360/2)
            hDifference =  180 - hDifference;
        double hStepSize =  hDifference / (m_steps + 1);
        double sStepSize = (rightColor.components()[1] - leftColor.components()[1]) / (m_steps + 1);
        double vStepSize = (rightColor.components()[2] - leftColor.components()[2]) / (m_steps + 1);

        QVector<double> stepColorComponents;
        stepColorComponents = leftColor.components();
        Color stepColor(Color::sRgbHsv, stepColorComponents);
        for (int i = 0; i < m_steps; i++) {
            stepColorComponents[0] += hStepSize;
            stepColorComponents[1] += sStepSize;
            stepColorComponents[2] += vStepSize;
            stepColor.setComponents(stepColorComponents);
            result.append(stepColor);
        }

        if (m_includeInput)
            result.append(input[1]);
    }
    return result;
}

QWidget *Mixture::ui()
{
    return NULL;
}

QString Mixture::name() const
{
    return tr("Mixture");
}

bool Mixture::includeInput() const
{
    return m_includeInput;
}

void Mixture::setIncludeInput(bool include)
{
    m_includeInput = include;
}

int Mixture::steps() const
{
    return m_steps;
}

void Mixture::setSteps(int steps)
{
    m_steps = steps;
    emit outputChanged();
}
