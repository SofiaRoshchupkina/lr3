#pragma once
class ruble { //абстрактный класс рубля
protected:
	virtual double rubleTOcur(double rub_num/*количество рублей*/) = 0; //перевод рублей в другую валюта
	virtual double curTOruble(double cur_num/*количество другой валюты*/) = 0; //перевод валюты в рубли
};
