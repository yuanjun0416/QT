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

private slots:
    void on_closewin2_clicked();

    void receive_from_mainwindow(QString data);

    void on_sendtowin1_clicked();

signals:
    void send_to_mainwindow(QString data);

private:
    Ui::win2 *ui;
};

#endif // WIN2_H
