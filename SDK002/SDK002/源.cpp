#include <windows.h>

// 名字随便起
LRESULT CALLBACK WindowProc(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// 先注册窗口类
	WNDCLASS wcs = {};
	wcs.lpszClassName = L"24期";
	wcs.lpfnWndProc = WindowProc;
	wcs.hbrBackground = (HBRUSH)(COLOR_CAPTIONTEXT + 1);
	RegisterClass(&wcs);
	HWND hWnd = CreateWindow(L"24期", L"第2天", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0, 500, 500,
		NULL, NULL, hInstance, NULL);
	// 三种风格  WS_OVERLAPPEDWINDOW  WS_POPUPWINDOW  WS_CHILDWINDOW
	CreateWindow(L"BUTTON", L"我是按钮", WS_CHILD | WS_VISIBLE,
		10, 10,// 在父窗口的客户区的位置，
		100, 50,// 宽 高
		hWnd,// 父窗口
		(HMENU)0x1001,// 如果是顶层窗口 就是菜单句柄 子窗口就是本身的ID
		hInstance, NULL);
	ShowWindow(hWnd, SW_SHOW);
	MSG msg = {};
	while (GetMessage(&msg,0,0,0))
	{
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WindowProc(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_CREATE: {
		DWORD dwStyle = ES_LEFT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
		DWORD dwExStyle = WS_EX_CLIENTEDGE | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
		
		HWND hWnd = ::CreateWindowEx(
			dwExStyle, //dwExStyle 扩展样式
			L"Edit", //lpClassName 窗口类名
			L"text", //lpWindowName 窗口标题
			dwStyle, //dwStyle 窗口样式
			20, //x 左边位置
			20, //y 顶边位置
			200, //nWidth 宽度
			20, //nHeight 高度
			hwnd, //hWndParent 父窗口句柄
			(HMENU)0x1002, //ID
			GetModuleHandle(0), //hInstance 应用程序句柄
			NULL //lpParam 附加参数
			);
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		break;
	}
	// 返回默认的窗口处理过程
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}