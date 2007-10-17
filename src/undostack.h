#ifndef UNDOSTACK_H
#define UNDOSTACK_H

#include <QUndoStack>

class UndoStack : public QUndoStack
{
    Q_OBJECT

public:
    static UndoStack *instance();

private:
    UndoStack(QObject *parent = 0);
};

#endif
