#include "dollar.h"
#include <iostream>

dollar::dollar() {
	std::cout << "¬ведите отношение рубл€ к доллару: ";
	std::cin >> this->ruble_dollar_ratio;
}
double dollar::rubleTOcur(double rub_num) { return rub_num * this->ruble_dollar_ratio; }
double dollar::curTOruble(double cur_num) { return cur_num / this->ruble_dollar_ratio; }
double dollar::ratio() { return this->ruble_dollar_ratio; }
