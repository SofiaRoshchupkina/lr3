#include "euro.h"
#include <iostream>
euro::euro() {
	std::cout << "���� �� 10.05.2022:\n 1 ���. = 0.013 ���. = 0.014 ��. = 0.012 �.�. = 1.86 �.�.\n\n��� ����: \n";
	std::cout << "������� ��������� ����� � ����: ";
	std::cin >> this->ruble_euro_ratio;
}
double euro::rubleTOcur(double rub_num) { return rub_num * this->ruble_euro_ratio; }
double euro::curTOruble(double cur_num) { return cur_num / this->ruble_euro_ratio; }
double euro::ratio() { return this->ruble_euro_ratio; }