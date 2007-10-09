#ifndef COLORMODEL_H
#define COLORMODEL_H

#include <QAbstractListModel>
#include "color.h"

class ColorModel : public QAbstractListModel
{
public:
    ColorModel(QObject *parent);
    int rowCount(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int itemRole) const;
    void setColors(QVector<Color> *colors);

private:
    QVector<Color> *m_colors;
};

#endif
