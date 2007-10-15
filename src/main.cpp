#include "color.h"
#include "colorsource.h"
#include "analogous.h"
#include "complementary.h"
#include "mixture.h"
#include "colortransformationnode.h"
#include <QtDebug>
#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *nodesWidget = new QWidget;
    QGridLayout *nodesWidgetLayout = new QGridLayout;
    nodesWidget->setLayout(nodesWidgetLayout);

    QVector<double> inputValues(3);
    inputValues[0] = 0;
    inputValues[1] = 0;
    inputValues[2] = 255;
    ColorSource *source1 = new ColorSource;
    source1->setColor(Color (Color::sRgb, inputValues));
    ColorTransformationNode source1Node(source1);
    nodesWidgetLayout->addWidget(source1Node.ui(), 0, 0);

    inputValues[0] = 255;
    inputValues[1] = 127;
    inputValues[2] = 0;
    ColorSource *source2 = new ColorSource;
    source2->setColor(Color (Color::sRgb, inputValues));
    ColorTransformationNode source2Node(source2);
    nodesWidgetLayout->addWidget(source2Node.ui(), 0, 1);

    Complementary *complementary = new Complementary;
    ColorTransformationNode complementaryNode(complementary);
    complementaryNode.connectToSourceNode(&source1Node, 0);
    nodesWidgetLayout->addWidget(complementaryNode.ui(), 1, 3);

    Analogous *analogous1 = new Analogous;
    analogous1->setIncludeInput(false);
    analogous1->setAngle(10);
    ColorTransformationNode analogous1Node(analogous1);
    analogous1Node.connectToSourceNode(&complementaryNode, 0);
    nodesWidgetLayout->addWidget(analogous1Node.ui(), 1, 1);

    Analogous *analogous2 = new Analogous;
    analogous2->setIncludeInput(true);
    analogous2->setAngle(30);
    ColorTransformationNode analogous2Node(analogous2);
    analogous2Node.connectToSourceNode(&source1Node, 0);
    nodesWidgetLayout->addWidget(analogous2Node.ui(), 1, 2);

    Mixture *mixture = new Mixture;
    ColorTransformationNode mixtureNode(mixture);
    mixture->setStepsCount(10);
    mixtureNode.connectToSourceNode(&source1Node, 0, 0);
    mixtureNode.connectToSourceNode(&source2Node, 0, 1);
    nodesWidgetLayout->addWidget(mixtureNode.ui(), 1, 0);

    QScrollArea scrollArea;
    nodesWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    scrollArea.setWidget(nodesWidget);
    scrollArea.show();

    return a.exec();
}
