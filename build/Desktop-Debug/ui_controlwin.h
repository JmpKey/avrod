/********************************************************************************
** Form generated from reading UI file 'controlwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWIN_H
#define UI_CONTROLWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ControlWin
{
public:
    QLineEdit *le_ticket;
    QLabel *lab_ticket;
    QPushButton *pb_enter;

    void setupUi(QDialog *ControlWin)
    {
        if (ControlWin->objectName().isEmpty())
            ControlWin->setObjectName("ControlWin");
        ControlWin->resize(234, 97);
        le_ticket = new QLineEdit(ControlWin);
        le_ticket->setObjectName("le_ticket");
        le_ticket->setGeometry(QRect(90, 20, 121, 22));
        lab_ticket = new QLabel(ControlWin);
        lab_ticket->setObjectName("lab_ticket");
        lab_ticket->setGeometry(QRect(10, 20, 71, 16));
        pb_enter = new QPushButton(ControlWin);
        pb_enter->setObjectName("pb_enter");
        pb_enter->setGeometry(QRect(90, 50, 121, 23));

        retranslateUi(ControlWin);

        QMetaObject::connectSlotsByName(ControlWin);
    } // setupUi

    void retranslateUi(QDialog *ControlWin)
    {
        ControlWin->setWindowTitle(QCoreApplication::translate("ControlWin", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214", nullptr));
        lab_ticket->setText(QCoreApplication::translate("controlwin", "\320\232\320\276\320\264 \320\261\320\270\320\273\320\265\321\202\320\260", nullptr));
        pb_enter->setText(QCoreApplication::translate("ControlWin", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlWin: public Ui_ControlWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWIN_H
