/********************************************************************************
** Form generated from reading UI file 'Qt_Saolei.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SAOLEI_H
#define UI_QT_SAOLEI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <vector>
#include "MyLittleButton.h"

QT_BEGIN_NAMESPACE

class Ui_Qt_SaoleiClass
{
public:
    QAction *actionqui;
	QAction *actionrestart;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
	MyLittleButton* buttons;

    void setupUi(QMainWindow *Qt_SaoleiClass)
    {
        if (Qt_SaoleiClass->objectName().isEmpty())
            Qt_SaoleiClass->setObjectName(QStringLiteral("Qt_SaoleiClass"));
        Qt_SaoleiClass->resize(430, 455);
        actionqui = new QAction(Qt_SaoleiClass);
        actionqui->setObjectName(QStringLiteral("actionqui"));
		actionrestart = new QAction(Qt_SaoleiClass);
		actionrestart->setObjectName(QStringLiteral("actionrestart"));

        centralWidget = new QWidget(Qt_SaoleiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 430, 430));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

		buttons = new MyLittleButton[10 * 10];

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				MyLittleButton* button = buttons + i * 10 + j;
				// QObject::connect(button, SIGNAL(clicked()), button, SLOT(plus()));
				// button->setMaximumSize(QSize(32, 23));
				QObject::connect(button, SIGNAL(clicked()), Qt_SaoleiClass, SLOT(clickone()));
				gridLayout->addWidget(button, i, j, 1, 1); // , Qt::AlignHCenter | Qt::AlignVCenter
			}
		}      
		
        Qt_SaoleiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qt_SaoleiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        //menuBar->setGeometry(QRect(0, 0, 299, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        Qt_SaoleiClass->setMenuBar(menuBar);
		/*mainToolBar = new QToolBar(Qt_SaoleiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Qt_SaoleiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qt_SaoleiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Qt_SaoleiClass->setStatusBar(statusBar);*/

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionqui);
		menu->addAction(actionrestart);

        retranslateUi(Qt_SaoleiClass);

		QObject::connect(actionqui, SIGNAL(triggered()), Qt_SaoleiClass, SLOT(close()));
		QObject::connect(actionrestart, SIGNAL(triggered()), Qt_SaoleiClass, SLOT(restart()));
        
		QMetaObject::connectSlotsByName(Qt_SaoleiClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_SaoleiClass)
    {
        Qt_SaoleiClass->setWindowTitle(QApplication::translate("Qt_SaoleiClass", "\346\211\253\351\233\267", nullptr));
        actionqui->setText(QApplication::translate("Qt_SaoleiClass", "quit", nullptr));
		actionrestart->setText(QApplication::translate("Qt_SaoleiClass", "restart", nullptr));
		menu->setTitle(QApplication::translate("Qt_SaoleiClass", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("Qt_SaoleiClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

	~Ui_Qt_SaoleiClass() {
		if (buttons) {
			delete[] buttons;
		}
	};

};

namespace Ui {
    class Qt_SaoleiClass: public Ui_Qt_SaoleiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SAOLEI_H
