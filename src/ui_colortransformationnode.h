/********************************************************************************
** Form generated from reading ui file 'colortransformationnode.ui'
**
** Created: Tue 9. Oct 01:00:23 2007
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_COLORTRANSFORMATIONNODE_H
#define UI_COLORTRANSFORMATIONNODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_ColorTransformationNodeUi
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *m_colorTransformationLabel;
    QWidget *m_colorTransformationUi;
    QListView *m_colorList;

    void setupUi(QWidget *ColorTransformationNodeUi)
    {
    if (ColorTransformationNodeUi->objectName().isEmpty())
        ColorTransformationNodeUi->setObjectName(QString::fromUtf8("ColorTransformationNodeUi"));
    ColorTransformationNodeUi->resize(274, 236);
    vboxLayout = new QVBoxLayout(ColorTransformationNodeUi);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    m_colorTransformationLabel = new QLabel(ColorTransformationNodeUi);
    m_colorTransformationLabel->setObjectName(QString::fromUtf8("m_colorTransformationLabel"));

    vboxLayout->addWidget(m_colorTransformationLabel);

    m_colorTransformationUi = new QWidget(ColorTransformationNodeUi);
    m_colorTransformationUi->setObjectName(QString::fromUtf8("m_colorTransformationUi"));

    vboxLayout->addWidget(m_colorTransformationUi);

    m_colorList = new QListView(ColorTransformationNodeUi);
    m_colorList->setObjectName(QString::fromUtf8("m_colorList"));

    vboxLayout->addWidget(m_colorList);


    retranslateUi(ColorTransformationNodeUi);

    QMetaObject::connectSlotsByName(ColorTransformationNodeUi);
    } // setupUi

    void retranslateUi(QWidget *ColorTransformationNodeUi)
    {
    ColorTransformationNodeUi->setWindowTitle(QApplication::translate("ColorTransformationNodeUi", "Form", 0, QApplication::UnicodeUTF8));
    m_colorTransformationLabel->setText(QApplication::translate("ColorTransformationNodeUi", "TextLabel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ColorTransformationNodeUi);
    } // retranslateUi

};

namespace Ui {
    class ColorTransformationNodeUi: public Ui_ColorTransformationNodeUi {};
} // namespace Ui

#endif // UI_COLORTRANSFORMATIONNODE_H
