#include <QSize>
#include "shapedclock.h"
#include <QtWidgets>

void ShapedClock::resizeEvent(QResizeEvent * /* event */)
{
   int side = qMin(width(), height());
   QRegion maskedRegion(width() / 2 - side / 2, height() / 2 - side / 2, side,
                        side, QRegion::Ellipse);
   setMask(maskedRegion);
}

QSize ShapedClock::sizeHint() const
{
    return QSize(500, 500);
}
