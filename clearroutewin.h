#ifndef CLEARROUTEWIN_H
#define CLEARROUTEWIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ClearRouteWin;
}

class ClearRouteWin : public QDialog
{
    Q_OBJECT

public:
    explicit ClearRouteWin(QWidget *parent = nullptr);
    ~ClearRouteWin();

private slots:
    void on_pb_end_route_clicked();

signals:
    void sendDataClearRote(int route);

private:
    Ui::ClearRouteWin *ui;
};

#endif // CLEARROUTEWIN_H
