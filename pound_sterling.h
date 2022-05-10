#pragma once
#include "ruble.h"
class pound_sterling : public ruble {
	double ruble_pound_ratio;
public:
	pound_sterling();
	double ratio();
	double rubleTOcur(double) override;
	double curTOruble(double) override;
};