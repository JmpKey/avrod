#ifndef CUSTOMSQLTABLEMODEL_H
#define CUSTOMSQLTABLEMODEL_H

#include <QSqlTableModel>

class CustomSqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit CustomSqlTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

    // Redefining the flags method to adjust the editability of columns
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

#endif // CUSTOMSQLTABLEMODEL_H
