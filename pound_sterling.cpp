#include "pound_sterling.h"
#include <iostream>

pound_sterling::pound_sterling() {
	std::cout << "Введите отношение рубля к фунту стерлингов: ";
	std::cin >> this->ruble_pound_ratio;
}
double pound_sterling::rubleTOcur(double rub_num) { return rub_num * this->ruble_pound_ratio; }
double pound_sterling::curTOruble(double cur_num) { return cur_num / this->ruble_pound_ratio; }
double pound_sterling::ratio() { return this->ruble_pound_ratio; }