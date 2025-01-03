#include "reportwin.h"
#include "ui_reportwin.h"

ReportWin::ReportWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReportWin)
{
    ui->setupUi(this);

    connect(ui->pb_enter, &QPushButton::clicked, this, &ReportWin::on_pb_enter_clicked);
}

ReportWin::~ReportWin()
{
    delete ui;
}

void ReportWin::on_pb_enter_clicked()
{
    emit sendDataRepWin(ui->cb_route_id->currentIndex() + 1);
    accept();
}

