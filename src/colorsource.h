#ifndef COLORSOURCE_H
#define COLORSOURCE_H

#include "colortransformation.h"
#include "color.h"
#include "ui_colorsource.h"

class ColorSource;

class ColorSourceUi : public QWidget, public Ui::ColorSourceUi
{
    Q_OBJECT

public:
    ColorSourceUi(QWidget *parent = 0);

signals:
    void componentChanged(int componentId, qreal value);

private slots:
    void on_component0SpinBox_valueChanged(double value);
    void on_component1SpinBox_valueChanged(double value);
    void on_component2SpinBox_valueChanged(double value);
    void on_component3SpinBox_valueChanged(double value);
};

class ColorSourceUiController : public QObject
{
    Q_OBJECT

public:
    ColorSourceUiController(QObject *parent = 0);
    void connectToModelAndView(QObject *model, QWidget *view);
};

class ColorSource : public ColorTransformation
{
    Q_OBJECT
    Q_PROPERTY(Color color READ color WRITE setColor)

public:
    ColorSource(QObject *parent = 0);

    int inputCount() const;
    QVector<Color> getOutput(const QVector<Color> &input = QVector<Color>()) const;
    QWidget *ui();
    QString name() const;

    Color color() const;

public slots:
    void setColor(const Color &color);
    void setColorComponent(int componentId, qreal value);

private:
    Color m_color;
    ColorSourceUiController *m_uiController;
};

#endif
