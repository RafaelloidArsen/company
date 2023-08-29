/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionExit;
    QAction *actionAbout_Qt;
    QAction *actionAbout_author;
    QAction *actionEnglish;
    QAction *action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_2;
    QWidget *tabprojectInsert;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QLabel *label_2;
    QLineEdit *lineEditaddress;
    QLabel *label_3;
    QLineEdit *lineEditphonenumber;
    QSpinBox *spinBoxmoney;
    QLabel *label_5;
    QLineEdit *lineEditmanager;
    QLabel *label_6;
    QSpinBox *spinBoxtype;
    QLabel *label_7;
    QLineEdit *lineEditingener;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonUpdateprojects;
    QPushButton *pushButtonAddprojects;
    QPushButton *pushButtonDeleteprojects;
    QTabWidget *tabWidget;
    QWidget *tabPets;
    QGridLayout *gridLayout_2;
    QTableView *tableViewprojects;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuLanguage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(978, 544);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionAbout_author = new QAction(MainWindow);
        actionAbout_author->setObjectName(QString::fromUtf8("actionAbout_author"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(350, 0));
        tabWidget_2->setMaximumSize(QSize(250, 16777215));
        tabprojectInsert = new QWidget();
        tabprojectInsert->setObjectName(QString::fromUtf8("tabprojectInsert"));
        gridLayout_5 = new QGridLayout(tabprojectInsert);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(tabprojectInsert);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditName = new QLineEdit(tabprojectInsert);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditName);

        label_2 = new QLabel(tabprojectInsert);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditaddress = new QLineEdit(tabprojectInsert);
        lineEditaddress->setObjectName(QString::fromUtf8("lineEditaddress"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditaddress);

        label_3 = new QLabel(tabprojectInsert);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditphonenumber = new QLineEdit(tabprojectInsert);
        lineEditphonenumber->setObjectName(QString::fromUtf8("lineEditphonenumber"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditphonenumber);

        spinBoxmoney = new QSpinBox(tabprojectInsert);
        spinBoxmoney->setObjectName(QString::fromUtf8("spinBoxmoney"));

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxmoney);

        label_5 = new QLabel(tabprojectInsert);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEditmanager = new QLineEdit(tabprojectInsert);
        lineEditmanager->setObjectName(QString::fromUtf8("lineEditmanager"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditmanager);

        label_6 = new QLabel(tabprojectInsert);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        spinBoxtype = new QSpinBox(tabprojectInsert);
        spinBoxtype->setObjectName(QString::fromUtf8("spinBoxtype"));

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxtype);

        label_7 = new QLabel(tabprojectInsert);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        lineEditingener = new QLineEdit(tabprojectInsert);
        lineEditingener->setObjectName(QString::fromUtf8("lineEditingener"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditingener);

        label_4 = new QLabel(tabprojectInsert);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        gridLayout_5->addLayout(formLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButtonUpdateprojects = new QPushButton(tabprojectInsert);
        pushButtonUpdateprojects->setObjectName(QString::fromUtf8("pushButtonUpdateprojects"));

        verticalLayout_3->addWidget(pushButtonUpdateprojects);

        pushButtonAddprojects = new QPushButton(tabprojectInsert);
        pushButtonAddprojects->setObjectName(QString::fromUtf8("pushButtonAddprojects"));

        verticalLayout_3->addWidget(pushButtonAddprojects);

        pushButtonDeleteprojects = new QPushButton(tabprojectInsert);
        pushButtonDeleteprojects->setObjectName(QString::fromUtf8("pushButtonDeleteprojects"));

        verticalLayout_3->addWidget(pushButtonDeleteprojects);


        gridLayout_5->addLayout(verticalLayout_3, 1, 0, 1, 1);

        tabWidget_2->addTab(tabprojectInsert, QString());

        gridLayout->addWidget(tabWidget_2, 0, 2, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabPets = new QWidget();
        tabPets->setObjectName(QString::fromUtf8("tabPets"));
        gridLayout_2 = new QGridLayout(tabPets);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableViewprojects = new QTableView(tabPets);
        tableViewprojects->setObjectName(QString::fromUtf8("tableViewprojects"));

        gridLayout_2->addWidget(tableViewprojects, 0, 0, 1, 1);

        tabWidget->addTab(tabPets, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 978, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionConnect);
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAbout_Qt);
        menuAbout->addAction(actionAbout_author);
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(action);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "&Connect", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About &Qt", nullptr));
        actionAbout_author->setText(QCoreApplication::translate("MainWindow", "About a&uthor", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Manager", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ingener", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Money", nullptr));
        pushButtonUpdateprojects->setText(QCoreApplication::translate("MainWindow", "Update information", nullptr));
        pushButtonAddprojects->setText(QCoreApplication::translate("MainWindow", "Add new order", nullptr));
        pushButtonDeleteprojects->setText(QCoreApplication::translate("MainWindow", "Delete selected order", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabprojectInsert), QCoreApplication::translate("MainWindow", "Project", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPets), QCoreApplication::translate("MainWindow", "Projects", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "&About", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "&Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
