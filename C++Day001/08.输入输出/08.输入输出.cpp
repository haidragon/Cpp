// 08.输入输出.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//cout << 1 << 'a' << 1.2;
	cout << hex<<setw(10) <<setfill('*')<< 12345;
    return 0;
}

