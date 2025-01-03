#ifndef PARSEMODULE_H
#define PARSEMODULE_H

#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QDebug>

class ParseModule
{
public:
    ParseModule();
    ~ParseModule();

    void readFile(QString _in_file);
    void parsStringPaper(QString _route, QString _sum_back, QString _sum_legal, QString _sum_handsome);
    void parsStringPop(QString _id_r, QString _name_r, QString _count, QString _u_char);
    void parsStringSpy(QString _route, QString _оccupied_seats, QString _total_seats);
    void writeFile(QString _out_file);

private:
    QString html_content = "";
};

#endif // PARSEMODULE_H
