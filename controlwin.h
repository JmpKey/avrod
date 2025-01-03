#ifndef CONTROLWIN_H
#define CONTROLWIN_H

#include <QDialog>

namespace Ui {
class ControlWin;
}

class ControlWin : public QDialog
{
    Q_OBJECT

public:
    explicit ControlWin(QWidget *parent = nullptr);
    ~ControlWin();

private slots:
    void on_pb_enter_clicked();

signals:
    void sendDataCont(QString ticket);

private:
    Ui::ControlWin *ui;
};

#endif // CONTROLWIN_H
