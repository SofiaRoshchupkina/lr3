#include "yen.h"
#include <iostream>

yen::yen() {
	std::cout << "¬ведите отношение рубл€ к €понскойф иене: ";
	std::cin >> this->ruble_nena_ratio;
}
double yen::rubleTOcur(double rub_num) { return rub_num * this->ruble_nena_ratio; }
double yen::curTOruble(double cur_num) { return cur_num / this->ruble_nena_ratio; }
double yen::ratio() { return this->ruble_nena_ratio; }