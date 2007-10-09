#ifndef COLORTRANSFORMATIONNODEUI_H
#define COLORTRANSFORMATIONNODEUI_H

#include <QWidget>
#include "ui_colortransformationnode.h"

class ColorTransformationNodeUi : public QWidget, public Ui::ColorTransformationNodeUi
{
    Q_OBJECT

public:
    ColorTransformationNodeUi(QWidget *parent = 0);
};

#endif
