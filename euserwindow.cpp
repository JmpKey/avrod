#include "euserwindow.h"
#include "ui_euserwindow.h"

EUserWindow::EUserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EUserWindow)
{
    ui->setupUi(this);

    connect(ui->pb_enteru, &QPushButton::clicked, this, &EUserWindow::on_pb_enteru_clicked);
}

EUserWindow::~EUserWindow()
{
    delete ui;
}

void EUserWindow::on_pb_enteru_clicked()
{
    if((ui->le_uname->text() != "") | (ui->le_passu->text() != "")) {
        emit sendDataE(ui->le_uname->text(), ui->le_passu->text());
        accept();
    }
}

