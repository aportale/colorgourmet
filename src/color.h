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
    Color(ColorSpace colorSpace, const QVector<double> &components);

    void setComponents(const QVector<double> &components);
    QVector<double> components() const;
    void setComponentValue(int componentId, double value);
    double componentValue(int componentId) const;
    void setName(const QString &name);
    QString name() const;
    ColorSpace colorSpace() const;
    QString colorSpaceName() const;
    static QString colorSpaceName(ColorSpace colorSpace);
    QVector<double> pcsColor() const;
    Color convertToColorConversionSpace() const;
    Color convertToColorSpace(ColorSpace targetColorSpace) const;
    QString description() const;
    QColor displayColor(int displayId = 0) const;

private:
    ColorSpace m_colorSpace;
    QVector<double> m_components;
    QString m_name;

    void setColorSpace(ColorSpace colorSpace);
};

#endif
