#include <iostream>
#include <Windows.h>
#include <locale>
#include <fstream>
#include <conio.h>
#include "ruble.h"
#include "dollar.h"
#include "euro.h"
#include "pound_sterling.h"
#include "yen.h"

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

short cur = 1; //1 = euro, 2 = dollar, 3 = pound, 4 = yen
double value_left = 1, value_right;
bool value_ch = true; //true последне изменЄнное слева, false последне изменЄнное справо

void menu_output(euro&, dollar&, pound_sterling&, yen&);
short cur_menu();


void out_cur(euro& e) {
	cout << "рубль ";
	if (value_ch)
		cout << value_left << " : " << e.rubleTOcur(value_left) << " евро\n";
	else cout << e.curTOruble(value_right) << " : " << value_right << " евро\n";
}
void out_cur(dollar& d) {
	cout << "рубль ";
	if (value_ch)
		cout << value_left << " : " << d.rubleTOcur(value_left) << " доллар\n";
	else cout << d.curTOruble(value_right) << " : " << value_right << " доллар\n";
}

void out_cur(pound_sterling& p) {
	cout << "рубль ";
	if (value_ch)
		cout << value_left << " : " << p.rubleTOcur(value_left) << " фунт стерлингов\n";
	else cout << p.curTOruble(value_right) << " : " << value_right << " фунт стерлингов\n";
}
void out_cur(yen& y) {
	cout << "рубль ";
	if (value_ch)
		cout << value_left << " : " << y.rubleTOcur(value_left) << " €понска€ иена\n";
	else cout << y.curTOruble(value_right) << " : " << value_right << " €понска€ иена\n";
}
void saveData(euro& e, dollar& d, pound_sterling& p, yen& y, ofstream& op1) {
	op1 << "рубль ";
	if (value_ch)
		op1 << value_left << " : " << e.rubleTOcur(value_left) << " евро\n";
	else op1 << e.curTOruble(value_right) << " : " << value_right << " евро\n";
	op1 << "рубль ";
	if (value_ch)
		op1 << value_left << " : " << d.rubleTOcur(value_left) << " доллар\n";
	else op1 << d.curTOruble(value_right) << " : " << value_right << " доллар\n";

	op1 << "рубль ";
	if (value_ch)
		op1 << value_left << " : " << p.rubleTOcur(value_left) << " фунт стерлингов\n";
	else op1 << p.curTOruble(value_right) << " : " << value_right << " фунт стерлингов\n";
	op1 << "рубль ";
	if (value_ch)
		op1 << value_left << " : " << y.rubleTOcur(value_left) << " €понска€ иена\n";
	else op1 << y.curTOruble(value_right) << " : " << value_right << " €понска€ иена\n";
}


int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	ofstream fout("Result.txt");
	//инициализаци€ объектов
	euro e;
	dollar d;
	pound_sterling p;
	yen y;

	int horizontal_pointer = 1;
	char tmp; //временное хранилище символов
	char key; //выбор опции
	bool ENTER_;
	bool exit = false;

	while (!exit) {
		//вывод меню и рассчЄт соотношений
		menu_output(e, d, p, y);
		switch (cur) {
		case 1:
			out_cur(e);
			break;
		case 2:
			out_cur(d);
			break;
		case 3:
			out_cur(p);
			break;
		case 4:
			out_cur(y);
			break;
		}
		cout << "выбор действи€: " << horizontal_pointer << endl;

		//управление меню
		ENTER_ = false;
		tmp = _getch();
		if (tmp == 224) //проверка стрелочек
			key = _getch();
		else key = tmp;

		switch (key) {
		case 75: //стрелка влево
			if (horizontal_pointer != 1)
				horizontal_pointer--;
			break;
		case 77: //стрелка вправо
			if (horizontal_pointer != 3)
				horizontal_pointer++;
			break;
		case 13:
			ENTER_ = true;
			break;
		case 'e':
			exit = true;
			break;
		case 's':
			saveData(e, d, p, y, fout);
			break;
		}

		//реализаци€ опции
		if (ENTER_) {
			switch (horizontal_pointer) {
			case 1:
				cout << "¬ведите количество рублей дл€ перевода в валюту: ";
				cin >> value_left;
				value_ch = true;
				break;
			case 2:
				cout << "¬ведите количество валюты дл€ перевода в рубли: ";
				cin >> value_right;
				value_ch = false;
				break;
			case 3:
				cur = cur_menu();
				break;
			}
		}
	}

	return 0;
}

short cur_menu() {
	short currency = 0;
	do {
		//system("cls");
		cout << "1. ≈вро\n2. ƒоллар\n3. ‘унт стерлингов\n4. японска€ иена\n";
		cout << "¬ведите номер действи€: ";
		cin >> currency;
		if (currency >= 1 && currency <= 4)
			break;
	} while (true);
	return currency;
}

void menu_output(euro& e, dollar& d, pound_sterling& p, yen& y) {
	system("cls");
	cout << "ƒействи€: 1 - рубль в валюту, 2 - валюту в рубль, 3 - сменить валюту\n";
	cout << "¬ведите\"e\" дл€ закрыти€ программы\n¬ведите\"s\" дл€ сохранени€ валют в файл\n";
	cout << "1 рубль = " << e.ratio() << " евро\n";
	cout << "1 рубль = " << d.ratio() << " доллар\n";
	cout << "1 рубль = " << p.ratio() << " фунт стерлингов\n";
	cout << "1 рубль = " << y.ratio() << " €понска€ иена\n\n";
}