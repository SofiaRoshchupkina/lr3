#pragma once
#include "ruble.h"
class dollar : public ruble {
	double ruble_dollar_ratio;
public:
	dollar();
	double ratio();
	double rubleTOcur(double) override;
	double curTOruble(double) override;
};
