#ifndef CLOCK2024_H
#define CLOCK2024_H


#include <QWidget>
#include<QEvent>
#include<QSize>

namespace Ui {
class Clock2024;
}

class Clock2024 : public QWidget
{
    Q_OBJECT

public:
    explicit Clock2024(QWidget *parent = nullptr);
    ~Clock2024();
   QSize sizeHint()const override;
    void mouseMoveEvent(QMouseEvent *event) ;
    void mousePressEvent(QMouseEvent *event) ;

    void resizeEvent(QResizeEvent *event) ;



private:
    Ui::Clock2024 *ui;
    QPoint dragPosition;
};

#endif // CLOCK2024_H
