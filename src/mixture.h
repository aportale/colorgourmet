#ifndef GRADIENT_H
#define GRADIENT_H

#include "colortransformation.h"

class Mixture : public ColorTransformation
{
    Q_OBJECT
    Q_PROPERTY(bool includeInput READ includeInput WRITE setIncludeInput)
    Q_PROPERTY(int steps READ steps WRITE setSteps)

public:
    Mixture(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QWidget *ui();
    QString name() const;

    bool includeInput() const;
    void setIncludeInput(bool include);
    int steps() const;
    void setSteps(int steps);

private:
    bool m_includeInput;
    int m_steps;
};

#endif
