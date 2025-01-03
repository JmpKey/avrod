/********************************************************************************
** Form generated from reading UI file 'clearroutewin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEARROUTEWIN_H
#define UI_CLEARROUTEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClearRouteWin
{
public:
    QComboBox *cb_clear_route;
    QLabel *lab_clear_route;
    QPushButton *pb_end_route;

    void setupUi(QDialog *ClearRouteWin)
    {
        if (ClearRouteWin->objectName().isEmpty())
            ClearRouteWin->setObjectName("ClearRouteWin");
        ClearRouteWin->resize(225, 107);
        cb_clear_route = new QComboBox(ClearRouteWin);
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->addItem(QString());
        cb_clear_route->setObjectName("cb_clear_route");
        cb_clear_route->setGeometry(QRect(100, 20, 101, 23));
        lab_clear_route = new QLabel(ClearRouteWin);
        lab_clear_route->setObjectName("lab_clear_route");
        lab_clear_route->setGeometry(QRect(20, 20, 58, 15));
        pb_end_route = new QPushButton(ClearRouteWin);
        pb_end_route->setObjectName("pb_end_route");
        pb_end_route->setGeometry(QRect(100, 60, 101, 23));

        retranslateUi(ClearRouteWin);

        QMetaObject::connectSlotsByName(ClearRouteWin);
    } // setupUi

    void retranslateUi(QDialog *ClearRouteWin)
    {
        ClearRouteWin->setWindowTitle(QCoreApplication::translate("ClearRouteWin", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        cb_clear_route->setItemText(0, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\235. \320\235\320\276\320\262\320\263\320\276\321\200\320\276\320\264", nullptr));
        cb_clear_route->setItemText(1, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\230\320\262\320\260\320\275\320\276\320\262\320\276", nullptr));
        cb_clear_route->setItemText(2, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\232\320\276\321\201\321\202\321\200\320\276\320\274\320\260", nullptr));
        cb_clear_route->setItemText(3, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\257\321\200\320\276\321\201\320\273\320\260\320\262\320\273\321\214", nullptr));
        cb_clear_route->setItemText(4, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\241\320\265\321\200\320\263\320\270\320\265\320\262 \320\237\320\276\321\201\320\260\320\264", nullptr));
        cb_clear_route->setItemText(5, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        cb_clear_route->setItemText(6, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\240\321\217\320\267\320\260\320\275\321\214", nullptr));
        cb_clear_route->setItemText(7, QCoreApplication::translate("ClearRouteWin", "\320\222\320\273\320\260\320\264\320\270\320\274\320\270\321\200-\320\220\321\200\320\267\320\260\320\274\320\260\321\201", nullptr));

        lab_clear_route->setText(QCoreApplication::translate("ClearRouteWin", "\320\234\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        pb_end_route->setText(QCoreApplication::translate("ClearRouteWin", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClearRouteWin: public Ui_ClearRouteWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEARROUTEWIN_H
