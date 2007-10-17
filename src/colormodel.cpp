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

    const Color &color = m_colors->at(index.row());

    if (itemRole == Qt::DisplayRole)
        return color.description();
    else if (itemRole == Qt::DecorationRole)
        return color.displayColor(0);
    else if (itemRole == Qt::ToolTipRole)
        return toolTipForColor(color);
    else
        return QVariant();
}

void ColorModel::setColors(QVector<Color> *colors)
{
    m_colors = colors;
    emit reset();
}

QString ColorModel::toolTipForColor(const Color &color)
{
    Color::ColorSpace colorSpaces[] = {Color::sRgb, Color::sRgbHsv};

    QString result = "<html><body><table cellpadding=\"2\">";
    for (size_t i = 0; i < sizeof(colorSpaces)/sizeof(colorSpaces[0]); i++) {
        QString row = "<tr>";
        row += QString("<th align=\"left\">%1</th>")
            .arg(Color::colorSpaceName(colorSpaces[i]));
        foreach (double component, color.convertToColorSpace(colorSpaces[i]).components())
            row += QString("<td align=\"right\">%1</td>").arg(int(component));
        row += "</tr>";
        result += row;
    }
    result += "</table></body></html>";

    return result;
}
