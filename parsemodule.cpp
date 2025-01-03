#include "parsemodule.h"

ParseModule::ParseModule() {}

ParseModule::~ParseModule() {}

void ParseModule::readFile(QString __in_file) {
    QFile inputFile(__in_file);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Error opening input file:" << inputFile.errorString();
    }

    html_content = inputFile.readAll();
    inputFile.close();
}

void ParseModule::parsStringPaper(QString _route, QString _sum_back, QString _sum_legal, QString _sum_handsome) {
    QRegularExpression re_route("Маршрут \\[〇\\]"); // A regular expression for searching for a route placeholder
    QRegularExpression re_legal("Сумма проданных билетов: \\[Ω\\]"); // An example for another placeholder
    QRegularExpression re_back("Сумма отменённых билетов: \\[∂\\]");
    QRegularExpression re_chandsome("Сумма билетов не прошедших контроль: \\[†\\]");

    html_content.replace(re_route, "Маршрут [" + _route + "]"); // Substitution
    html_content.replace(re_legal, "Сумма проданных билетов: " + _sum_legal);
    html_content.replace(re_back, "Сумма отменённых билетов: " + _sum_back);
    html_content.replace(re_chandsome, "Сумма билетов не прошедших контроль: " + _sum_handsome);
}

void ParseModule::parsStringSpy(QString _route, QString _оccupied_seats, QString _total_seats) {
    QRegularExpression re_route("Маршрут \\[〇\\]");
    QRegularExpression re_legal("Сумма занятых мест: \\[α\\]");
    QRegularExpression re_back("Сумма свободных мест: \\[ω\\]");
    QRegularExpression re_chandsome("Всего мест: \\[γ\\]");

    html_content.replace(re_route, "Маршрут [" + _route + "]");
    html_content.replace(re_legal, "Сумма занятых мест: " + _оccupied_seats);
    html_content.replace(re_back, "Сумма свободных мест: " + QString::number(_total_seats.toInt() - _оccupied_seats.toInt()));
    html_content.replace(re_chandsome, "Всего мест: " + _total_seats);
}

void ParseModule::parsStringPop(QString _id_r, QString _name_r, QString _count, QString _u_char) {
    QString search = "\\[" + _u_char + "\\]";
    QRegularExpression reg(search);
    QString routeReplacement = "Маршрут " + _id_r + " " + _name_r + " " + _count;

    html_content.replace(reg, routeReplacement);
}

void ParseModule::writeFile(QString __out_file) {
    QFile outputFile(__out_file);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qCritical() << "Error opening output file:" << outputFile.errorString();
    }

    outputFile.write(html_content.toUtf8());
    outputFile.close();

    qDebug() << "HTML file processed successfully.";
}
