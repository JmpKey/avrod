#include "clearroutewin.h"
#include "ui_clearroutewin.h"

ClearRouteWin::ClearRouteWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClearRouteWin)
{
    ui->setupUi(this);

    connect(ui->pb_end_route, &QPushButton::clicked, this, &ClearRouteWin::on_pb_end_route_clicked);
}

ClearRouteWin::~ClearRouteWin()
{
    delete ui;
}

void ClearRouteWin::on_pb_end_route_clicked()
{
    // Creating a confirmation window
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите очистить маршрут?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        int route_id = ui->cb_clear_route->currentIndex() + 1;
        QMessageBox msg;
        msg.setText(QString::number(route_id));
        msg.exec();
        emit sendDataClearRote(route_id);
        accept();
    }
}
