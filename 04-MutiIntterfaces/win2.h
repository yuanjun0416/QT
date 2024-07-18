#ifndef WIN2_H
#define WIN2_H

#include <QWidget>

namespace Ui {
class win2;
}

class win2 : public QWidget
{
    Q_OBJECT

public:
    explicit win2(QWidget *parent = nullptr);
    ~win2();

signals:
    void back();

private:
    Ui::win2 *ui;
};

#endif // WIN2_H
