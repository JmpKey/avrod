/********************************************************************************
** Form generated from reading UI file 'reservwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVWINDOW_H
#define UI_RESERVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReservWindow
{
public:
    QLineEdit *le_fio;
    QLineEdit *le_tel;
    QLineEdit *le_place;
    QLabel *lab_fio;
    QLabel *lab_tel;
    QLabel *lab_route;
    QLabel *lab_place;
    QLabel *lab_price;
    QPushButton *pb_enter;
    QComboBox *cb_route;
    QLabel *lab_price_1;

    void setupUi(QDialog *ReservWindow)
    {
        if (ReservWindow->objectName().isEmpty())
            ReservWindow->setObjectName("ReservWindow");
        ReservWindow->resize(224, 212);
        le_fio = new QLineEdit(ReservWindow);
        le_fio->setObjectName("le_fio");
        le_fio->setGeometry(QRect(100, 20, 113, 22));
        le_tel = new QLineEdit(ReservWindow);
        le_tel->setObjectName("le_tel");
        le_tel->setGeometry(QRect(100, 50, 113, 22));
        le_place = new QLineEdit(ReservWindow);
        le_place->setObjectName("le_place");
        le_place->setGeometry(QRect(100, 110, 113, 22));
        lab_fio = new QLabel(ReservWindow);
        lab_fio->setObjectName("lab_fio");
        lab_fio->setGeometry(QRect(10, 20, 58, 15));
        lab_tel = new QLabel(ReservWindow);
        lab_tel->setObjectName("lab_tel");
        lab_tel->setGeometry(QRect(10, 50, 58, 15));
        lab_route = new QLabel(ReservWindow);
        lab_route->setObjectName("lab_route");
        lab_route->setGeometry(QRect(10, 80, 58, 15));
        lab_place = new QLabel(ReservWindow);
        lab_place->setObjectName("lab_place");
        lab_place->setGeometry(QRect(10, 110, 58, 15));
        lab_price = new QLabel(ReservWindow);
        lab_price->setObjectName("lab_price");
        lab_price->setGeometry(QRect(10, 140, 58, 15));
        pb_enter = new QPushButton(ReservWindow);
        pb_enter->setObjectName("pb_enter");
        pb_enter->setGeometry(QRect(99, 170, 111, 23));
        cb_route = new QComboBox(ReservWindow);
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->addItem(QString());
        cb_route->setObjectName("cb_route");
        cb_route->setGeometry(QRect(100, 80, 111, 23));
        lab_price_1 = new QLabel(ReservWindow);
        lab_price_1->setObjectName("lab_price_1");
        lab_price_1->setGeometry(QRect(100, 140, 58, 15));

        retranslateUi(ReservWindow);

        QMetaObject::connectSlotsByName(ReservWindow);
    } // setupUi

    void retranslateUi(QDialog *ReservWindow)
    {
        ReservWindow->setWindowTitle(QCoreApplication::translate("ReservWindow", "Dialog", nullptr));
        lab_fio->setText(QCoreApplication::translate("ReservWindow", "\320\244\320\230\320\236", nullptr));
        lab_tel->setText(QCoreApplication::translate("ReservWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        lab_route->setText(QCoreApplication::translate("ReservWindow", "\320\234\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        lab_place->setText(QCoreApplication::translate("ReservWindow", "\320\234\320\265\321\201\321\202\320\276", nullptr));
        lab_price->setText(QCoreApplication::translate("ReservWindow", "\320\236\320\277\320\273\320\260\321\202\320\260", nullptr));
        pb_enter->setText(QCoreApplication::translate("ReservWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        cb_route->setItemText(0, QCoreApplication::translate("ReservWindow", "\320\235. \320\235\320\276\320\262\320\263\320\276\321\200\320\276\320\264", nullptr));
        cb_route->setItemText(1, QCoreApplication::translate("ReservWindow", "\320\230\320\262\320\260\320\275\320\276\320\262\320\276", nullptr));
        cb_route->setItemText(2, QCoreApplication::translate("ReservWindow", "\320\232\320\276\321\201\321\202\321\200\320\276\320\274\320\260", nullptr));
        cb_route->setItemText(3, QCoreApplication::translate("ReservWindow", "\320\257\321\200\320\276\321\201\320\273\320\260\320\262\320\273\321\214", nullptr));
        cb_route->setItemText(4, QCoreApplication::translate("ReservWindow", "\320\241\320\265\321\200\320\263\320\270\320\265\320\262 \320\237\320\276\321\201\320\260\320\264", nullptr));
        cb_route->setItemText(5, QCoreApplication::translate("ReservWindow", "\320\234\320\276\321\201\320\272\320\262\320\260", nullptr));
        cb_route->setItemText(6, QCoreApplication::translate("ReservWindow", "\320\240\321\217\320\267\320\260\320\275\321\214", nullptr));
        cb_route->setItemText(7, QCoreApplication::translate("ReservWindow", "\320\220\321\200\320\267\320\260\320\274\320\260\321\201", nullptr));

        lab_price_1->setText(QCoreApplication::translate("ReservWindow", "350 \321\200\321\203\320\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReservWindow: public Ui_ReservWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVWINDOW_H
