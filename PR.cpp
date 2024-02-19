#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

struct workout { // Создаем структуру для сохранения тренировок
	string name = " ";
	int hour = 0;
	int minute = 0;
	int second = 0;
};
 
void Time(int &s, int &m, int &h) { // Функция для вывода секундомера или таймера
	cout << "Текущее время = " << h << " : " << m << " : " << s << endl << endl;
}

void DataTime(int &s, int &m, int &h) { // Функция задания времени для таймера
	cout << "Установите количество часов: ";
	cin >> h;
	cout << "Установите количество минут: ";
	cin >> m;
	cout << "Установите количество секунд: ";
	cin >> s;
	if (s == 0 && m == 0 && h == 0) {
		system("cls");
		cout << "Ошибка" << endl;
		DataTime(s,m,h); // Простенькая рекурсия, если данные заполнены нулями
	}
}

void Menu() { // Функция с меню возможных тренировок
	cout << "Какую тренировку желаете начать? " << endl;
	cout << "Бег       - нажмите 1" << endl;
	cout << "Ходьба    - нажмите 2" << endl;
	cout << "Плавание  - нажмите 3" << endl;
	cout << "Велосипед - нажмите 4" << endl;
}

void stopwatch(int &sec, int &min, int &hour, int go, string name2) { // Секундомер, берем ссылки у полученных данных, чтобы их не копировать

	while (go == 1) {  // Цикл хода времени

		system("cls");
		cout << "Тип тренировки: " << name2 << endl << endl;
		cout << "Чтобы остановить нажмите - 0" << endl << endl;
		Time(sec, min, hour);

		Sleep(950); // Замедление консоли, для имитации течения времени
		sec++;
		if (sec == 60) {
			min++;
			sec = 0;
		}
		else if (min == 60) {
			hour++;
			min = 0;
		}
		if (_kbhit()) { // Отслеживаем нажатие клавиши с клавиатуры
			cout << "Пауза! Чтобы продолжить нажмите 1, чтобы выйти и сохранить нажмите 0: " << endl;
			cin >> go;
			if (go == 2) { // Правило чтобы не попасть в таймер
				go = 0;
			}
		}
	}
}

void timer(int& sec, int& min, int& hour, int go, string name2) { // Таймер, берем ссылки у полученных данных, чтобы их не копировать
	if (go == 2) {
		DataTime(sec, min, hour); //Задаем стартовое время
	}
	while (go == 2) {  // Цикл таймера
		if (sec == 0 && min == 0 && hour == 0) { // Когда время пройдет - завершаем цикл
			break;
		}
		system("cls");
		cout << "Тип тренировки: " << name2 << endl << endl;
		cout << "Чтобы остановить нажмите - 0" << endl << endl;
		Time(sec, min, hour);

		Sleep(950); // Замедление консоли, для имитации течения времени
		sec--;
		if (sec == 0 && min > 0) {
			min--;
			sec = 60;
		}
		else if (min == 0 && sec == 0 && hour > 0) {
			hour--;
			min = 60;
		}
		if (_kbhit()) { // Отслеживаем нажатие клавиши с клавиатуры
			cout << "Пауза! Чтобы продолжить нажмите 2, чтобы выйти нажмите 0: " << endl;
			cin >> go;
		}
	}
}

string Table(int num, string name) { // Функция определения названия тренировки
	switch (num) {
	case 1:
		name = "Бег       "; // Записываем одинаковое количество символов в строку для ровного вывода
		break;
	case 2:
		name = "Ходьба    ";
		break;
	case 3:
		name = "Плавание  ";
		break;
	case 4:
		name = "Велосипед ";
		break;
	default:
		name = "Не выбрано";
		break;	
	}
	return name;
}

int main() {
	setlocale(LC_ALL, "Russian");
	const int SIZE = 50; // Делаем константный размер массива
	workout step; // Создаем обьект структуры тренировки
	workout smass[SIZE]; // Создаем массив структур с тренировками
	
	int sec = 0, min = 0, hour = 0; // Переменные отвечающие за показатели времени
	int go = 0; // Переменная запуска таймера
	int type = 0; // Переменная для выбора типа тренировки
	int counter = 0; // Количество сохраненных тренировок в массиве
	int select = 0; // Выбранный тип гаджета
	int repeat = 0; // Новая тренировка
	string name; // переменные для имени
	string name2;

	do {
		Menu(); // Выводим меню тренировок для пользователя
		cin >> type; // Запрашиваем название тренировки
		name2 = Table(type, name); // Определяем название тренировки и присваиваем новой переменной

		cout << "Тип тренировки: " << name2 << endl;
		cout << "Запустить секундомер? - 1, Запустить таймер - 2" << endl;
		cin >> go; // Запрашиваем от пользователя разрешение что запустить
		select = go; // Записываем выбранный код тренировки

		if (select == 1) {
			stopwatch(sec, min, hour, go, name2); // Секундомер
		}
		else if (select == 2) {
			timer(sec, min, hour, go, name2); // Таймер
		}

		if (select == 1) { //Сохраняем тренировку по секундомеру
			step.hour = hour; // Заполняем поля первого обьекта структуры
			step.minute = min;
			step.second = sec;
			step.name = name2;

			smass[counter] = step;
			counter++;
 		}

		if (select == 1) { // В зависимости от типа замера времени - выводим результат
			cout << "Результат занятия: " << step.name << "\t" << step.hour << " часы\t" << step.minute << " минуты\t" << step.second << " секунды" << endl;
		}
		else if (select == 2) {
			cout << "Тренировка завершена!" << endl;
		}
		cout << "Запустить новую тренировку? 1 - да, 0 - нет, 2 - выгрузить мои тренировки" << endl; // Спрашиваем желание запустить новую тренировку
		cin >> repeat;
		sec = 0, min = 0, hour = 0; // Обнуляем время для новой тренировки
		system("cls");

		switch (repeat) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			system("cls");
			cout << "Список моих тренировок: " << endl << endl;
			for (int i = 0; i < counter; i++) { // Выводим список моих тренировок
				cout << smass[i].name << "\t" << smass[i].hour << " час    \t" << smass[i].minute << " минуты \t" << smass[i].second << " секунды\t" << endl;
			}
			cout << endl; // Это для красоты
			cout << "Запустить новую тренировку? 1 - да, 0 - нет" << endl; // Спрашиваем желание запустить новую тренировку
			cin >> repeat;
		}	
	} while (repeat == 1);

	return 0;
}
