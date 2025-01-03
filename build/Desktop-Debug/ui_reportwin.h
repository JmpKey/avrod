/********************************************************************************
** Form generated from reading UI file 'reportwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIN_H
#define UI_REPORTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReportWin
{
public:
    QLabel *lab_route_id;
    QComboBox *cb_route_id;
    QPushButton *pb_enter;

    void setupUi(QDialog *ReportWin)
    {
        if (ReportWin->objectName().isEmpty())
            ReportWin->setObjectName("ReportWin");
        ReportWin->resize(326, 111);
        lab_route_id = new QLabel(ReportWin);
        lab_route_id->setObjectName("lab_route_id");
        lab_route_id->setGeometry(QRect(10, 20, 121, 16));
        cb_route_id = new QComboBox(ReportWin);
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->addItem(QString());
        cb_route_id->setObjectName("cb_route_id");
        cb_route_id->setGeometry(QRect(140, 20, 161, 23));
        pb_enter = new QPushButton(ReportWin);
        pb_enter->setObjectName("pb_enter");
        pb_enter->setGeometry(QRect(140, 60, 161, 23));

        retranslateUi(ReportWin);

        QMetaObject::connectSlotsByName(ReportWin);
    } // setupUi

    void retranslateUi(QDialog *ReportWin)
    {
        ReportWin->setWindowTitle(QCoreApplication::translate("ReportWin", "\320\236\321\202\321\207\321\221\321\202", nullptr));
        lab_route_id->setText(QCoreApplication::translate("ReportWin", "\320\222\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        cb_route_id->setItemText(0, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\235. \320\235\320\276\320\262\320\263\320\276\321\200\320\276\320\264", nullptr));
        cb_route_id->setItemText(1, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\230\320\262\320\260\320\275\320\276\320\262\320\276", nullptr));
        cb_route_id->setItemText(2, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\232\320\276\321\201\321\202\321\200\320\276\320\274\320\260", nullptr));
        cb_route_id->setItemText(3, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\257\321\200\320\276\321\201\320\273\320\260\320\262\320\273\321\214", nullptr));
        cb_route_id->setItemText(4, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\241\320\265\321\200\320\263\320\270\320\265\320\262 \320\237\320\276\321\201\320\260\320\264", nullptr));
        cb_route_id->setItemText(5, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        cb_route_id->setItemText(6, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\240\321\217\320\267\320\260\320\275\321\214", nullptr));
        cb_route_id->setItemText(7, QCoreApplication::translate("ReportWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\220\321\200\320\267\320\260\320\274\320\260\321\201", nullptr));

        pb_enter->setText(QCoreApplication::translate("ReportWin", "\320\222\320\262\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportWin: public Ui_ReportWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIN_H
