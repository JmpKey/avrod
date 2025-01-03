#ifndef REPORTWIN_H
#define REPORTWIN_H

#include <QDialog>

namespace Ui {
class ReportWin;
}

class ReportWin : public QDialog
{
    Q_OBJECT

public:
    explicit ReportWin(QWidget *parent = nullptr);
    ~ReportWin();

private slots:
    void on_pb_enter_clicked();

signals:
    void sendDataRepWin(int route_id);

private:
    Ui::ReportWin *ui;
};

#endif // REPORTWIN_H
