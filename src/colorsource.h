#ifndef COLORSOURCE_H
#define COLORSOURCE_H

#include "colortransformation.h"
#include "color.h"

class ColorSource : public ColorTransformation
{
    Q_OBJECT
    Q_PROPERTY(Color color READ color WRITE setColor)

public:
    ColorSource(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QString name() const;

    Color color() const;

signals:
    void colorChanged(const Color &color);

public slots:
    void setColor(const Color &color);
    void setColorComponent(int componentId, double value);

private:
    Color m_color;
};

#endif
