// 05.自定义异常类.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CMyError {
public:
	CMyError() {}
	void Fun() {
		printf("pop错误，CVector已空\n");
	}

};

template<class T>
class CVector {
public:
	CVector() {
		m_nCount = 0;
		m_p = new T[10]{};
	}
	void Push(T nEle);
	void Pop() {
		if (m_nCount == 0)
		{
			throw CMyError();
		}
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

int main()
{
	CVector<int> obj;
	for (int i = 0; i < 10; i++) {
		obj.Push(i);
	}
	for (int i=0;i<100;i++)
	{
		try
		{
			obj.Pop();// 触发异常后面的代码不会被执行
			printf("%d\n", i);
		}
		catch (CMyError& e)
		{
			e.Fun();
			break;
		}
	}
    return 0;
}

