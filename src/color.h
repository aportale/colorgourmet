#ifndef COLOR_H
#define COLOR_H

#include <QVector>
#include <QString>
#include <QColor>

class Color
{
public:
    enum ColorSpace {
        sRgb,
        monitorRgb,
        euroScaleCmyk,
        printerCmyk,
        sRgbHsv
    };

    Color();
    Color(ColorSpace colorSpace, const QVector<qreal> &components);

    void setComponents(const QVector<qreal> &components);
    QVector<qreal> components() const;
    void setComponentValue(int componentId, qreal value);
    void setName(const QString &name);
    QString name() const;
    ColorSpace colorSpace() const;
    QVector<qreal> pcsColor() const;
    Color convertToColorConversionSpace() const;
    Color convertToColorSpace(ColorSpace targetColorSpace) const;
    QString description() const;
    QColor displayColor(int displayId = 0) const;

private:
    ColorSpace m_colorSpace;
    QVector<qreal> m_components;
    QString m_name;

    void setColorSpace(ColorSpace colorSpace);
};

#endif
