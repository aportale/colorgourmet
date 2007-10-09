#ifndef COLORTRANSFORMATION_H
#define COLORTRANSFORMATION_H

#include <QObject>
#include "color.h"

class QWidget;

class ColorTransformation : public QObject
{
    Q_OBJECT

public:
    ColorTransformation(QObject *parent = 0);

    virtual int inputCount() const = 0;
    virtual QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const = 0;
    virtual QWidget *ui() = 0;
    virtual QString name() const = 0;

signals:
    void outputChanged();
};

#endif
