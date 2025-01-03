#include "controlwin.h"
#include "ui_controlwin.h"

ControlWin::ControlWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ControlWin)
{
    ui->setupUi(this);

    connect(ui->pb_enter, &QPushButton::clicked, this, &ControlWin::on_pb_enter_clicked);
}

ControlWin::~ControlWin()
{
    delete ui;
}

void ControlWin::on_pb_enter_clicked()
{
    if(ui->le_ticket->text() != "") {
        emit sendDataCont(ui->le_ticket->text());
        accept();
    }
}

