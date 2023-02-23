/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QLabel *image_granta;
    QCheckBox *checkBox;
    QLabel *big_name;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(653, 579);
        MainWindow->setMinimumSize(QSize(653, 579));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result = new QLabel(centralwidget);
        result->setObjectName("result");
        result->setGeometry(QRect(150, 340, 461, 171));
        result->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(12, 11, 601, 321));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName("checkBox_4");

        gridLayout->addWidget(checkBox_4, 4, 0, 1, 1);

        checkBox_6 = new QCheckBox(layoutWidget);
        checkBox_6->setObjectName("checkBox_6");

        gridLayout->addWidget(checkBox_6, 6, 0, 1, 1);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName("checkBox_3");

        gridLayout->addWidget(checkBox_3, 3, 0, 1, 1);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName("checkBox_2");

        gridLayout->addWidget(checkBox_2, 2, 0, 1, 1);

        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName("checkBox_5");

        gridLayout->addWidget(checkBox_5, 5, 0, 1, 1);

        image_granta = new QLabel(layoutWidget);
        image_granta->setObjectName("image_granta");
        image_granta->setMaximumSize(QSize(461, 261));
        image_granta->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pictures/granta.jpeg")));
        image_granta->setScaledContents(true);

        gridLayout->addWidget(image_granta, 1, 1, 6, 1);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        big_name = new QLabel(layoutWidget);
        big_name->setObjectName("big_name");

        gridLayout->addWidget(big_name, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 653, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\263\320\260\320\267\320\270\320\275 \"\320\221\320\260\321\200\321\205\320\260\321\202\320\275\320\260\321\217 \321\202\321\217\320\263\320\260\"", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\246\320\265\320\275\320\260 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\217 - 1500000 \321\200\321\203\320\261.</p><p align=\"center\">\320\230\321\202\320\276\320\263: 1500000 \321\200\321\203\320\261.</p></body></html>", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "\320\236\320\241\320\220\320\223\320\236", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\263\320\275\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\201\320\272\320\276", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\201\320\272\320\270", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\264\320\270\321\206\320\270\320\276\320\275\320\265\321\200", nullptr));
        image_granta->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\320\275\321\213", nullptr));
        big_name->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Lada GRANTA</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
