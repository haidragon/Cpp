// 02.类模板.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template<class T>
class CVector {
public:
	CVector() {
		m_nCount = 0;
		m_p = new T[10]{};
	}
	void Push(T nEle);
	void Pop() {
		m_nCount--;
	}
	int m_nCount;
	T *m_p;
};
// 模板类成员函数的类外实现
template<class T>
void CVector<T>::Push(T nEle) {
	m_p[m_nCount++] = nEle;
}

int main() {
	CVector<int> obj;
	return 0;
}

