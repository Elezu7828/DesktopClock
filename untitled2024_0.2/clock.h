#ifndef CLOCK_H
#define CLOCK_H
#include<QLabel>
#include<QPainter>
#include<QAction>
#include<QApplication>
#include<QTimer>
#include<QDateTime>

//定义一个Clock类，继承自QLabel
class Clock : public QLabel
{
    Q_OBJECT

public:
    Clock(QWidget *parent = nullptr);

protected:
    //重写paintEvent函数
    void paintEvent(QPaintEvent *)override;

};
#endif // CLOCK_H
