#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include <QUndoCommand>

class UndoCommand : public QUndoCommand
{
public:
    UndoCommand(QUndoCommand * parent = 0);
    int id() const;
    virtual void pointerAndCommand(QObject *&pointer, int &command) const = 0;
    static int id(QObject *pointer, int command);
};

#endif
