#include <QtWidgets>
#include<QEvent>
#include "mechanical.h"
#include "ui_clock2024.h"


Mechanical::~Mechanical()
{
    //delete ui;
}

Mechanical::Mechanical(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint|Qt::WindowSystemMenuHint)
{


    //创建菜单
    QAction *quitAction = new QAction(tr("退出"), this);
    QAction *changeAction = new QAction(tr("切换为电子表"), this);
    QAction *sizeupAction = new QAction(tr("增大"), this);
    QAction *sizedownAction = new QAction(tr("缩小"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    addAction(quitAction);
    addAction(changeAction);
    addAction(sizeupAction);
    addAction(sizedownAction);


    setContextMenuPolicy(Qt::ActionsContextMenu);
    setToolTip(tr("使用左键拖动时钟。\n"
                  "使用右键打开上下文菜单。"));
    setWindowTitle(tr("Shaped Analog Clock"));
}

void Mechanical::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void Mechanical::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
#include <QSize>


void Mechanical::resizeEvent(QResizeEvent * )
{
   int side = qMin(width(), height());
   QRegion maskedRegion(width() / 2 - side / 2, height() / 2 - side / 2, side,
                       side, QRegion::Ellipse);
  setMask(maskedRegion);
}


QSize Mechanical::sizeHint() const
{
    return QSize(300, 300);
}

