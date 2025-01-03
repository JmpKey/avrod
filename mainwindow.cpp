#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Code from Windows 2x
    widget = new QWidget();
    widget->setLayout(ui->gridLayout);
    setCentralWidget(widget);

    connect(ui->action_enter, &QAction::triggered, this, &MainWindow::onOpenDialogE);
    connect(ui->action_reg, &QAction::triggered, this, &MainWindow::onOpenDialogR);
    connect(ui->pb_add_tick, &QPushButton::clicked, this, &MainWindow::onOpenDialogReserv);
    connect(ui->pb_control, &QPushButton::clicked, this, &MainWindow::onOpenDialogCont);
    connect(ui->pb_clear_route_dat, &QPushButton::clicked, this, &MainWindow::onOpenDialogClearRoute);

    abonentModel = nullptr;

    updateFilesFromConfig("path.conf");
}

MainWindow::~MainWindow()
{
    clearModel();
    delete widget;
    delete ui;
}

void MainWindow::sdb_init()
{
    sdb = QSqlDatabase::addDatabase("QIBASE", "av4462");
    sdb.setHostName("localhost");
    sdb.setDatabaseName(readSingleLineFromFile('b'));
    const bool ok = sdb.open("SYSDBA", "masterkey");

    if (!ok)
    {
        ShowMessage("Не удалось открыть базу данных: " + sdb.lastError().text());
        return;
    }
}

void MainWindow::sdb_deinit() { sdb.close(); }

void MainWindow::on_pb_save_clicked()
{
    if (!abonentModel->submitAll())
        ShowMessage(abonentModel->lastError().text());
}

void MainWindow::on_pb_update_clicked()
{
    abonentModel->select();
}

void MainWindow::ShowMessage(const QString text)
{
    QMessageBox msg;
    msg.setText(text);
    msg.exec();
}

void MainWindow::on_pb_cancel_clicked()
{
    abonentModel->revertAll();
}

void MainWindow::createNewUser(QString username, QString password, QString roleName)
{
    sdb_init();

    QSqlQuery query(sdb);

    // Creating a new user
    if (!query.exec(QString("CREATE USER %1 PASSWORD '%2'").arg(username).arg(password)))
    {
        qDebug() << "Error creating user:" << query.lastError().text();
    }

    // Granting a role to a new user
    if (!query.exec(QString("GRANT %1 TO %2").arg(roleName).arg(username)))
    {
        qDebug() << "Error granting role to user:" << query.lastError().text();
    }

    if (!query.exec(QString("GRANT SELECT ON PASSENGERS TO %1").arg(username)))
    {
        qDebug() << "Error grant select pas to user:" << query.lastError().text();
    }

    if (!query.exec(QString("GRANT SELECT ON ROUTES TO %1").arg(username)))
    {
        qDebug() << "Error grant select rout to user:" << query.lastError().text();
    }

    if (!query.exec(QString("GRANT SELECT ON BUSES TO %1").arg(username)))
    {
        qDebug() << "Error grant select bus to user:" << query.lastError().text();
    }

    if(roleName == "PASSENGERS") {
        if (!query.exec(QString("GRANT INSERT ON PASSENGERS TO %1").arg(username)))
        {
            qDebug() << "Error grant insert pas to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT USAGE ON GENERATOR SEQ_PASSENGERS_ID TO %1").arg(username)))
        {
            qDebug() << "Error granting generator to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT UPDATE ON PASSENGERS TO %1").arg(username)))
        {
            qDebug() << "Error grant update pas to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT SELECT ON ACCOUNTING TO %1").arg(username)))
        {
            qDebug() << "Error grant select to ac user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT INSERT ON ACCOUNTING TO %1").arg(username)))
        {
            qDebug() << "Error grant insert ac to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT USAGE ON GENERATOR SEQ_ACCOUNTING_ID TO %1").arg(username)))
        {
            qDebug() << "Error granting generator to user:" << query.lastError().text();
        }
    }

    if(roleName == "PERSONNEL") {
        if (!query.exec(QString("GRANT SELECT ON ACCOUNTING TO %1").arg(username)))
        {
            qDebug() << "Error grant select to ac user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT UPDATE ON ACCOUNTING TO %1;").arg(username)))
        {
            qDebug() << "Error grant update ac to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT UPDATE ON PASSENGERS TO %1;").arg(username)))
        {
            qDebug() << "Error grant update pas to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT DELETE ON ACCOUNTING TO %1").arg(username)))
        {
            qDebug() << "Error grant delete ac to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT DELETE ON PASSENGERS TO %1").arg(username)))
        {
            qDebug() << "Error grant delet pas to user:" << query.lastError().text();
        }
    }

    if(roleName == "ST_ATTENDAT") {
        if (!query.exec(QString("GRANT SELECT ON ACCOUNTING TO %1").arg(username)))
        {
            qDebug() << "Error grant select ac to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT UPDATE ON BUSES TO %1;").arg(username)))
        {
            qDebug() << "Error grant update bus to user:" << query.lastError().text();
        }

        if (!query.exec(QString("GRANT UPDATE ON ROUTES TO %1;").arg(username)))
        {
            qDebug() << "Error grant update rout to user:" << query.lastError().text();
        }
    }

    if (!query.exec(QString("COMMIT")))
    {
        qDebug() << "Error granting generator to user:" << query.lastError().text();
        return;
    }

    sdb_deinit();
}

void MainWindow::setControlUsBut(QString us_char) {
    if (us_char == "PASSENGERS") {
        ui->pb_control->setVisible(false);
        ui->pb_clear_route_dat->setVisible(false);
        ui->pb_del_no_block->setVisible(false);
        ui->pb_cancel->setVisible(false);
        ui->pb_update->setVisible(false);
        ui->pb_save->setVisible(false);
        ui->pb_chek_data->setVisible(false); //???
        ui->pb_to_file->setVisible(false);
    }

    if (us_char == "PERSONNEL") {
        ui->pb_add_tick->setVisible(false);
        ui->pb_del_tick->setVisible(false);
        ui->pb_cancel->setVisible(false);
        ui->pb_update->setVisible(false);
        ui->pb_save->setVisible(false);
    }

    if (us_char == "ST_ATTENDAT") {
        ui->pb_add_tick->setVisible(false);
        ui->pb_del_tick->setVisible(false);
        ui->pb_control->setVisible(false);
        ui->pb_clear_route_dat->setVisible(false);
        ui->pb_del_no_block->setVisible(false);
    }
}

void MainWindow::rollbackControlUsBut() {
    ui->pb_control->setVisible(true);
    ui->pb_clear_route_dat->setVisible(true);
    ui->pb_del_no_block->setVisible(true);
    ui->pb_cancel->setVisible(true);
    ui->pb_update->setVisible(true);
    ui->pb_save->setVisible(true);
    ui->pb_chek_data->setVisible(true); //???
    ui->pb_add_tick->setVisible(true);
    ui->pb_del_tick->setVisible(true);
    ui->pb_to_file->setVisible(true);
}

void MainWindow::on_action_reg_triggered() {}

void MainWindow::on_action_enter_triggered() {}

void MainWindow::onOpenDialogE()
{
    EUserWindow win_en(this);
    connect(&win_en, &EUserWindow::sendDataE, this, &MainWindow::receiveDataE);
    win_en.exec();
}

void MainWindow::receiveDataE(QString uname, QString upass)
{
    udb = QSqlDatabase::addDatabase("QIBASE", "av4462");
    udb.setHostName("localhost");
    udb.setDatabaseName(readSingleLineFromFile('b'));
    const bool ok = udb.open(uname, upass);

    if (!ok)
    {
        ShowMessage("Не удалось открыть базу данных: " + udb.lastError().text());
        return;
    }

    qDebug() << "Successfully connected as user:" << uname;

    // Now you can continue working with the connection under a new user
    abonentModel = new CustomSqlTableModel(this, udb);
    abonentModel->setTable("ROUTES");
    abonentModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    abonentModel->select();
    ui->tableView->setModel(abonentModel);
    usname = uname;

    setControlUsBut(readSingleLineFromFile('d'));
}

void MainWindow::onOpenDialogR()
{
    RUserWindow win_reg(this);
    connect(&win_reg, &RUserWindow::sendDataR, this, &MainWindow::receiveDataR);
    win_reg.exec();
}

void MainWindow::receiveDataR(QString uname, QString upass)
{
    createNewUser(uname, upass, readSingleLineFromFile('d'));

    ShowMessage("Теперь войдите в учётную запись");
}

QString MainWindow::readSingleLineFromFile(char sig_f) {
    QString line = "";
    QString filePath = "";

    if(sig_f == 's') { filePath = QCoreApplication::applicationDirPath() + "/" + "pathreport"; }
    if(sig_f == 'd') { filePath = QCoreApplication::applicationDirPath() + "/" + "rdata"; }
    if(sig_f == 'b') { filePath = QCoreApplication::applicationDirPath() + "/" + "pathdb"; }

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << file.errorString();
        return QString();
    }

    QTextStream in(&file);

    line = in.readLine();

    file.close();
    return line;
}

void MainWindow::writeToFile(const QString &filePath, const QString &content) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << content;
        file.close();
    } else {
        qWarning() << "No open file in write:" << filePath;
    }
}

void MainWindow::updateFilesFromConfig(const QString &configFilePath) {
    QFile configFile(configFilePath);

    if (configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&configFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            // We assume the format: "file path" = "new value"
            QStringList parts = line.split("=");
            if (parts.size() == 2) {
                QString filePath = parts[0].trimmed().remove('"');
                QString newValue = parts[1].trimmed().remove('"');

                writeToFile(filePath, newValue);
            }
        }
        configFile.close();
    } else {
        qWarning() << "Не удалось открыть конфигурационный файл:" << configFilePath;
    }
}

int MainWindow::getPassengerId() {
    QSqlQuery query(udb);
    query.prepare("SELECT ID FROM PASSENGERS WHERE UNAME = :uname");
    query.bindValue(":uname", usname);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return -1;
    }

    if (query.next()) {
        return query.value(0).toInt(); // Returning the ID
    }

    return -1;
}

int MainWindow::getNextPassengerId() {
    QSqlQuery query(udb);
    // Executing the request
    query.prepare("SELECT COALESCE(MAX(ID), 0) + 1 AS Next_ID FROM PASSENGERS");

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return -1; // We return -1 in case of an error
    }

    // Checking if there are any results
    if (query.next()) {
        int nextId = query.value(0).toInt(); // We get the value of the following ID
        return nextId;
    } else {
        qDebug() << "No results returned.";
        return -1;
    }
}

QString MainWindow::generateUniqueRandomValue() {
    // Creating a random number generator
    QRandomGenerator generator;
    generator.seed(QTime::currentTime().msec());

    // generating a random value
    QString randomValue;
    for (int i = 0; i < 10; ++i) {
        // Generating a random character from a set of valid characters
        QString characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        int randomIndex = generator.bounded(characters.length());
        randomValue += characters[randomIndex];
    }

    return randomValue;
}

void MainWindow::on_pb_add_tick_clicked() {}

void MainWindow::onOpenDialogReserv() {
    ShowMessage("Для проверки доступных мест, выберете маршрут в таблице и кликните на кнопку 'ИНФОРМАЦИЯ'");

    ReservWindow win_res(this);
    connect(&win_res, &ReservWindow::sendDataResWin, this, &MainWindow::receiveDataReserv);
    win_res.exec();
}

void MainWindow::receiveDataReserv(QString fio, QString tel, int route, int place, double price) {
    int usid = getNextPassengerId();
    QString ticket = generateUniqueRandomValue();

    // Создание запроса для вставки данных
    QSqlQuery query(udb);
    query.prepare("INSERT INTO PASSENGERS (ID, UNAME, FIO, TELEPHON, TICKETS_U, \"BLOCK\", ROUTE_T_ID, NUM_PLACE, PRICE) VALUES (:id, :uname, :fio, :telephon, :tickets_u, :block, :route_t_id, :num_place, :price)");

    // Filling the table with test data
    query.bindValue(":id", usid);
    query.bindValue(":uname", usname);
    query.bindValue(":fio", fio);
    query.bindValue(":telephon", tel);
    query.bindValue(":tickets_u", ticket);
    query.bindValue(":block", true);
    query.bindValue(":route_t_id", route);
    query.bindValue(":num_place", place);
    query.bindValue(":price", price);
    if (!query.exec()) {
        qDebug() << "Ошибка вставки данных: " << query.lastError().text();
    }

    setInsertTicket(usid);

    if(not_duble < 1) {
        QString fileName = QFileDialog::getSaveFileName(nullptr, "Сохранить билет", QDir::homePath(), "Text Files (*.txt);;All Files (*)");

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << ticket;
                file.close();
            } else {
                qWarning("Не удалось открыть файл для записи.");
            }
        }
    }
    not_duble++;

    // not every GRANT USAGE ON GENERATOR SEQ_PASSENGERS_ID TO <role_name>
    // Grant the INSERT privilege to the PASSENGERS tab: GRANT INSERT ON PASSENGERS TO <username>
}

int MainWindow::getNextAccountingId() {
    int nextId = 0;
    QSqlQuery query(udb);
    // Выполняем запрос
    query.prepare("SELECT COALESCE(MAX(ID), 0) + 1 AS Next_ID FROM ACCOUNTING");

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    if (query.next()) {
        nextId = query.value(0).toInt(); // We get the value of the following ID
    } else {
        qDebug() << "No results returned.";
    }
    return nextId;
}

void MainWindow::setInsertTicket(int ticket_id)
{
    int next_id = getNextAccountingId();

    // Creating a data insertion request
    QSqlQuery query(udb);
    query.prepare("INSERT INTO ACCOUNTING (ID, TICKETS_A_ID, \"PAID\") VALUES (:id, :tickets_a_id, :paid)");

    // Filling the table with test data
    query.bindValue(":id", next_id);
    query.bindValue(":tickets_a_id", ticket_id);
    query.bindValue(":paid", false);
    if (!query.exec()) {
        qDebug() << "Ошибка вставки данных: " << query.lastError().text();
    }
}

void MainWindow::on_pb_del_tick_clicked()
{
    QSqlQuery query(udb);
    query.prepare("UPDATE PASSENGERS SET \"BLOCK\" = FALSE WHERE ID = :id");
    query.bindValue(":id", getPassengerId()); // Replace the passenger id with the actual value

    if (query.exec()) {
        qDebug() << "Запись успешно обновлена.";
    } else {
        qDebug() << "Ошибка обновления записи: " << query.lastError().text();
    }
}

void MainWindow::on_pb_info_clicked()
{
    QModelIndex i = ui->tableView->selectionModel()->currentIndex();
    int info_id = i.row() + 1; // !!! link the route ID from the abonentModel table by clicking

    if (info_id > 0)
    {
        QSqlQuery query(udb);
        query.prepare("SELECT NUM_PLACE FROM PASSENGERS WHERE ROUTE_T_ID = :routeId");
        query.bindValue(":routeId", info_id);

        if (!query.exec())
        {
            qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
            return;
        }

        QStringList seats;
        while (query.next())
        {
            seats << query.value("NUM_PLACE").toString();
        }

        // Combining all NUM_PLACE values into a single line separated by a comma
        QString m = seats.join(", ");

        ShowMessage("Занятые места: " + m);

        query.prepare("SELECT (SELECT TOTAL_SEATS FROM BUSES WHERE ROUTE_B_ID = :routeId) - COUNT(P.NUM_PLACE) AS FreeSeats FROM PASSENGERS P WHERE P.ROUTE_T_ID = :routeId");
        query.bindValue(":routeId", info_id);

        if (!query.exec()) {
            qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
        }

        if (query.next()) {
            int freeSeats = query.value("FreeSeats").toInt();
            ShowMessage("Свободных мест: " + QString::number(freeSeats));
        } else {
            qDebug() << "Результат пуст";
        }
    }
}

void MainWindow::onOpenDialogCont()
{
    ControlWin win_cont(this);
    connect(&win_cont, &ControlWin::sendDataCont, this, &MainWindow::receiveDataCont);
    win_cont.exec();
}

void MainWindow::receiveDataCont(QString ticket)
{
    setCheckTicket(getTicketId(ticket));
}

void MainWindow::on_pb_control_clicked() {}

int MainWindow::getTicketId(QString ticket_code)
{
    QSqlQuery query(udb);
    query.prepare("SELECT ID FROM PASSENGERS WHERE TICKETS_U = :ticket");

    query.bindValue(":ticket", ticket_code);

    if (!query.exec()) {
        return 0; // Beetles and Chirno play hide and seek
        qDebug() << "Ошибка выполнения запроса";
    }

    int passengerId = 0;
    if (query.next()) {
        passengerId = query.value(0).toInt();
    }

    return passengerId;
}

void MainWindow::setCheckTicket(int id_passenger) {
    if(id_passenger == 0) { ShowMessage("Билет не зарегистрирован!"); }

    QSqlQuery query(udb);
    query.prepare("UPDATE ACCOUNTING SET PAID = TRUE WHERE TICKETS_A_ID = :passengerId");

    query.bindValue(":passengerId", id_passenger);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    }
}

void MainWindow::clearPassengersRoute(int id_route) {

    ShowMessage(QString::number(id_route));
    QSqlQuery query(udb);
    if (!udb.transaction()) {
        qDebug() << "Ошибка начала транзакции:" << udb.lastError().text();
    }

    query.prepare("DELETE FROM ACCOUNTING WHERE TICKETS_A_ID IN (SELECT ID FROM PASSENGERS WHERE ROUTE_T_ID = :route_id) AND PAID = true");
    query.bindValue(":route_id", id_route);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения DELETE:" << query.lastError().text();
        udb.rollback(); // Rollback of a transaction in case of an error
    }

    QSqlQuery updateQuery(udb);
        updateQuery.prepare(R"(
            UPDATE PASSENGERS
            SET UNAME = NULL,
                FIO = NULL,
                TELEPHON = NULL,
                TICKETS_U = NULL,
                BLOCK = NULL,
                ROUTE_T_ID = NULL,
                NUM_PLACE = NULL,
                PRICE = NULL
            WHERE ROUTE_T_ID = :routeId
        )");

    updateQuery.bindValue(":routeId", id_route);

    if (!updateQuery.exec()) {
        qDebug() << "Ошибка выполнения UPDATE:" << updateQuery.lastError().text();
        udb.rollback();
    }

    if (!udb.commit()) {
        qDebug() << "Ошибка подтверждения транзакции:" << udb.lastError().text();
    }
}

void MainWindow::killNullPassengers() {
    QSqlQuery query(udb);
    query.prepare("DELETE FROM PASSENGERS WHERE UNAME IS NULL");

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения UPDATE:" << query.lastError().text();
        udb.rollback();
    }

    if (!udb.commit()) {
        qDebug() << "Ошибка подтверждения транзакции:" << udb.lastError().text();
    }
}

void MainWindow::on_pb_clear_route_dat_clicked() {}

void MainWindow::onOpenDialogClearRoute()
{
    ClearRouteWin win_clear_r(this);
    connect(&win_clear_r, &ClearRouteWin::sendDataClearRote, this, &MainWindow::receiveDataClearRoute);
    win_clear_r.exec();
}

void MainWindow::receiveDataClearRoute(int route)
{
    clearPassengersRoute(route);
    killNullPassengers();
}

void MainWindow::on_pb_del_no_block_clicked()
{
    QSqlQuery query1(udb);
    query1.prepare("DELETE FROM ACCOUNTING WHERE PAID = FALSE");

    if (!query1.exec()) {
        qDebug() << "Ошибка выполнения запроса 1:" << query1.lastError().text();
    } else {
        qDebug() << "Записи из ACCOUNTING успешно удалены.";
    }

    QSqlQuery query2(udb);
    query2.prepare("DELETE FROM PASSENGERS WHERE BLOCK = FALSE");

    if (!query2.exec()) {
        qDebug() << "Ошибка выполнения запроса 2:" << query2.lastError().text();
    } else {
        qDebug() << "Записи из PASSENGERS успешно удалены.";
    }
}

void MainWindow::clearModel() {
    // We don't need leaks. Save your memory-chan :3
    if(abonentModel != nullptr) {
        clear_all_elem_model();
        delete abonentModel;
        abonentModel = nullptr;
        ui->tableView->setModel(nullptr);
    }
}

void MainWindow::clear_all_elem_model() { ui->tableView->model()->removeRows(0, ui->tableView->model()->rowCount()); abonentModel->clear(); }

void MainWindow::setNewModel(QString name_t) {
    abonentModel->setTable(name_t);
    abonentModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    abonentModel->select();
    ui->tableView->setModel(abonentModel);
}

void MainWindow::on_pb_chek_data_clicked()
{
    QString table_name = abonentModel->tableName();

    if(table_name == "ROUTES") {
        clearModel();
        abonentModel = new CustomSqlTableModel(this, udb);
        setNewModel("BUSES");
    }
    else if(table_name == "BUSES") {
        clearModel();
        abonentModel = new CustomSqlTableModel(this, udb);
        setNewModel("ROUTES");
    }
    else { ShowMessage("Yor database is compromised"); }
}

void MainWindow::exit_mw() {
    if(usname != "")
    {
        rollbackControlUsBut();
        clear_all_elem_model();
        not_duble = 0; // this is so that the ticket is saved
        usname = "";
        udb.close();
    }
    else { ShowMessage("Вы не вошли!"); }
}

void MainWindow::on_action_exit_u_triggered() { exit_mw(); }

void MainWindow::on_pb_to_file_clicked()
{
    QString tstr = readSingleLineFromFile('d');

    if(tstr == "ST_ATTENDAT") {
        ParseModule parse;
        parse.readFile("template/route.html");
        popRoutes(parse);
        parse.writeFile(readSingleLineFromFile('s') + "/poproute" + "_" + usname + "_" + getCurrentDate() + ".html"); // poproute_user_2023-10-27T10:30:00
    }

    if(tstr == "PERSONNEL") {
        connect(ui->pb_to_file, &QPushButton::clicked, this, &MainWindow::onOpenDialogReport);
    }
}

void MainWindow::onOpenDialogReport() {
    ReportWin win_rep(this);
    connect(&win_rep, &ReportWin::sendDataRepWin, this, &MainWindow::receiveDataReport);
    win_rep.exec();
}

void MainWindow::receiveDataReport(int _route_id) {
    ParseModule paper;
    paper.readFile("template/paper.html");
    QVector<QString> tick_info = getTicketCounts(_route_id);
    paper.parsStringPaper(QString::number(_route_id), tick_info[0], tick_info[1], tick_info[2]);
    paper.writeFile(readSingleLineFromFile('s') + "/paper" + "_" + QString::number(_route_id) + "_" + usname + "_" + getCurrentDate() + ".html"); // paper_routeid_user_2023-10-27T10:30:00

    ParseModule spy;
    spy.readFile("template/spy.html");
    QVector<QString> spy_info = spySeatsInfo(_route_id);
    spy.parsStringSpy(QString::number(_route_id), spy_info[0], spy_info[1]);
    spy.writeFile(readSingleLineFromFile('s') + "/spy" + "_" + QString::number(_route_id) + "_" + usname + "_" + getCurrentDate() + ".html");
}

QString MainWindow::getCurrentDate() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    return currentDateTime.toString(Qt::ISODate);
}

QVector<QString> MainWindow::getTicketCounts(int route_id){
    QVector<QString> results;
    QSqlQuery query(udb);

    // Request for the number of tickets booked
    query.prepare("SELECT COUNT(*) AS UNBOOKED_TICKETS "
                  "FROM PASSENGERS p "
                  "JOIN ROUTES r ON p.ROUTE_T_ID = r.ID "
                  "WHERE r.ACTIVE = TRUE AND p.BLOCK = FALSE AND r.ID = :route_id");
    query.bindValue(":route_id", route_id);

    if (query.exec() && query.next()) {
        results.append(query.value(0).toString());
    } else {
        qDebug() << "Error in UNBOOKED_TICKETS query:" << query.lastError().text();
    }

    // Request for the total number of tickets sold
    query.prepare("SELECT COUNT(*) AS TOTAL_TICKETS_SOLD "
                  "FROM ROUTES r "
                  "JOIN PASSENGERS p ON r.ID = p.ROUTE_T_ID "
                  "JOIN ACCOUNTING a ON p.ID = a.TICKETS_A_ID "
                  "WHERE r.ACTIVE = TRUE AND a.PAID = TRUE AND r.ID = :route_id");
    query.bindValue(":route_id", route_id);

    if (query.exec() && query.next()) {
        results.append(query.value(0).toString());
    } else {
        qDebug() << "Error in TOTAL_TICKETS_SOLD query:" << query.lastError().text();
    }

    // Request for the number of unpaid tickets
    query.prepare("SELECT COUNT(*) AS Not_Paid_Tickets "
                  "FROM PASSENGERS p "
                  "JOIN ACCOUNTING a ON p.ID = a.TICKETS_A_ID "
                  "JOIN ROUTES r ON p.ROUTE_T_ID = r.ID "
                  "WHERE r.ACTIVE = TRUE AND a.PAID = FALSE AND r.ID = :route_id");
    query.bindValue(":route_id", route_id);

    if (query.exec() && query.next()) {
        results.append(query.value(0).toString());
    } else {
        qDebug() << "Error in Not_Paid_Tickets query:" << query.lastError().text();
    }

    return results;
}

void MainWindow::popRoutes(ParseModule &_parse) {
    QSqlQuery query(udb);
    QString sql = R"(
           SELECT
               R.ID AS ROUTE_ID,
               R.MAP AS MAP,
               COUNT(P.ID) AS PASSENGER_COUNT
           FROM
               ROUTES R
           LEFT JOIN
               PASSENGERS P ON R.ID = P.ROUTE_T_ID
           WHERE
               R.ACTIVE = TRUE
           GROUP BY
               R.ID, R.MAP
           ORDER BY
               PASSENGER_COUNT DESC
       )";

    if (!query.exec(sql)) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    QString u_char[8] = {"〇", "§", "†", "≈", "∞", "◆", "♪", "𐍈"}; // This is not gibberish, these are the characters that will be found in the template and replaced
    int i = 0;

    while (query.next()) {
        QString routeId = query.value("ROUTE_ID").toString();
        QString map = query.value("MAP").toString();
        QString passengerCount = query.value("PASSENGER_COUNT").toString();
        _parse.parsStringPop(routeId, map, passengerCount, u_char[i]);
        i++;
    }
}

QVector<QString> MainWindow::spySeatsInfo(int _route_id) {
    QVector<QString> results;
    // Making the first request
        QSqlQuery query1(udb);
        query1.prepare("SELECT SUM(CASE WHEN P.NUM_PLACE IS NOT NULL THEN 1 ELSE 0 END) AS occupied_seats "
                       "FROM PASSENGERS P WHERE P.ROUTE_T_ID = :route_id");
        query1.bindValue(":route_id", _route_id);

        if (query1.exec() && query1.next()) {
            int occupiedSeats = query1.value(0).toInt();
            results.append(QString::number(occupiedSeats));
        } else {
            qDebug() << "Ошибка выполнения первого запроса:" << query1.lastError().text();
            results.append("0"); // Or handle the error in a different way
        }

        // Executing the second request
        QSqlQuery query2(udb);
        query2.prepare("SELECT B.TOTAL_SEATS FROM BUSES B WHERE B.ROUTE_B_ID = :route_id");
        query2.bindValue(":route_id", _route_id);

        if (query2.exec() && query2.next()) {
            int totalSeats = query2.value(0).toInt();
            results.append(QString::number(totalSeats));
        } else {
            qDebug() << "Ошибка выполнения второго запроса:" << query2.lastError().text();
            results.append("0");
        }

    return results;
}
