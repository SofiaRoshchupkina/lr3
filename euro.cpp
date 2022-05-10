#include "euro.h"
#include <iostream>
euro::euro() {
	std::cout << "Курс на 10.05.2022:\n 1 руб. = 0.013 дол. = 0.014 ев. = 0.012 ф.с. = 1.86 я.е.\n\nВаш курс: \n";
	std::cout << "Введите отношение рубля к евро: ";
	std::cin >> this->ruble_euro_ratio;
}
double euro::rubleTOcur(double rub_num) { return rub_num * this->ruble_euro_ratio; }
double euro::curTOruble(double cur_num) { return cur_num / this->ruble_euro_ratio; }
double euro::ratio() { return this->ruble_euro_ratio; }