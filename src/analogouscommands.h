#ifndef ANALOGOUSCOMMANDS_H
#define ANALOGOUSCOMMANDS_H

#include "undocommand.h"

class Analogous;

class AnalogousCommands
{
public:
    enum Commands {
        ColorsCount,
        Angle,
        IncludeInput
    };
};

class AnalogousColorsCountCommand : public UndoCommand
{
public:
    AnalogousColorsCountCommand(Analogous *analogous, int count, QUndoCommand *parent = 0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    void pointerAndCommand(QObject *&pointer, int &command) const;

private:
    Analogous *m_analogous;
    int m_oldCount;
    int m_count;
};

class AnalogousAngleCommand : public UndoCommand
{
public:
    AnalogousAngleCommand(Analogous *analogous, double angle, QUndoCommand *parent = 0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    void pointerAndCommand(QObject *&pointer, int &command) const;

private:
    Analogous *m_analogous;
    double m_oldAngle;
    double m_angle;
};

class AnalogousIncludeInputCommand : public UndoCommand
{
public:
    AnalogousIncludeInputCommand(Analogous *analogous, bool include, QUndoCommand *parent = 0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    void pointerAndCommand(QObject *&pointer, int &command) const;

private:
    Analogous *m_analogous;
    bool m_oldInclude;
    bool m_include;
};

#endif
