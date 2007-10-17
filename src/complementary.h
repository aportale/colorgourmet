#ifndef COMPLEMENTARY_H
#define COMPLEMENTARY_H

#include "colortransformation.h"

class Complementary : public ColorTransformation
{
    Q_OBJECT

public:
    Complementary(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QString name() const;
};

#endif
