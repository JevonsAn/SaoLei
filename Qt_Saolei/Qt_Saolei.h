#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_Saolei.h"

class Qt_Saolei : public QMainWindow
{
	Q_OBJECT

public:
	Qt_Saolei(QWidget *parent = Q_NULLPTR);

private:
	Ui::Qt_SaoleiClass ui;
};
