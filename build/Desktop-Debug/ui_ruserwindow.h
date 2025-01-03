/********************************************************************************
** Form generated from reading UI file 'ruserwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUSERWINDOW_H
#define UI_RUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RUserWindow
{
public:
    QPushButton *pb_registr;
    QLineEdit *le_uname;
    QLineEdit *le_passu;
    QLabel *lab_uname;
    QLabel *lab_passu;
    QLabel *lab_passu1;
    QLineEdit *le_passu1;

    void setupUi(QDialog *RUserWindow)
    {
        if (RUserWindow->objectName().isEmpty())
            RUserWindow->setObjectName("RUserWindow");
        RUserWindow->resize(275, 164);
        pb_registr = new QPushButton(RUserWindow);
        pb_registr->setObjectName("pb_registr");
        pb_registr->setGeometry(QRect(130, 120, 131, 23));
        le_uname = new QLineEdit(RUserWindow);
        le_uname->setObjectName("le_uname");
        le_uname->setGeometry(QRect(130, 20, 131, 22));
        le_passu = new QLineEdit(RUserWindow);
        le_passu->setObjectName("le_passu");
        le_passu->setGeometry(QRect(130, 50, 131, 22));
        le_passu->setEchoMode(QLineEdit::EchoMode::Password);
        lab_uname = new QLabel(RUserWindow);
        lab_uname->setObjectName("lab_uname");
        lab_uname->setGeometry(QRect(10, 20, 81, 16));
        lab_passu = new QLabel(RUserWindow);
        lab_passu->setObjectName("lab_passu");
        lab_passu->setGeometry(QRect(10, 50, 58, 15));
        lab_passu1 = new QLabel(RUserWindow);
        lab_passu1->setObjectName("lab_passu1");
        lab_passu1->setGeometry(QRect(10, 80, 121, 16));
        le_passu1 = new QLineEdit(RUserWindow);
        le_passu1->setObjectName("le_passu1");
        le_passu1->setGeometry(QRect(130, 80, 131, 22));
        le_passu1->setEchoMode(QLineEdit::EchoMode::Password);

        retranslateUi(RUserWindow);

        QMetaObject::connectSlotsByName(RUserWindow);
    } // setupUi

    void retranslateUi(QDialog *RUserWindow)
    {
        RUserWindow->setWindowTitle(QCoreApplication::translate("RUserWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pb_registr->setText(QCoreApplication::translate("RUserWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        lab_uname->setText(QCoreApplication::translate("RUserWindow", "\320\230\320\274\321\217 (\320\275\320\270\320\272 EN)", nullptr));
        lab_passu->setText(QCoreApplication::translate("RUserWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lab_passu1->setText(QCoreApplication::translate("RUserWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RUserWindow: public Ui_RUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUSERWINDOW_H
