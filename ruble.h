#pragma once
class ruble { //����������� ����� �����
protected:
	virtual double rubleTOcur(double rub_num/*���������� ������*/) = 0; //������� ������ � ������ ������
	virtual double curTOruble(double cur_num/*���������� ������ ������*/) = 0; //������� ������ � �����
};
