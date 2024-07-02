#ifndef CLOCK2024_H
#define CLOCK2024_H

#include <QWidget>

namespace Ui {
class Clock2024;
}

class Clock2024 : public QWidget
{
    Q_OBJECT

public:
    explicit Clock2024(QWidget *parent = nullptr);
    ~Clock2024();

private:
    Ui::Clock2024 *ui;
};

#endif // CLOCK2024_H
