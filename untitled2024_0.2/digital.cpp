#include "digital.h"
#include <QApplication>
#include<QLCDNumber>
#include <QLabel>
#include <QDateTime>
#include<QDateTimeEdit>
#include <QHBoxLayout>
#include <QSettings>
#include<QLCDNumber>

// 构造函数的实现
TimeDateWidget::TimeDateWidget(QWidget *parent) : QWidget(parent)
{


    // 创建水平布局，并将其设置为当前窗口的布局
    QGridLayout *layout = new QGridLayout(this);

    // 创建用于显示时间的标签
    timeQLCD = new QLCDNumber(this);
    // 创建用于显示日期的标签
    dateLabel = new QLabel(this);

    // 将时间标签和日期标签添加到布局中
    layout->addWidget(timeQLCD);
    layout->addWidget(dateLabel);

    //更改时间标签和日期标签的字体大小
    timeQLCD->setStyleSheet("font-size:50px;");
    dateLabel->setStyleSheet("font-size:23px; font-family:微软雅黑;");
    // 初始时更新时间和日期的显示
    updateTimeAndDate();

    // 创建定时器
    QTimer *timer = new QTimer(this);
    // 将定时器的超时信号与更新时间和日期的槽函数连接
    connect(timer, &QTimer::timeout, this, &TimeDateWidget::updateTimeAndDate);
    // 启动定时器，每 1000 毫秒触发一次超时信号
    timer->start(1000);

    // 创建设置按钮
    setButton = new QPushButton("change", this);
    // 将设置按钮的点击信号与显示设置对话框的槽函数连接
    connect(setButton, &QPushButton::clicked, this, &TimeDateWidget::showSetDialog);
    // 将设置按钮添加到布局中
    layout->addWidget(setButton);
}

// 更新时间和日期显示的槽函数
void TimeDateWidget::updateTimeAndDate()
{
    // 获取当前的日期时间
    QDateTime current = QDateTime::currentDateTime();
    // 将当前时间以"hh:mm:ss"格式设置到时间标签的文本中
//    timeLabel->setText(current.toString("hh:mm:ss"));
    // 获取当前时间
    QTime currentTime = current.time();
    // 将当前时间设置到QLCDNumber中
    timeQLCD->display(currentTime.toString("hh:mm:ss"));
    timeQLCD->setDigitCount(8);
    timeQLCD->setSegmentStyle(QLCDNumber::Flat);

    // 将当前日期以"ddd yyyy-MM-dd"格式设置到日期标签的文本中
    dateLabel->setText(current.toString("ddd yyyy-MM-dd"));
}

// 显示设置时间和日期对话框的槽函数
void TimeDateWidget::showSetDialog()
{
    // 创建一个对话框，并指定其父窗口为当前窗口
    QDialog dialog(this);
    // 为对话框创建垂直布局
    QVBoxLayout *dialogLayout = new QVBoxLayout(&dialog);

    // 创建用于输入时间的编辑框
    QLineEdit *timeEdit = new QLineEdit(&dialog);
    // 创建用于输入日期的编辑框
    QLineEdit *dateEdit = new QLineEdit(&dialog);

    // 创建确定按钮
    QPushButton *okButton = new QPushButton("确定", &dialog);
    // 将确定按钮的点击信号与对话框的接受信号连接
    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    // 在对话框布局中添加时间输入的提示标签
    dialogLayout->addWidget(new QLabel("设置时间(hh:mm:ss):"));
    // 在对话框布局中添加时间输入编辑框
    dialogLayout->addWidget(timeEdit);
    // 在对话框布局中添加日期输入的提示标签
    dialogLayout->addWidget(new QLabel("设置日期(yyyy-MM-dd):"));
    // 在对话框布局中添加日期输入编辑框
    dialogLayout->addWidget(dateEdit);
    // 在对话框布局中添加确定按钮
    dialogLayout->addWidget(okButton);

    // 如果对话框被接受（即点击了确定按钮）
    if (dialog.exec() == QDialog::Accepted)
    {
        // 获取输入的时间字符串
        QString timeStr = timeEdit->text();
        // 获取输入的日期字符串
        QString dateStr = dateEdit->text();

        // 将输入的时间字符串转换为 QTime 对象
        QTime time = QTime::fromString(timeStr, "hh:mm:ss");
        // 将输入的日期字符串转换为 QDate 对象
        QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");

        // 如果时间和日期输入有效
        if (time.isValid() && date.isValid())
        {
            // 创建包含输入时间和日期的 QDateTime 对象
            QDateTime setDateTime(date, time);
            // 将设置的时间以"hh:mm:ss"格式设置到时间标签的文本中
//            timeLabel->setText(setDateTime.toString("hh:mm:ss"));
            // 将设置的日期以"yyyy-MM-dd"格式设置到日期标签的文本中
            dateLabel->setText(setDateTime.toString("yyyy-MM-dd"));
        }
        else
        {
            // 处理输入无效的情况
            // 例如弹出提示消息
        }
    }
}

