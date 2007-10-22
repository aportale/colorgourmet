#ifndef MIXTURECOMMANDS_H
#define MIXTURECOMMANDS_H

#include "undocommand.h"

class Mixture;

class MixtureCommands
{
public:
    enum Commands {
        StepsCount,
        IncludeInput
    };
};

class MixtureStepsCountCommand : public UndoCommand
{
public:
    MixtureStepsCountCommand(Mixture *mixture, int count, QUndoCommand *parent = 0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    void pointerAndCommand(QObject *&pointer, int &command) const;

private:
    Mixture *m_mixture;
    int m_oldCount;
    int m_count;
};

#endif
