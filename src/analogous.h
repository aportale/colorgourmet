#ifndef ANALOGOUS_H
#define ANALOGOUS_H

#include "colortransformation.h"

class Analogous : public ColorTransformation
{
    Q_OBJECT
    Q_PROPERTY(qreal angle READ angle WRITE setAngle)

public:
    Analogous(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QWidget *ui();
    QString name() const;

    bool includeInput() const;
    void setIncludeInput(bool include);
    qreal angle() const;
    void setAngle(qreal angle);

private:
    bool m_includeInput;
    qreal m_angle;
    int m_analogousColorsCount;
};

#endif
