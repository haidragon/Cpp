// 02.双目运算符重载.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

class CFood {
public:
	CFood() {
		Create();
	}
	void Create() {
		m_nValue = rand()%100;
	}
	int m_nValue;
};

class CTank {
public:
	CTank(int a) {
		m_nBlood = a;
	}
	int Crash(CTank &obj) {
		return this->m_nBlood -= obj.m_nBlood;
	}
	int operator-(CTank &obj) {
		return this->m_nBlood -= obj.m_nBlood;
	}
	CTank &operator+=(int nNum) {
		this->m_nBlood += nNum;
		return *this;
	}
	CTank &operator+=(CFood obj) {
		this->m_nBlood += obj.m_nValue;
		return *this;
	}
	int m_nBlood;
};

int main()
{
	CTank mine(100), enemy(50);
	mine.Crash(enemy);
	mine - enemy;
	mine.operator-(enemy);
	mine += 10;
	CFood food;
	mine += food;
    return 0;
}

