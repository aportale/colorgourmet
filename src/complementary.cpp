#include "complementary.h"
#include <QWidget>

Complementary::Complementary(QObject *parent)
    : ColorTransformation(parent)
{
}

int Complementary::inputCount() const
{
    return 1;
}

QVector<Color> Complementary::getOutput(const QVector<Color> &input) const
{
    QVector<Color> result;

    if (!input.empty()) {
        Color inputColor = input[0];

        Color workingColor = inputColor.convertToColorSpace(Color::sRgbHsv);
        QVector<qreal> workingColorComponents = workingColor.components();
        qreal hueValue = workingColorComponents[0];
        hueValue += 180;
        if (hueValue >= 360)
            hueValue -= 360;
        workingColorComponents[0] = hueValue;
        workingColor.setComponents(workingColorComponents);

        result.append(workingColor.convertToColorSpace(inputColor.colorSpace()));
    }

    return result;
}

QWidget *Complementary::ui()
{
    return new QWidget;
}

QString Complementary::name() const
{
    return tr("Complementary");
}