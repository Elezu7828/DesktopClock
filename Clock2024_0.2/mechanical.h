#ifndef MECHANICAL_H
#define MECHANICAL_H


#include <QWidget>
#include<QEvent>
#include<QSize>

namespace MechanicalUi {
class Mechanical;
}

class Mechanical : public QWidget
{
    Q_OBJECT

public:
    explicit Mechanical(QWidget *parent = nullptr);
    ~Mechanical()override;
   QSize sizeHint()const override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;



private:
    MechanicalUi::Mechanical *ui;
    QPoint dragPosition;
};

#endif // CLOCK2024_H
