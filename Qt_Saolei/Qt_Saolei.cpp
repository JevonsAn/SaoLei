#include <random>
#include <algorithm>
#include <time.h>
#include "Qt_Saolei.h"
using std::vector;
using std::unordered_set;
using std::default_random_engine;
using std::max;
using std::min;

Qt_Saolei::Qt_Saolei(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	start(); // this->
}

void Qt_Saolei::clickone() {
	int x, y;
	MyLittleButton* buttons = ui.buttons;
	MyLittleButton* button = qobject_cast<MyLittleButton*>(sender());  // buttons + x * 10 + y;
	x = (button - buttons) / 10;
	y = (button - buttons) % 10;
	this->clickxy(x, y);
}

void Qt_Saolei::clickxy(const int& x, const int& y) {
	if (stop) {
		restart();
		return;
	}

	if (visitnum >= 100 - 10) {
		restart();
		return;
	}

	if (visited[x][y]) {
		return;
	}
	visited[x][y] = 1;
	visitnum++;
	int n = nums[x][y];
	MyLittleButton* buttons = ui.buttons;
	if (n < 0) {
		for (unordered_set<int>::iterator it = bugs.begin(); it != bugs.end(); it++) {
			(buttons + *it)->setText(QString(QString::number(-1)));
		}
		stop = true;
	}
	else if (n > 0) {
		(buttons + x * 10 + y)->setText(QString(QString::number(n)));
	}
	else {
		(buttons + x * 10 + y)->setText(QString(QString::number(0)));
		for (int m = max(x - 1, 0); m <= min(x + 1, 9); m++) {
			for (int n = max(y - 1, 0); n <= min(y + 1, 9); n++) {
				if (!(m==x && n==y))
					clickxy(m, n);
			}
		}		
	}
}

void Qt_Saolei::start() {
	stop = false;
	visitnum = 0;
	visited.clear();
	for (int i = 0; i < 10; i++) {
		visited.push_back(vector<int>(10, 0));
	}

	nums.clear();
	for (int i = 0; i < 10; i++) {
		nums.push_back(vector<int>(10, 0));
	}

	bugs.clear();
	default_random_engine e;
	e.seed(time(NULL));
	while (bugs.size() < 10) {
		int t = e() % 100;
		if (bugs.find(t) == bugs.end()) {
			bugs.emplace(t);
		}
	}

	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < 10; j++) {
			if (bugs.find(i * 10 + j) != bugs.end()) {
				nums[i][j] = -1;
				continue;
			}
			int ns = 0;
			for (int m = max(i - 1, 0); m <= min(i + 1,9); m++) {
				for (int n = max(j - 1,0); n <= min(j + 1,9); n++) {
					if (bugs.find(m * 10 + n) != bugs.end()) {
						ns++;
					}			
				}
			}
			nums[i][j] = ns;
		}
	}

	/*MyLittleButton* buttons = ui.buttons;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			MyLittleButton* button = buttons + i * 10 + j;
			// QObject::connect(button, SIGNAL(clicked()), this, SLOT([](int a, int b) -> {this->clickone(a,b) }(i, j))); // clickone(i,j)
			QObject::connect(button, SIGNAL(clicked()), this, SLOT(clickone())); // clickone(i,j)
		}
	}*/
}

void Qt_Saolei::restart() {
	MyLittleButton* buttons = ui.buttons;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			MyLittleButton* button = buttons + i * 10 + j;
			button->setText(QString(""));
		}
	}
	this->start();
}