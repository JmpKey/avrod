#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlTableModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlError>
#include <QSqlQuery>
#include <QRandomGenerator>
#include <QFileDialog>
#include <iostream>
#include <QDebug>

#include "ruserwindow.h"
#include "euserwindow.h"
#include "reservwindow.h"
#include "controlwin.h"
#include "clearroutewin.h"
#include "customsqltablemodel.h"
#include "reportwin.h"

#include "parsemodule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_save_clicked();
    void on_pb_update_clicked();
    void on_pb_cancel_clicked();
    void on_action_reg_triggered();
    void on_action_enter_triggered();

    // user slots:
    void onOpenDialogE();
    void receiveDataE(QString uname, QString upass);
    void onOpenDialogR();
    void receiveDataR(QString uname, QString upass);
    void onOpenDialogReserv();
    void receiveDataReserv(QString fio, QString tel, int route, int place, double price);
    void onOpenDialogCont();
    void receiveDataCont(QString ticket);
    void onOpenDialogClearRoute();
    void receiveDataClearRoute(int route);
    void onOpenDialogReport();
    void receiveDataReport(int _route_id);

    void on_pb_add_tick_clicked();
    void on_pb_del_tick_clicked();
    void on_pb_info_clicked();
    void on_pb_control_clicked();
    void on_pb_clear_route_dat_clicked();
    void on_pb_del_no_block_clicked();
    void on_pb_chek_data_clicked();
    void on_action_exit_u_triggered();
    void on_pb_to_file_clicked();

private:
    Ui::MainWindow *ui;
    QWidget* widget;
    CustomSqlTableModel* abonentModel;
    QSqlDatabase sdb;
    QSqlDatabase udb;
    QString usname = "";
    char not_duble = 0;

    void ShowMessage(const QString text);
    void createNewUser(QString username, QString password, QString roleName);
    QString readSingleLineFromFile(char sig_f);
    void sdb_init();
    void sdb_deinit();
    int getPassengerId();
    int getNextPassengerId();
    QString generateUniqueRandomValue();
    int getTicketId(QString ticket_code);
    void setCheckTicket(int id_passenger);
    void setInsertTicket(int ticket_id);
    int getNextAccountingId();
    void clearPassengersRoute(int id_route);
    void killNullPassengers();
    void clearModel();
    void setNewModel(QString name_t);
    void exit_mw();
    void clear_all_elem_model();
    void setControlUsBut(QString us_char);
    void rollbackControlUsBut();
    void popRoutes(ParseModule &_parse);
    QVector<QString> getTicketCounts(int route_id);
    QVector<QString> spySeatsInfo(int _route_id);
    QString getCurrentDate();
    void writeToFile(const QString &filePath, const QString &content);
    void updateFilesFromConfig(const QString &configFilePath);
    void readConf();
};
#endif // MAINWINDOW_H
