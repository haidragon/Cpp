// 03.纯虚函数和抽象类.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class A {
public:
	virtual void Fun1() = 0;
};
class A1 :public A {
public:
	// 派生类可以不实现纯虚函数
	// 如果不实现，该类也是抽象类
	// 不能实例化对象
	void Fun2() {
		printf("A1\n");
	}
};
int main()
{
	A obj;// 抽象类不能实例化对象
	A1 obj1;
    return 0;
}

