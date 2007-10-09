#include "colortransformationnode.h"
#include "colortransformationnodeui.h"
#include "colortransformation.h"
#include "colormodel.h"
#include <QWidget>

ColorInputSource::ColorInputSource(ColorTransformationNode *sourceNode, int colorIndex,
    QObject *parent)
    : QObject(parent)
    , m_sourceNodePointer(sourceNode)
    , m_sourceColorIndex(colorIndex)
{
    connect(m_sourceNodePointer, SIGNAL(colorsUpdated()), SIGNAL(sourceColorUpdated()));
}

Color ColorInputSource::color() const
{
    if (m_sourceNodePointer)
        return m_sourceNodePointer->colors().at(m_sourceColorIndex);
    else
        return Color();
}

ColorTransformationNode::ColorTransformationNode(ColorTransformation *colorTransformation, QObject *parent)
    : QObject(parent)
    , m_transformation(colorTransformation)
{
    Q_ASSERT(m_transformation);
    m_inputSources.fill(NULL, m_transformation->inputCount());
    m_colorModel = new ColorModel(this);
    updateColors();
    m_transformation->setParent(this);
    connect(m_transformation, SIGNAL(outputChanged()),
        SLOT(updateColors()));
}

ColorTransformationNode::~ColorTransformationNode()
{
    qDeleteAll(m_inputSources);
}

const QVector<Color> &ColorTransformationNode::colors() const
{
    return m_colors;
}

QWidget *ColorTransformationNode::ui()
{
    Q_ASSERT(m_transformation);
    ColorTransformationNodeUi *ui = new ColorTransformationNodeUi();
    ui->m_colorTransformationLabel->setText(m_transformation->name());
    ui->m_colorList->setModel(colorModel());
    QWidget *transformationUi = m_transformation->ui();
    if (transformationUi) {
        QHBoxLayout *transformationUiLayout = new QHBoxLayout;
        transformationUiLayout->setMargin(0);
        ui->m_colorTransformationUi->setLayout(transformationUiLayout);
        transformationUiLayout->addWidget(transformationUi);
    }
    return ui;
}

QAbstractItemModel *ColorTransformationNode::colorModel() const
{
    return m_colorModel;
}

void ColorTransformationNode::updateColors()
{
    QVector<Color> input;
    for (int inputId = 0; inputId < m_transformation->inputCount(); inputId++)
        if (m_inputSources[inputId])
            input.append(m_inputSources[inputId]->color());

    m_colors = m_transformation->getOutput(input);
    m_colorModel->setColors(&m_colors);
    emit colorsUpdated();
}

void ColorTransformationNode::connectToSourceNode(ColorTransformationNode *node,
    int colorIndex, int inputSourceIndex)
{
    Q_ASSERT(node);
    Q_ASSERT(inputSourceIndex < m_transformation->inputCount());

    if (m_inputSources[inputSourceIndex])
        delete m_inputSources[inputSourceIndex];
    m_inputSources[inputSourceIndex] = new ColorInputSource(node, colorIndex);
    connect(m_inputSources[inputSourceIndex], SIGNAL(sourceColorUpdated()),
        SLOT(updateColors()));
    updateColors();
}
