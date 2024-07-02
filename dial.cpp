#include <QtWidgets>
#include <QTime>
#include "shapedclock.h"

ShapedClock::ShapedClock(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    QAction *quitAction = new QAction(tr("Exit"), this);
    QAction *changeAction = new QAction(tr("Change"), this);
    QAction *sizeupAction = new QAction(tr("Size Up"), this);
    QAction *sizedownAction = new QAction(tr("Size Down"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    addAction(quitAction);
    addAction(changeAction);
    addAction(sizeupAction);
    addAction(sizedownAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);
    setToolTip(tr("Drag the clock with the left mouse button.\n"
                  "Use the right mouse button to open a context menu."));
    setWindowTitle(tr("Shaped Analog Clock"));
}

