#include "mainwindow.h"
#include "actionstoolbar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    addToolBar(new ActionsToolbar);
}
