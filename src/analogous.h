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

    int analogousColorsCount() const;
    double angle() const;
    bool includeInput() const;

signals:
    void analogousColorsCountChanged(int count);
    void angleChanged(double angle);
    void includeInputChanged(bool include);

public slots:
    void setAnalogousColorsCount(int count);
    void setAngle(double angle);
    void setIncludeInput(bool include);

private:
    int m_analogousColorsCount;
    double m_angle;
    bool m_includeInput;
    QWidget *m_ui;
};

#endif
