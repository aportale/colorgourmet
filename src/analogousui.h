#ifndef ANALOGOUSUI_H
#define ANALOGOUSUI_H

#include <QWidget>
#include <QUndoCommand>
#include "ui_analogous.h"

class Analogous;

class AnalogousUi : public QWidget, public Ui::AnalogousUi
{
    Q_OBJECT

public:
    AnalogousUi(Analogous *analogous, QWidget *parent = 0);

public slots:
    void on_analogousColorsCountSpinbox_valueChanged(int value);
    void on_angleSpinBox_valueChanged(double value);

private:
    Analogous *m_analogous;
};

class AnalogousColorsCountCommand : public QUndoCommand
{
public:
    AnalogousColorsCountCommand(Analogous *analogous, int count, QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    Analogous *m_analogous;
    int m_oldCount;
    int m_count;
};

class AnalogousAngleCommand : public QUndoCommand
{
public:
    AnalogousAngleCommand(Analogous *analogous, double angle, QUndoCommand *parent = 0);
    void undo();
    void redo();

private:
    Analogous *m_analogous;
    double m_oldAngle;
    double m_angle;
};

#endif
