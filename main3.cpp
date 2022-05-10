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
bool value_ch = true; //true �������� ��������� �����, false �������� ��������� ������

void menu_output(euro&, dollar&, pound_sterling&, yen&);
short cur_menu();


void out_cur(euro& e) {
	cout << "����� ";
	if (value_ch)
		cout << value_left << " : " << e.rubleTOcur(value_left) << " ����\n";
	else cout << e.curTOruble(value_right) << " : " << value_right << " ����\n";
}
void out_cur(dollar& d) {
	cout << "����� ";
	if (value_ch)
		cout << value_left << " : " << d.rubleTOcur(value_left) << " ������\n";
	else cout << d.curTOruble(value_right) << " : " << value_right << " ������\n";
}

void out_cur(pound_sterling& p) {
	cout << "����� ";
	if (value_ch)
		cout << value_left << " : " << p.rubleTOcur(value_left) << " ���� ����������\n";
	else cout << p.curTOruble(value_right) << " : " << value_right << " ���� ����������\n";
}
void out_cur(yen& y) {
	cout << "����� ";
	if (value_ch)
		cout << value_left << " : " << y.rubleTOcur(value_left) << " �������� ����\n";
	else cout << y.curTOruble(value_right) << " : " << value_right << " �������� ����\n";
}
void saveData(euro& e, dollar& d, pound_sterling& p, yen& y, ofstream& op1) {
	op1 << "����� ";
	if (value_ch)
		op1 << value_left << " : " << e.rubleTOcur(value_left) << " ����\n";
	else op1 << e.curTOruble(value_right) << " : " << value_right << " ����\n";
	op1 << "����� ";
	if (value_ch)
		op1 << value_left << " : " << d.rubleTOcur(value_left) << " ������\n";
	else op1 << d.curTOruble(value_right) << " : " << value_right << " ������\n";

	op1 << "����� ";
	if (value_ch)
		op1 << value_left << " : " << p.rubleTOcur(value_left) << " ���� ����������\n";
	else op1 << p.curTOruble(value_right) << " : " << value_right << " ���� ����������\n";
	op1 << "����� ";
	if (value_ch)
		op1 << value_left << " : " << y.rubleTOcur(value_left) << " �������� ����\n";
	else op1 << y.curTOruble(value_right) << " : " << value_right << " �������� ����\n";
}


int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	ofstream fout("Result.txt");
	//������������� ��������
	euro e;
	dollar d;
	pound_sterling p;
	yen y;

	int horizontal_pointer = 1;
	char tmp; //��������� ��������� ��������
	char key; //����� �����
	bool ENTER_;
	bool exit = false;

	while (!exit) {
		//����� ���� � ������� �����������
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
		cout << "����� ��������: " << horizontal_pointer << endl;

		//���������� ����
		ENTER_ = false;
		tmp = _getch();
		if (tmp == 224) //�������� ���������
			key = _getch();
		else key = tmp;

		switch (key) {
		case 75: //������� �����
			if (horizontal_pointer != 1)
				horizontal_pointer--;
			break;
		case 77: //������� ������
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

		//���������� �����
		if (ENTER_) {
			switch (horizontal_pointer) {
			case 1:
				cout << "������� ���������� ������ ��� �������� � ������: ";
				cin >> value_left;
				value_ch = true;
				break;
			case 2:
				cout << "������� ���������� ������ ��� �������� � �����: ";
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
		cout << "1. ����\n2. ������\n3. ���� ����������\n4. �������� ����\n";
		cout << "������� ����� ��������: ";
		cin >> currency;
		if (currency >= 1 && currency <= 4)
			break;
	} while (true);
	return currency;
}

void menu_output(euro& e, dollar& d, pound_sterling& p, yen& y) {
	system("cls");
	cout << "��������: 1 - ����� � ������, 2 - ������ � �����, 3 - ������� ������\n";
	cout << "�������\"e\" ��� �������� ���������\n�������\"s\" ��� ���������� ����� � ����\n";
	cout << "1 ����� = " << e.ratio() << " ����\n";
	cout << "1 ����� = " << d.ratio() << " ������\n";
	cout << "1 ����� = " << p.ratio() << " ���� ����������\n";
	cout << "1 ����� = " << y.ratio() << " �������� ����\n\n";
}