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
    void componentChanged(int componentId, double value);

public slots:
    void setComponents(double component0, double component1, double component2, double component3);

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

signals:
    void colorChanged(double component0, double component1, double component2, double component3);

private slots:
    void handleModelColorChanged(const Color &color);
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

signals:
    void colorChanged(const Color &color);

public slots:
    void setColor(const Color &color);
    void setColorComponent(int componentId, double value);

private:
    Color m_color;
    QWidget *m_ui;
};

#endif
