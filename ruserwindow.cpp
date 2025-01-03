#include "ruserwindow.h"
#include "ui_ruserwindow.h"

RUserWindow::RUserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RUserWindow)
{
    ui->setupUi(this);

    connect(ui->pb_registr, &QPushButton::clicked, this, &RUserWindow::on_pb_registr_clicked);
}

RUserWindow::~RUserWindow()
{
    delete ui;
}

void RUserWindow::on_pb_registr_clicked()
{
    if((ui->le_uname->text() != "") | (ui->le_passu->text() != "") | (ui->le_passu1->text() != "")) {
        if(ui->le_passu->text() == ui->le_passu1->text()) {
            emit sendDataR(ui->le_uname->text(), ui->le_passu->text());
            accept();
        }
        else {
            QMessageBox msg;
            msg.setText("Пароли не совпадают");
            msg.exec();
        }
    }
}
