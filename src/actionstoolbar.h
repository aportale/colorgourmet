#ifndef ACTIONSTOOLBAR_H
#define ACTIONSTOOLBAR_H

#include <QToolBar>

class ActionsToolbar : public QToolBar
{
    Q_OBJECT

public:
    ActionsToolbar(QWidget *parent = 0);

private:
    QAction *m_undoAction;
    QAction *m_redoAction;
};

#endif
