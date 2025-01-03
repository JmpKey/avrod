/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_reg;
    QAction *action_enter;
    QAction *action_exit_u;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_add_tick;
    QPushButton *pb_del_no_block;
    QPushButton *pb_clear_route_dat;
    QPushButton *pb_control;
    QPushButton *pb_info;
    QPushButton *pb_del_tick;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_save;
    QPushButton *pb_update;
    QPushButton *pb_cancel;
    QPushButton *pb_chek_data;
    QPushButton *pb_to_file;
    QMenuBar *menubar;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(692, 386);
        action_reg = new QAction(MainWindow);
        action_reg->setObjectName("action_reg");
        action_enter = new QAction(MainWindow);
        action_enter->setObjectName("action_enter");
        action_exit_u = new QAction(MainWindow);
        action_exit_u->setObjectName("action_exit_u");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 671, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pb_add_tick = new QPushButton(gridLayoutWidget);
        pb_add_tick->setObjectName("pb_add_tick");

        horizontalLayout_3->addWidget(pb_add_tick);

        pb_del_no_block = new QPushButton(gridLayoutWidget);
        pb_del_no_block->setObjectName("pb_del_no_block");

        horizontalLayout_3->addWidget(pb_del_no_block);

        pb_clear_route_dat = new QPushButton(gridLayoutWidget);
        pb_clear_route_dat->setObjectName("pb_clear_route_dat");

        horizontalLayout_3->addWidget(pb_clear_route_dat);

        pb_control = new QPushButton(gridLayoutWidget);
        pb_control->setObjectName("pb_control");

        horizontalLayout_3->addWidget(pb_control);

        pb_info = new QPushButton(gridLayoutWidget);
        pb_info->setObjectName("pb_info");

        horizontalLayout_3->addWidget(pb_info);

        pb_del_tick = new QPushButton(gridLayoutWidget);
        pb_del_tick->setObjectName("pb_del_tick");

        horizontalLayout_3->addWidget(pb_del_tick);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pb_save = new QPushButton(gridLayoutWidget);
        pb_save->setObjectName("pb_save");

        horizontalLayout->addWidget(pb_save);

        pb_update = new QPushButton(gridLayoutWidget);
        pb_update->setObjectName("pb_update");

        horizontalLayout->addWidget(pb_update);

        pb_cancel = new QPushButton(gridLayoutWidget);
        pb_cancel->setObjectName("pb_cancel");

        horizontalLayout->addWidget(pb_cancel);

        pb_chek_data = new QPushButton(gridLayoutWidget);
        pb_chek_data->setObjectName("pb_chek_data");

        horizontalLayout->addWidget(pb_chek_data);

        pb_to_file = new QPushButton(gridLayoutWidget);
        pb_to_file->setObjectName("pb_to_file");

        horizontalLayout->addWidget(pb_to_file);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 692, 20));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_2->menuAction());
        menu_2->addAction(action_reg);
        menu_2->addAction(action_enter);
        menu_2->addAction(action_exit_u);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_reg->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        action_enter->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        action_exit_u->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        pb_add_tick->setText(QCoreApplication::translate("MainWindow", "\320\222\320\267\321\217\321\202\321\214 \320\261\320\270\320\273\320\265\321\202", nullptr));
        pb_del_no_block->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273. \320\275\320\265\320\260\320\272\321\202\320\270\320\262.", nullptr));
        pb_clear_route_dat->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        pb_control->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214", nullptr));
        pb_info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        pb_del_tick->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\261\320\270\320\273\320\265\321\202", nullptr));
        pb_save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pb_update->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pb_cancel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pb_chek_data->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        pb_to_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\321\221\321\202", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
