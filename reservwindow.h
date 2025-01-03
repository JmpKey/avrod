#ifndef RESERVWINDOW_H
#define RESERVWINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class ReservWindow;
}

class ReservWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReservWindow(QWidget *parent = nullptr);
    ~ReservWindow();

private slots:
    void on_pb_enter_clicked();

signals:
    void sendDataResWin(QString fio, QString tel, int route, int place, double price);

private:
    Ui::ReservWindow *ui;
};

#endif // RESERVWINDOW_H
