#ifndef COLORTRANSFORMATIONNODE_H
#define COLORTRANSFORMATIONNODE_H

#include <QObject>
#include <QPointer>
#include <QAbstractItemModel>
#include "color.h"

class ColorTransformation;
class ColorTransformationNode;
class ColorModel;

class ColorInputSource : public QObject
{
    Q_OBJECT

public:
    ColorInputSource(ColorTransformationNode *sourceNode, int colorIndex,
        QObject *parent = 0);
    Color color() const;

signals:
    void sourceColorUpdated();

private:
    QPointer<ColorTransformationNode> m_sourceNodePointer;
    int m_sourceColorIndex;
};

class ColorTransformationNode : public QObject
{
    Q_OBJECT

public:
    ColorTransformationNode(ColorTransformation *colorTransformation,
        QObject *parent = 0);
    ~ColorTransformationNode();
    const QVector<Color> &colors() const;
    QWidget *ui();
    QAbstractItemModel *colorModel() const;

signals:
    void colorsUpdated();

public slots:
    void updateColors();
    void connectToSourceNode(ColorTransformationNode *node,
        int colorIndex, int inputSourceIndex = 0);

private:
    QVector<ColorInputSource*> m_inputSources;
    ColorTransformation *m_transformation;
    QVector<Color> m_colors;
    ColorModel *m_colorModel;
};

#endif
