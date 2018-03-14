#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}

INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_INITDIALOG: {
		//SetClassLong/SetWindowLong
		HICON hIcon = LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(IDI_ICON1));
		HICON hOldIcon = (HICON)SetClassLong(hwndDlg, GCL_HICON, (LONG)hIcon);
		HCURSOR hCurson = LoadCursor(GetModuleHandle(0), MAKEINTRESOURCE(IDC_CURSOR1));
		SetClassLong(hwndDlg, GCL_HCURSOR, (LONG)hCurson);
		break;
	}
	case WM_COMMAND:
	{
		//菜单
		if (HIWORD(wParam) == 0)
		{
			// 打开菜单的消息响应
			if (LOWORD(wParam) == ID_40001)
			{
				MessageBox(hwndDlg, L"打开菜单！\n", 0, MB_OK);
				TCHAR szDir[MAX_PATH] = { 0 };
				//打开文件
				OPENFILENAME ofn = { sizeof(OPENFILENAME) };
				TCHAR szFileName[MAX_PATH] = { 0 };
				ofn.Flags = OFN_HIDEREADONLY;
				ofn.hwndOwner = NULL;
				TCHAR szFilter[] = TEXT("EXE Files(*.exe)\0*.exe\0")TEXT("DLL Files(*.dll)\0*.dll\0")TEXT("All Files(*.*)\0*.*\0\0");
				ofn.lpstrFilter = szFilter;
				ofn.nMaxFile = MAX_PATH;
				ofn.nMaxFileTitle = MAX_PATH;
				//用来保存文件路径
				ofn.lpstrFile = szDir;
				ofn.lpstrFileTitle = szFileName;
				ofn.lpstrInitialDir = szDir;
				GetOpenFileName(&ofn);
			}
		}
		break;
	}
	case WM_NOTIFY: {
		break;
	}
	case WM_CLOSE: {
		EndDialog(hwndDlg, 0);
		break;
	}
	case WM_RBUTTONUP: {
		HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU2));
		HMENU hSub = GetSubMenu(hMenu, 0);
		// 客户区坐标转屏幕坐标
		POINT pt = {LOWORD(lParam),HIWORD(lParam)};
		ClientToScreen(hwndDlg, &pt);
		TrackPopupMenu(hSub, TPM_BOTTOMALIGN | TPM_LEFTALIGN, pt.x, pt.y, NULL, hwndDlg, NULL);
		break;
	}
	default:
		break;
	}
	return 0;
}

