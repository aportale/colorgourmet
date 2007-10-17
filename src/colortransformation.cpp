#include "colortransformation.h"

ColorTransformation::ColorTransformation(QObject *parent)
    : QObject(parent)
    , m_ui(NULL)
{
}

QWidget *ColorTransformation::ui()
{
    return m_ui;
}
