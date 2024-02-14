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
 
void Time(int s, int m, int h) { //Функция для вывода секундомера
	cout << "Текущее время = " << h << " : " << m << " : " << s << endl << endl;
}

void Menu() { // Функция с меню возможных тренировок
	cout << "Какую тренировку желаете начать? " << endl;
	cout << "Бег - нажмите 1" << endl;
	cout << "Ходьба - нажмите 2" << endl;
	cout << "Плавание - нажмите 3" << endl;
	cout << "Велосипед - нажмите 4" << endl;
}

string Table(int num, string name) { // Функция определения названия тренировки
	switch (num) {
	case 1:
		name = "Бег";
		break;
	case 2:
		name = "Ходьба";
		break;
	case 3:
		name = "Плавание";
		break;
	case 4:
		name = "Велосипед";
		break;
	default:
		name = "Не выбрано";
		break;	
	}
	return name;
}

int main() {
	setlocale(LC_ALL, "Russian");
	workout step; // Создаем обьект структуры тренировки
	workout smass[100]; // Создаем массив структур с тренировками
	
	int sec = 0, min = 0, hour = 0; // Переменные отвечающие за показатели времени
	int go = 0; // Переменная запуска таймера
	int type = 0; // Переменная для выбора типа тренировки
	int counter = 0; // Количество сохраненных тренировок
	string name;
	
	Menu(); // Выводим меню тренировок для пользователя
	cin >> type; // Запрашиваем название тренировки
	cout << "Тип тренировки: " << Table(type, name); // Определяем название тренировки

	cout << " Запустить секундомер? 1 - да, 0 - нет" << endl;
	cin >> go; // Запрашиваем от пользователя разименованный указатель

	while (go == 1) {  // Вечный цикл времени, остановка будет в обновлении 

		system("cls");
		cout << "Тип тренировки: " << Table(type, name) << endl;
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
			_getch(); // Останавливаем консоль
			cout << "Пауза! Чтобы продолжить нажмите 1, чтобы выйти и сохранить нажмите 0: ";
			cin >> go;
		}
	}
	step.hour = hour; // Заполняем поля первого обьекта структуры
	step.minute = min;
	step.second = sec;
	step.name = Table(type, name);

	smass[0] = step; // Кладем готовую структуру в массив
	counter++;

	cout << step.name << "\t" << step.hour << "\t" << step.minute << "\t" << step.second << endl;

	return 0;
}