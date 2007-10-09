/********************************************************************************
** Form generated from reading ui file 'colorsource.ui'
**
** Created: Tue 9. Oct 01:00:23 2007
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_COLORSOURCE_H
#define UI_COLORSOURCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

class Ui_ColorSourceUi
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *component0SpinBox;
    QLabel *label_2;
    QDoubleSpinBox *component1SpinBox;
    QLabel *label_3;
    QDoubleSpinBox *component2SpinBox;

    void setupUi(QWidget *ColorSourceUi)
    {
    if (ColorSourceUi->objectName().isEmpty())
        ColorSourceUi->setObjectName(QString::fromUtf8("ColorSourceUi"));
    ColorSourceUi->resize(316, 72);
    gridLayout = new QGridLayout(ColorSourceUi);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(ColorSourceUi);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    component0SpinBox = new QDoubleSpinBox(ColorSourceUi);
    component0SpinBox->setObjectName(QString::fromUtf8("component0SpinBox"));
    component0SpinBox->setMaximum(255);

    gridLayout->addWidget(component0SpinBox, 0, 1, 1, 1);

    label_2 = new QLabel(ColorSourceUi);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    component1SpinBox = new QDoubleSpinBox(ColorSourceUi);
    component1SpinBox->setObjectName(QString::fromUtf8("component1SpinBox"));
    component1SpinBox->setMaximum(255);

    gridLayout->addWidget(component1SpinBox, 1, 1, 1, 1);

    label_3 = new QLabel(ColorSourceUi);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    component2SpinBox = new QDoubleSpinBox(ColorSourceUi);
    component2SpinBox->setObjectName(QString::fromUtf8("component2SpinBox"));
    component2SpinBox->setMaximum(255);

    gridLayout->addWidget(component2SpinBox, 2, 1, 1, 1);


    retranslateUi(ColorSourceUi);

    QMetaObject::connectSlotsByName(ColorSourceUi);
    } // setupUi

    void retranslateUi(QWidget *ColorSourceUi)
    {
    ColorSourceUi->setWindowTitle(QApplication::translate("ColorSourceUi", "Form", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ColorSourceUi", "Red:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("ColorSourceUi", "Green:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("ColorSourceUi", "Blue:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ColorSourceUi);
    } // retranslateUi

};

namespace Ui {
    class ColorSourceUi: public Ui_ColorSourceUi {};
} // namespace Ui

#endif // UI_COLORSOURCE_H
