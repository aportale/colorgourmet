#include "colormodel.h"

ColorModel::ColorModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ColorModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_colors->count();
}

QVariant ColorModel::data(const QModelIndex &index, int itemRole) const
{
    if (!index.isValid())
        return QVariant();

    if (itemRole == Qt::DisplayRole)
        return m_colors->at(index.row()).description();
    else if (itemRole == Qt::DecorationRole)
        return m_colors->at(index.row()).displayColor(1);
    else
        return QVariant();
}

void ColorModel::setColors(QVector<Color> *colors)
{
    m_colors = colors;
    emit reset();
}
