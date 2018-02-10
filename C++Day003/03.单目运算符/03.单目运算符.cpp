// 03.单目运算符.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CTank {
public:
	CTank operator--(int) {
		CTank temp = *this;
		this->m_nBlood--;
		return temp;
	}
	CTank& operator--() {
		this->m_nBlood--;
		return *this;
	}
	CTank operator++(int) {
		CTank temp = *this;
		this->m_nBlood++;
		return temp;
	}
	CTank& operator++() {
		this->m_nBlood++;
		return *this;
	}
	int m_nBlood;
};

int main()
{
	int a = 10, b = 20;
	a = --b;
	CTank obj;
	obj--;
	--obj;
	obj++;
	++obj;
	obj.operator++(5);
	obj.operator++();
    return 0;
}

