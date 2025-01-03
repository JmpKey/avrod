/********************************************************************************
** Form generated from reading UI file 'euserwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EUSERWINDOW_H
#define UI_EUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EUserWindow
{
public:
    QPushButton *pb_enteru;
    QLabel *lab_uname;
    QLabel *lab_passu;
    QLineEdit *le_uname;
    QLineEdit *le_passu;

    void setupUi(QDialog *EUserWindow)
    {
        if (EUserWindow->objectName().isEmpty())
            EUserWindow->setObjectName("EUserWindow");
        EUserWindow->resize(225, 123);
        pb_enteru = new QPushButton(EUserWindow);
        pb_enteru->setObjectName("pb_enteru");
        pb_enteru->setGeometry(QRect(90, 80, 121, 23));
        lab_uname = new QLabel(EUserWindow);
        lab_uname->setObjectName("lab_uname");
        lab_uname->setGeometry(QRect(10, 20, 81, 16));
        lab_passu = new QLabel(EUserWindow);
        lab_passu->setObjectName("lab_passu");
        lab_passu->setGeometry(QRect(10, 50, 58, 15));
        le_uname = new QLineEdit(EUserWindow);
        le_uname->setObjectName("le_uname");
        le_uname->setGeometry(QRect(92, 20, 121, 22));
        le_passu = new QLineEdit(EUserWindow);
        le_passu->setObjectName("le_passu");
        le_passu->setGeometry(QRect(92, 50, 121, 22));
        le_passu->setEchoMode(QLineEdit::EchoMode::Password);

        retranslateUi(EUserWindow);

        QMetaObject::connectSlotsByName(EUserWindow);
    } // setupUi

    void retranslateUi(QDialog *EUserWindow)
    {
        EUserWindow->setWindowTitle(QCoreApplication::translate("EUserWindow", "\320\222\321\205\320\276\320\264", nullptr));
        pb_enteru->setText(QCoreApplication::translate("EUserWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        lab_uname->setText(QCoreApplication::translate("EUserWindow", "\320\230\320\274\321\217 (\320\275\320\270\320\272 EN)", nullptr));
        lab_passu->setText(QCoreApplication::translate("EUserWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EUserWindow: public Ui_EUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EUSERWINDOW_H
