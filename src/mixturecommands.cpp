#include "mixturecommands.h"
#include "mixture.h"

MixtureStepsCountCommand::MixtureStepsCountCommand(Mixture *mixture, int count, QUndoCommand *parent)
    : UndoCommand(parent)
    , m_mixture(mixture)
    , m_oldCount(mixture->stepsCount())
    , m_count(count)
{
    setText(Mixture::tr("Set the amount of mixture steps to %1").arg(count));
}

void MixtureStepsCountCommand::undo()
{
    m_mixture->setStepsCount(m_oldCount);
}

void MixtureStepsCountCommand::redo()
{
    m_mixture->setStepsCount(m_count);
}

bool MixtureStepsCountCommand::mergeWith(const QUndoCommand *command)
{
    const MixtureStepsCountCommand *otherCommand = static_cast<const MixtureStepsCountCommand*>(command);
    setText(otherCommand->text());
    m_count = otherCommand->m_count;
    return true;
}

void MixtureStepsCountCommand::pointerAndCommand(QObject *&pointer, int &command) const
{
    pointer = m_mixture;
    command = MixtureCommands::StepsCount;
}
