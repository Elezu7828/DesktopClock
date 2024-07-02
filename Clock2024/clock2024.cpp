#include <QtWidgets>
#include<QEvent>
#include "clock2024.h"
#include "ui_clock2024.h"


Clock2024::~Clock2024()
{
    //delete ui;
}

Clock2024::Clock2024(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint|Qt::WindowSystemMenuHint)
{


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

void Clock2024::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Clock2024::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
#include <QSize>


void Clock2024::resizeEvent(QResizeEvent * )
{
   int side = qMin(width(), height());
   QRegion maskedRegion(width() / 2 - side / 2, height() / 2 - side / 2, side,
                       side, QRegion::Ellipse);
  setMask(maskedRegion);
}


QSize Clock2024::sizeHint() const
{
    return QSize(500, 500);
}

