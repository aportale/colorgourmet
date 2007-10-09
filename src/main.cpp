#include "color.h"
#include "colorsource.h"
#include "analogous.h"
#include "complementary.h"
#include "colortransformationnode.h"
#include <QtDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<qreal> inputValues(3);
    inputValues[0] = 0;
    inputValues[1] = 0;
    inputValues[2] = 255;

    ColorSource *source = new ColorSource;
    source->setColor(Color (Color::sRgb, inputValues));
    ColorTransformationNode sourceNode(source);
    sourceNode.ui()->show();

    Complementary *complementary = new Complementary;
    ColorTransformationNode complementaryNode(complementary);
    complementaryNode.connectToSourceNode(&sourceNode, 0);
    complementaryNode.ui()->show();

    Analogous *analogous = new Analogous;
    analogous->setIncludeInput(false);
    analogous->setAngle(10);
    ColorTransformationNode analogousNode(analogous);
    analogousNode.connectToSourceNode(&complementaryNode, 0);
    analogousNode.ui()->show();

    return a.exec();
}
