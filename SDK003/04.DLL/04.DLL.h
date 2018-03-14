#pragma once
// 2. 两种导出方式   声明导出
extern "C" _declspec(dllexport) void FunTest();
// 模块定义文件导出
void Fun2();

// 3. dll分为静态库 和 动态库
// 导出函数的方式没区别
// 使用的时候有区别
// 因为静态库没有dll文件，无法显式调用，只能隐式调用
// 动态库的lib文件和静态库的lib文件：动态库的只是目录，静态库的是代码
// 使用的时候，动态库的代码跟着dll随exe调用
// 静态库使用的时候是把代码嵌入到exe文件中，不跟随lib