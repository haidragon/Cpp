// 04.特殊运算符.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
using namespace std;
class CMyStr {
public:
	CMyStr(const char* sz) {
		//m_p = new char[strlen(sz) + 1]{};
		//strcpy_s(m_p, strlen(sz) + 1, sz);
		m_p = _strdup(sz);
	}
	CMyStr(const CMyStr& obj) {
		m_p = _strdup(obj.m_p);
	}
	~CMyStr() {
		if (m_p) {
			delete[] m_p;
			m_p = nullptr;
		}
	}
	CMyStr& operator=(const CMyStr& obj) {
		if (m_p) {
			delete[] m_p;
			m_p = nullptr;
		}
		m_p = _strdup(obj.m_p);
		return *this;
	}
	//CMyStr& operator+= (const char* sz) {
	//	int nLen = strlen(m_p) + strlen(sz) + 1;
	//	char *temp = new char[nLen] {};
	//	strcpy_s(temp, strlen(m_p) + 1, m_p);
	//	strcat_s(temp, nLen,sz);
	//	delete[] m_p;
	//	m_p = temp;
	//	return *this;
	//}
	CMyStr& operator+= (const CMyStr &obj) {
		int nLen = strlen(m_p) + strlen(obj.m_p) + 1;
		char *temp = new char[nLen] {};
		strcpy_s(temp, strlen(m_p) + 1, m_p);
		strcat_s(temp, nLen, obj.m_p);
		delete[] m_p;
		m_p = temp;
		return *this;
	}
	friend CMyStr operator+ (const CMyStr &obj1,const CMyStr &obj2) {
		int nLen = strlen(obj1.m_p) + strlen(obj2.m_p) + 1;
		char *temp = new char[nLen] {};
		strcpy_s(temp, strlen(obj1.m_p) + 1, obj1.m_p);
		strcat_s(temp, nLen, obj2.m_p);
		CMyStr objTemp(temp);
		delete[] temp;
		return objTemp;
	}
	friend ostream& operator<<(ostream &out,CMyStr& obj) {
		out << obj.m_p;
		return out;
	}

	char *m_p;
};

class CTest {
public:
	CTest(int a) {
		m_nNum = a;
	}
	int m_nNum;
};

int main() {
	cout << 1 << 'a' << "123";
	CTest obj = 12;// CTest obj(12);
	obj = 100;// obj = CTest(100);

	char sz[] = { "123" };
	char sz2[] = { "456" };
	//CMyStr obj(sz);
	//CMyStr objA = obj;
	//CMyStr objB(sz2);
	//objB = obj;
	CMyStr test = sz;// CMyStr test(sz);
	CMyStr test2 = sz2;
	test = sz2;// test = CMystr(sz2);
	test += sz2;
	test += test2;
	test = test2 + "123";
	test = "1243" + test2;
	cout << test<<test2;
	//test2<<(test << cout);
	return 0;
}

