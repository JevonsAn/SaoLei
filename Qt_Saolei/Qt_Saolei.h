#pragma once

#include <QtWidgets/QMainWindow>
#include <unordered_set>
#include "ui_Qt_Saolei.h"
using std::vector; 
using std::unordered_set;

class Qt_Saolei : public QMainWindow
{
	Q_OBJECT

public:
	Qt_Saolei(QWidget *parent = Q_NULLPTR);
public slots:
	void restart();
	void clickone();
private:
	Ui::Qt_SaoleiClass ui;
	unordered_set<int> bugs;
	vector<vector<int>> visited;
	vector<vector<int>> nums;
	int visitnum;
	bool stop;
	void start();
	void clickxy(const int &x, const int &y);
};
