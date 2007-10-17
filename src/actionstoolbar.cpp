#include "actionstoolbar.h"
#include "undostack.h"
#include <QIcon>
#include <QAction>

ActionsToolbar::ActionsToolbar(QWidget *parent)
    : QToolBar(parent)
{
    m_undoAction = UndoStack::instance()->createUndoAction(this);
    m_undoAction->setIcon(QIcon(":/icons/undo.png"));
    addAction(m_undoAction);
    m_redoAction = UndoStack::instance()->createRedoAction(this);
    m_redoAction->setIcon(QIcon(":/icons/redo.png"));
    addAction(m_redoAction);
}
