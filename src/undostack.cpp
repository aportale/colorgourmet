#include "undostack.h"
#include <QApplication>
#include <QWidget>

UndoStack::UndoStack(QObject *parent)
    : QUndoStack(parent)
{
}

UndoStack *UndoStack::instance()
{
    static UndoStack *undoStack = new UndoStack(QApplication::activeWindow());
    return undoStack;
}
