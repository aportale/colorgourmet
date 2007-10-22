#include "analogouscommands.h"
#include "analogous.h"

AnalogousColorsCountCommand::AnalogousColorsCountCommand(Analogous *analogous, int count, QUndoCommand *parent)
    : UndoCommand(parent)
    , m_analogous(analogous)
    , m_oldCount(analogous->analogousColorsCount())
    , m_count(count)
{
    setText(Analogous::tr("Set the amount of analog colors to %1").arg(count));
}

void AnalogousColorsCountCommand::undo()
{
    m_analogous->setAnalogousColorsCount(m_oldCount);
}

void AnalogousColorsCountCommand::redo()
{
    m_analogous->setAnalogousColorsCount(m_count);
}

bool AnalogousColorsCountCommand::mergeWith(const QUndoCommand *command)
{
    const AnalogousColorsCountCommand *otherCommand = static_cast<const AnalogousColorsCountCommand*>(command);
    setText(otherCommand->text());
    m_count = otherCommand->m_count;
    return true;
}

void AnalogousColorsCountCommand::pointerAndCommand(QObject *&pointer, int &command) const
{
    pointer = m_analogous;
    command = AnalogousCommands::ColorsCount;
}

AnalogousAngleCommand::AnalogousAngleCommand(Analogous *analogous, double angle, QUndoCommand *parent)
    : UndoCommand(parent)
    , m_analogous(analogous)
    , m_oldAngle(analogous->angle())
    , m_angle(angle)
{
    setText(Analogous::tr("Set the angle of analog colors to %1").arg(angle));
}

void AnalogousAngleCommand::undo()
{
    m_analogous->setAngle(m_oldAngle);
}

void AnalogousAngleCommand::redo()
{
    m_analogous->setAngle(m_angle);
}

bool AnalogousAngleCommand::mergeWith(const QUndoCommand *command)
{
    const AnalogousAngleCommand *otherCommand = static_cast<const AnalogousAngleCommand*>(command);
    setText(otherCommand->text());
    m_angle = otherCommand->m_angle;
    return true;
}

void AnalogousAngleCommand::pointerAndCommand(QObject *&pointer, int &command) const
{
    pointer = m_analogous;
    command = AnalogousCommands::Angle;
}

AnalogousIncludeInputCommand::AnalogousIncludeInputCommand(Analogous *analogous, bool include, QUndoCommand *parent)
    : UndoCommand(parent)
    , m_analogous(analogous)
    , m_oldInclude(analogous->includeInput())
    , m_include(include)
{
    setText(include?Analogous::tr("Include the input color"):
        Analogous::tr("Exclude the input color"));
}

void AnalogousIncludeInputCommand::undo()
{
    m_analogous->setIncludeInput(m_oldInclude);
}

void AnalogousIncludeInputCommand::redo()
{
    m_analogous->setIncludeInput(m_include);
}

bool AnalogousIncludeInputCommand::mergeWith(const QUndoCommand *command)
{
    const AnalogousIncludeInputCommand *otherCommand = static_cast<const AnalogousIncludeInputCommand*>(command);
    setText(otherCommand->text());
    m_include = otherCommand->m_include;
    return true;
}

void AnalogousIncludeInputCommand::pointerAndCommand(QObject *&pointer, int &command) const
{
    pointer = m_analogous;
    command = AnalogousCommands::IncludeInput;
}
