#ifndef ANALOGOUS_H
#define ANALOGOUS_H

#include "colortransformation.h"

class Analogous : public ColorTransformation
{
    Q_OBJECT
    Q_PROPERTY(bool includeInput READ includeInput WRITE setIncludeInput)
    Q_PROPERTY(double angle READ angle WRITE setAngle)

public:
    Analogous(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QWidget *ui();
    QString name() const;

    double angle() const;
    bool includeInput() const;

signals:
    void angleChanged(double angle);
    void includeInputChanged(bool include);

public slots:
    void setAngle(double angle);
    void setIncludeInput(bool include);

private:
    bool m_includeInput;
    double m_angle;
    int m_analogousColorsCount;
    QWidget *m_ui;
};

#endif
