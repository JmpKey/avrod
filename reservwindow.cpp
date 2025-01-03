#include "reservwindow.h"
#include "ui_reservwindow.h"

ReservWindow::ReservWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReservWindow)
{
    ui->setupUi(this);

    connect(ui->pb_enter, &QPushButton::clicked, this, &ReservWindow::on_pb_enter_clicked);
}

ReservWindow::~ReservWindow()
{
    delete ui;
}

void ReservWindow::on_pb_enter_clicked()
{
    if((ui->le_fio->text() != "") | (ui->le_tel->text() != "") | (ui->le_place->text() != "")) {
        int route_id = ui->cb_route->currentIndex() + 1;

        emit sendDataResWin(ui->le_fio->text(), ui->le_tel->text(), route_id, ui->le_place->text().toInt(), 350);
        accept();
    }
}

