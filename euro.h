#pragma once
#include "ruble.h"
class euro : protected ruble {
	double ruble_euro_ratio; //����������� ����� � ���� //1rub = ruble_euro
public:
	euro();
	double ratio();
	double rubleTOcur(double) override;
	double curTOruble(double) override;
};

