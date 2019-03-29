#include <string>
#include "MyLittleButton.h"
MyLittleButton::MyLittleButton(QWidget *parent) : QPushButton(parent) {
	i = 0;
	this->setObjectName(QStringLiteral(""));
	this->setEnabled(true);
	this->setMaximumSize(QSize(40, 40));
};

void MyLittleButton::plus(){
	i++;
	this->setText(QString(QString::number(i)));
}