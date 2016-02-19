/********************************************************************************
** Form generated from reading UI file 'prototype.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOTYPE_H
#define UI_PROTOTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prototypeClass
{
public:
    QAction *actionDf;
    QAction *actionSdf;
    QAction *actionSdf_2;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *tab_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_15;
    QLabel *label_16;
    QDateEdit *dateEdit_2;
    QLineEdit *lineEdit_6;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_4;
    QLabel *label_17;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton_4;
    QWidget *tab_6;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_6;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_19;
    QLabel *label_20;
    QDateEdit *dateEdit_3;
    QLineEdit *lineEdit_16;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QGroupBox *groupBox_5;
    QLabel *label_18;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_5;
    QWidget *tab_5;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_8;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_24;
    QLabel *label_25;
    QDateEdit *dateEdit_4;
    QLineEdit *lineEdit_20;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QGroupBox *groupBox_7;
    QLabel *label_23;
    QLineEdit *lineEdit_19;
    QPushButton *pushButton_7;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *prototypeClass)
    {
        if (prototypeClass->objectName().isEmpty())
            prototypeClass->setObjectName(QStringLiteral("prototypeClass"));
        prototypeClass->resize(716, 534);
        prototypeClass->setStyleSheet(QLatin1String("* {font: 8pt \"Segoe UI\"; 	color: rgb(247, 247, 247);}\n"
"\n"
"*{	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:1, stop:0.982955 rgba(46, 46, 46, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(239, 239, 239);\n"
"}\n"
"QMainWindow{\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:1, stop:0.982955 rgba(46, 46, 46, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"\n"
"QGroupBox{\n"
"border: 4px solid #8f8f91;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #5B5B5B; /* sets background of the menu */\n"
"    border: 1px solid black;\n"
"}\n"
"QMenu::item:selected { /* when user selects item using mouse or keyboard */\n"
"    background-color: #654321;\n"
"}\n"
"QMenuBar {\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:1, stop:0.982955 rgba(46, 46, 46, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    spacing: 6px; /* spacing between menu bar items */\n"
"    padding: 5p"
                        "x 10px;\n"
"    background: transparent;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"QMenuBar::item:selected { /* when selected using mouse or keyboard */\n"
"    background: #a8a8a8;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    background: #888888;\n"
"}\n"
"\n"
"QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 16px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"   color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"\n"
""));
        actionDf = new QAction(prototypeClass);
        actionDf->setObjectName(QStringLiteral("actionDf"));
        actionSdf = new QAction(prototypeClass);
        actionSdf->setObjectName(QStringLiteral("actionSdf"));
        actionSdf_2 = new QAction(prototypeClass);
        actionSdf_2->setObjectName(QStringLiteral("actionSdf_2"));
        centralWidget = new QWidget(prototypeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 0, 641, 441));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
"    border: 5px solid #C2C7CB;\n"
"	border-radius : 4px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"/*    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"*/\n"
"	\n"
"	background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:0, y2:1, stop:0.0677966 rgba(46, 46, 46, 255), stop:0.79096 rgba(150, 150, 150, 255));\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 14px;\n"
"    min-width: 8ex;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradie"
                        "nt(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"	color: rgb(42, 42, 42);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 271, 209));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEdit_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_7);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, lineEdit_7);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, comboBox);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, dateEdit);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 30, 231, 181));
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 127, 0);"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_8);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_9);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        lineEdit_10 = new QLineEdit(groupBox_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_10);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_11);

        lineEdit_11 = new QLineEdit(groupBox_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_11);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_12);

        lineEdit_12 = new QLineEdit(groupBox_2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_12);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 250, 121, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 16px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"   color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:0, y2:1, stop:0.0677966 rgba(207, 132, 42, 255), stop:0.79096 rgba(193, 193, 193, 255));\n"
"}\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"\n"
""));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 310, 541, 71));
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        textEdit->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_2 = new QTabWidget(tab_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(30, 10, 561, 371));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(70, 20, 391, 191));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 140, 131, 31));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 10, 203, 117));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(widget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 3, 0, 1, 1);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        dateEdit_2 = new QDateEdit(widget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(dateEdit_2, 1, 1, 1, 1);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(lineEdit_6, 3, 1, 1, 1);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 0, 1, 1);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 0, 1, 1);

        lineEdit_13 = new QLineEdit(widget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(lineEdit_13, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(70, 220, 391, 91));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(91, 21, 66, 16));
        lineEdit_14 = new QLineEdit(groupBox_4);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(170, 20, 101, 20));
        lineEdit_14->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 50, 131, 31));
        tabWidget_2->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        groupBox_6 = new QGroupBox(tab_6);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(70, 20, 391, 191));
        pushButton_6 = new QPushButton(groupBox_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 140, 131, 31));
        layoutWidget = new QWidget(groupBox_6);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 10, 203, 117));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 3, 0, 1, 1);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_2->addWidget(label_20, 0, 0, 1, 1);

        dateEdit_3 = new QDateEdit(layoutWidget);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));
        dateEdit_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(dateEdit_3, 1, 1, 1, 1);

        lineEdit_16 = new QLineEdit(layoutWidget);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lineEdit_16, 3, 1, 1, 1);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_2->addWidget(label_21, 1, 0, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 2, 0, 1, 1);

        lineEdit_17 = new QLineEdit(layoutWidget);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lineEdit_17, 0, 1, 1, 1);

        lineEdit_18 = new QLineEdit(layoutWidget);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lineEdit_18, 2, 1, 1, 1);

        groupBox_5 = new QGroupBox(tab_6);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(70, 220, 391, 91));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(91, 21, 66, 16));
        lineEdit_15 = new QLineEdit(groupBox_5);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(170, 20, 101, 20));
        lineEdit_15->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_5 = new QPushButton(groupBox_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(130, 50, 131, 31));
        tabWidget_2->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_8 = new QGroupBox(tab_5);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(70, 20, 391, 191));
        pushButton_8 = new QPushButton(groupBox_8);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(130, 140, 131, 31));
        layoutWidget_2 = new QWidget(groupBox_8);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(80, 10, 231, 117));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(layoutWidget_2);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_3->addWidget(label_24, 3, 0, 1, 1);

        label_25 = new QLabel(layoutWidget_2);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_3->addWidget(label_25, 0, 0, 1, 1);

        dateEdit_4 = new QDateEdit(layoutWidget_2);
        dateEdit_4->setObjectName(QStringLiteral("dateEdit_4"));
        dateEdit_4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(dateEdit_4, 1, 1, 1, 1);

        lineEdit_20 = new QLineEdit(layoutWidget_2);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lineEdit_20, 3, 1, 1, 1);

        label_26 = new QLabel(layoutWidget_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_3->addWidget(label_26, 1, 0, 1, 1);

        label_27 = new QLabel(layoutWidget_2);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_3->addWidget(label_27, 2, 0, 1, 1);

        lineEdit_21 = new QLineEdit(layoutWidget_2);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lineEdit_21, 0, 1, 1, 1);

        lineEdit_22 = new QLineEdit(layoutWidget_2);
        lineEdit_22->setObjectName(QStringLiteral("lineEdit_22"));
        lineEdit_22->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lineEdit_22, 2, 1, 1, 1);

        groupBox_7 = new QGroupBox(tab_5);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(70, 220, 391, 91));
        label_23 = new QLabel(groupBox_7);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(91, 21, 66, 16));
        lineEdit_19 = new QLineEdit(groupBox_7);
        lineEdit_19->setObjectName(QStringLiteral("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(170, 20, 101, 20));
        lineEdit_19->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_7 = new QPushButton(groupBox_7);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(130, 50, 131, 31));
        tabWidget_2->addTab(tab_5, QString());
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(60, 110, 511, 141));
        textEdit_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 280, 161, 41));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab_2, QString());
        prototypeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(prototypeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 24));
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        prototypeClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(prototypeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        prototypeClass->setStatusBar(statusBar);
        mainToolBar = new QToolBar(prototypeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        prototypeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionDf);
        menuFile->addAction(actionSdf);
        menuFile->addAction(actionSdf_2);

        retranslateUi(prototypeClass);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(prototypeClass);
    } // setupUi

    void retranslateUi(QMainWindow *prototypeClass)
    {
        prototypeClass->setWindowTitle(QApplication::translate("prototypeClass", "prototype", 0));
        actionDf->setText(QApplication::translate("prototypeClass", "df", 0));
        actionSdf->setText(QApplication::translate("prototypeClass", "sdf", 0));
        actionSdf_2->setText(QApplication::translate("prototypeClass", "sdf", 0));
        groupBox->setTitle(QApplication::translate("prototypeClass", "Merchant Info", 0));
        label->setText(QApplication::translate("prototypeClass", "Social Security ", 0));
        label_2->setText(QApplication::translate("prototypeClass", "Name", 0));
        label_3->setText(QApplication::translate("prototypeClass", "Date of Declaration", 0));
        label_4->setText(QApplication::translate("prototypeClass", "Value($)", 0));
        label_5->setText(QApplication::translate("prototypeClass", "Source Country", 0));
        label_6->setText(QApplication::translate("prototypeClass", "Method of Arrival", 0));
        label_7->setText(QApplication::translate("prototypeClass", "Count", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("prototypeClass", "Air", 0)
         << QApplication::translate("prototypeClass", "Sea", 0)
         << QApplication::translate("prototypeClass", "Land", 0)
        );
        groupBox_2->setTitle(QApplication::translate("prototypeClass", "Product Info", 0));
        label_8->setText(QApplication::translate("prototypeClass", "Name", 0));
        label_9->setText(QApplication::translate("prototypeClass", "Manufactor", 0));
        label_10->setText(QApplication::translate("prototypeClass", "Weight", 0));
        label_11->setText(QApplication::translate("prototypeClass", "Count", 0));
        label_12->setText(QApplication::translate("prototypeClass", "Price", 0));
        pushButton->setText(QApplication::translate("prototypeClass", "Check with Laws", 0));
        textEdit->setHtml(QApplication::translate("prototypeClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">For Product X You need Certificate Y</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("prototypeClass", "Declaration", 0));
        groupBox_3->setTitle(QApplication::translate("prototypeClass", "Creation", 0));
        pushButton_3->setText(QApplication::translate("prototypeClass", "Create Certificate", 0));
        label_15->setText(QApplication::translate("prototypeClass", "Source Country", 0));
        label_16->setText(QApplication::translate("prototypeClass", "ID", 0));
        label_13->setText(QApplication::translate("prototypeClass", "Date Of Issue", 0));
        label_14->setText(QApplication::translate("prototypeClass", "Value", 0));
        lineEdit_13->setText(QString());
        groupBox_4->setTitle(QApplication::translate("prototypeClass", "GroupBox", 0));
        label_17->setText(QApplication::translate("prototypeClass", "Certificate ID", 0));
        pushButton_4->setText(QApplication::translate("prototypeClass", "Load From Database", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("prototypeClass", "Hygien Products's Health", 0));
        groupBox_6->setTitle(QApplication::translate("prototypeClass", "Creation", 0));
        pushButton_6->setText(QApplication::translate("prototypeClass", "Create Certificate", 0));
        label_19->setText(QApplication::translate("prototypeClass", "Source Company", 0));
        label_20->setText(QApplication::translate("prototypeClass", "ID", 0));
        label_21->setText(QApplication::translate("prototypeClass", "Date Of Issue", 0));
        label_22->setText(QApplication::translate("prototypeClass", "Value", 0));
        lineEdit_17->setText(QString());
        groupBox_5->setTitle(QApplication::translate("prototypeClass", "GroupBox", 0));
        label_18->setText(QApplication::translate("prototypeClass", "Certificate ID", 0));
        pushButton_5->setText(QApplication::translate("prototypeClass", "Load From Database", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("prototypeClass", "Foreign Car Import", 0));
        groupBox_8->setTitle(QApplication::translate("prototypeClass", "Creation", 0));
        pushButton_8->setText(QApplication::translate("prototypeClass", "Create Certificate", 0));
        label_24->setText(QApplication::translate("prototypeClass", "Weight", 0));
        label_25->setText(QApplication::translate("prototypeClass", "ID", 0));
        label_26->setText(QApplication::translate("prototypeClass", "Expiration Date", 0));
        label_27->setText(QApplication::translate("prototypeClass", "Value", 0));
        lineEdit_21->setText(QString());
        groupBox_7->setTitle(QApplication::translate("prototypeClass", "GroupBox", 0));
        label_23->setText(QApplication::translate("prototypeClass", "Certificate ID", 0));
        pushButton_7->setText(QApplication::translate("prototypeClass", "Load From Database", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("prototypeClass", "Luxury Product Import", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("prototypeClass", "Certificate", 0));
        textEdit_2->setHtml(QApplication::translate("prototypeClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Insert Law Description Here</p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("prototypeClass", "Create Law", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("prototypeClass", "Law", 0));
        menuFile->setTitle(QApplication::translate("prototypeClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("prototypeClass", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class prototypeClass: public Ui_prototypeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOTYPE_H
