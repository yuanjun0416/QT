#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qdebug.h>
#include <QFileDialog>
#include <QString>
#include <QPixmap>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void select_radioButton();

private slots:
    void on_pushButton_select_clicked();

    void on_pushButton_preview_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QPixmap newmap;
    QString filePath;
    qint32 width;
    qint32 height;
};
#endif // WIDGET_H
