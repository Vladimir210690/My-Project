#include <iostream>
#include "Header.h"

using namespace std;

void Menu();

int main() {
	setlocale(LC_ALL, "RU");
	double distans = 0.0, time = 0.0, temp = 0.0, speed = 0.0;
	int select = 0, repeat = 0;

	do {
		Menu();
		cin >> select;
		switch (select) {
		case 1:
			cout << "Введите дистанцию в километрах: ";
			cin >> distans;
			cout << "Введите время в минутах: ";
			cin >> time;
			cout << "Темп движения: " << Temp(distans, time) << " мин/км" << endl;
			break;
		case 2:
			cout << "Введите дистанцию в километрах: ";
			cin >> distans;
			cout << "Введите время в минутах: ";
			cin >> time;
			cout << "Скорость движения: " << Speed(distans, time) << " км/ч" << endl;
			break;
		case 3:
			cout << "Введите темп в минутах/километр: ";
			cin >> temp;
			cout << "Введите время в минутах: ";
			cin >> time;
			cout << "Дистанция движения: " << Distans(time, temp) << " км" << endl;
			break;
		case 4:
			cout << "Введите дистанцию в километрах: ";
			cin >> distans;
			cout << "Введите темп в минутах: ";
			cin >> temp;
			cout << "Время движения: " << Time(distans, temp) << " мин" << endl;
			break;
		}

		cout << "Заного? 1 - да, 0 - нет ";
		cin >> repeat;
		system("cls");
	} while (repeat == 1);
	
	return 0;
}

void Menu() {
	cout << "Что хотите посчитать?" << endl;
	cout << "Темп -      нажмите 1" << endl;
	cout << "Скорость -  нажмите 2" << endl;
	cout << "Дистанцию - нажмите 3" << endl;
	cout << "Время -     нажмите 4" << endl;
}