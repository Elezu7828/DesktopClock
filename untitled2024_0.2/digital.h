#ifndef TIME_DATE_WIDGET_H
#define TIME_DATE_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include<QLabel>
#include<QTimer>
#include <QDialog>
#include<QLCDNumber>

#include <QLineEdit>

// 定义 TimeDateWidget 类，继承自 QWidget
class TimeDateWidget : public QWidget
{
    Q_OBJECT

public:
    // 构造函数，接受父窗口指针作为参数，默认为 nullptr
    TimeDateWidget(QWidget *parent = nullptr);

private slots:
    // 槽函数，用于更新时间和日期的显示
    void updateTimeAndDate();
    // 槽函数，用于显示设置时间和日期的对话框
    void showSetDialog();

private:
    // 用于显示时间的标签指针
    QLCDNumber *timeQLCD;
    // 用于显示日期的标签指针
    QLabel *dateLabel;
    // 用于触发设置操作的按钮指针
    QPushButton *setButton;
};

#endif // TIME_DATE_WIDGET_H
