#include "clock.h"

Clock::Clock(QWidget *parent)
    :QLabel (parent)
{
    //创建定时器
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

//    QAction *quitAction = new QAction("Exit", this);
//    quitAction->setShortcut(tr("Ctrl+Q"));
//    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
//    addAction(quitAction);

//    setContextMenuPolicy(Qt::ActionsContextMenu);
//    setToolTip("Drag the clock with the left mouse button.\n"
//                  "Use the right mouse button to open a context menu.");
//    setWindowTitle("2024NwafuClock");
}

void Clock::paintEvent(QPaintEvent *)
{
    static const QPoint hour[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint min[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    static const QPoint sec[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -100)
    };

    QColor hourColor(0, 153, 76);
    QColor minColor(0, 127, 127, 180);
    QColor secColor(153, 255, 104, 174);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    //绘制刻度线
    for (int m = 0; m < 12; m++)
    {
        painter.setPen(Qt::darkGreen);
        painter.setFont(QFont("微软雅黑",9));
        if (m == 3)
            painter.drawText(QPoint(68,8),"3");
    }
    for (int m = 0; m < 12; m++)
    {
        painter.setPen(Qt::darkGreen);
        painter.setFont(QFont("微软雅黑",9));
        if (m == 6)
            painter.drawText(QPoint(-4,78),"6");
    }
    for (int m = 0; m < 12; m++)
    {
        painter.setPen(Qt::darkGreen);
        painter.setFont(QFont("微软雅黑",9));
        if (m == 9)
            painter.drawText(QPoint(-74,8),"9");
    }
    for (int m = 0; m < 12; m++)
    {
        painter.setPen(Qt::darkGreen);
        painter.setFont(QFont("微软雅黑",9));
        if (m == 0)
            painter.drawText(QPoint(-10,-64),"12");
    }
    for (int i = 0; i < 12; i++)
    {
        painter.setPen(Qt::darkGreen);
        if ((i % 3) == 0)
            painter.drawLine(80, 0, 96, 0);
        painter.rotate(90.0);
    }
    for (int i = 0; i < 12; i++)
    {
        painter.setPen(Qt::darkGreen);
        if ((i % 3) != 0)
            painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
    for (int j = 0; j < 60; j++)
    {
        painter.setPen(Qt::black);
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hour, 3);
    painter.restore();

    painter.setPen(Qt::NoPen);
    painter.setBrush(minColor);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(min, 3);
    painter.restore();

    painter.setPen(Qt::NoPen);
    painter.setBrush(secColor);
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(sec, 3);
    painter.restore();

}

