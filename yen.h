#pragma once
#include "ruble.h"

class yen : public ruble {
	double ruble_nena_ratio;
public:
	yen();
	double ratio();
	double rubleTOcur(double) override;
	double curTOruble(double) override;
};

