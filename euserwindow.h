#ifndef EUSERWINDOW_H
#define EUSERWINDOW_H

#include <QDialog>

namespace Ui {
class EUserWindow;
}

class EUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EUserWindow(QWidget *parent = nullptr);
    ~EUserWindow();

private slots:
    void on_pb_enteru_clicked();

signals:
    void sendDataE(QString uname, QString upass);

private:
    Ui::EUserWindow *ui;
};

#endif // EUSERWINDOW_H
