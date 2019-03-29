#pragma once
#include <QtWidgets/QPushButton>

class MyLittleButton : public QPushButton {
	Q_OBJECT
public:
	explicit MyLittleButton(QWidget *parent = Q_NULLPTR);
public slots:
	void plus();
private:
	int i;
};
