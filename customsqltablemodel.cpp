#include "customsqltablemodel.h"

CustomSqlTableModel::CustomSqlTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db) {}

Qt::ItemFlags CustomSqlTableModel::flags(const QModelIndex &index) const {
    // If the index corresponds to the first column, we prohibit editing
    if (index.column() == 0) {
        return QSqlTableModel::flags(index) & ~Qt::ItemIsEditable; // Removing the edit flag
    }
    return QSqlTableModel::flags(index); // We leave the default flags for the other columns
}
