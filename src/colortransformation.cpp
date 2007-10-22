#include "colortransformation.h"

ColorTransformation::ColorTransformation(QObject *parent)
    : QObject(parent)
    , m_ui(NULL)
{
    static int serialNumber = 0;
    Q_ASSERT(serialNumber >= 0);
    m_serialNumber = serialNumber;
    serialNumber++;
}

QWidget *ColorTransformation::ui()
{
    return m_ui;
}

int ColorTransformation::serialNumber() const
{
    return m_serialNumber;
}
