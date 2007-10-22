#include "undocommand.h"
#include <QHash>

UndoCommand::UndoCommand(QUndoCommand * parent)
    : QUndoCommand(parent)
{

}

int UndoCommand::id() const
{
    QObject *pointer = NULL;
    int command = -1;
    pointerAndCommand(pointer, command);
    return id(pointer, command);
}

int UndoCommand::id(QObject *pointer, int command)
{
    int result = -1;
    static QHash<QPair<QObject *, int>, int> ids;
    QPair<QObject *, int> key(pointer, command);
    if (ids.contains(key)) {
        result = ids[key];
    } else {
        result = ids.count();
        ids[key] = result;
    }
    return result;
}
