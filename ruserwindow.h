#ifndef RUSERWINDOW_H
#define RUSERWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class RUserWindow;
}

class RUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RUserWindow(QWidget *parent = nullptr);
    ~RUserWindow();

private slots:
    void on_pb_registr_clicked();

signals:
    void sendDataR(QString uname, QString upass);

private:
    Ui::RUserWindow *ui;
};

#endif // RUSERWINDOW_H
