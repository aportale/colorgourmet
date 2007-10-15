#ifndef GRADIENT_H
#define GRADIENT_H

#include "colortransformation.h"

class Mixture : public ColorTransformation
{
    Q_OBJECT
    Q_PROPERTY(int stepsCount READ stepsCount WRITE setStepsCount)
    Q_PROPERTY(bool includeInput READ includeInput WRITE setIncludeInput)

public:
    Mixture(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QWidget *ui();
    QString name() const;

signals:
    void stepsCountChanged(int steps);
    void includeInputChanged(bool include);

public slots:
    int stepsCount() const;
    void setStepsCount(int steps);
    bool includeInput() const;
    void setIncludeInput(bool include);

private:
    int m_stepsCount;
    bool m_includeInput;
    QWidget *m_ui;
};

#endif
