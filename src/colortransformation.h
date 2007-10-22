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
    QWidget *ui();
    virtual QString name() const = 0;
    int serialNumber() const;

signals:
    void outputChanged();

protected:
    QWidget *m_ui;
    int m_serialNumber;
};

#endif
