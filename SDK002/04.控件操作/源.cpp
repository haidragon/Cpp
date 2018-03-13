#include <windows.h>
#include "resource.h"
#include <commctrl.h>
//#pragma comment(lib,"Comctl32.lib")
// 2013 需要 InitCommonControls();
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
	case WM_COMMAND: {
		WORD wId = LOWORD(wParam);
		WORD wCode = HIWORD(wParam);
		HANDLE hChild = (HANDLE)lParam;
		if (wId == IDC_BUTTON1 && wCode == BN_CLICKED)
		{
			// 操作窗口显示文本
			//SetWindowText(GetDlgItem(hwndDlg, IDC_EDIT1), L"1234");
			// 作为子控件显示文本函数
			//SetDlgItemText(hwndDlg, IDC_EDIT1, L"asdbvfvd");
			// 获取单选框的状态
			for (int i = 0; i < 3; i++)
			{
				int nRet = SendMessage(GetDlgItem(hwndDlg, IDC_RADIO1 + i), BM_GETCHECK, 0, 0);
				if (nRet == BST_CHECKED)
				{
					TCHAR tSex[3] = {};
					GetDlgItemText(hwndDlg, IDC_RADIO1 + i, tSex, 3);
					SetDlgItemText(hwndDlg, IDC_EDIT1, tSex);
					break;
					//MessageBox(0, 0, 0, 0);
				}
			}
			// 获取复选框的状态
			int nRet = SendDlgItemMessage(hwndDlg, IDC_CHECK1, BM_GETSTATE, 0, 0);
			const TCHAR *p[3] = { L"晴天:\r\n否" ,L"晴天:\r\n是" ,L"晴天:\r\n未知" };

			SetDlgItemText(hwndDlg, IDC_EDIT1, p[nRet]);
		}
		else if (wId == IDC_BUTTON2 && wCode == BN_CLICKED)
		{// 切换图片
			// 1. 静态添加图片：添加picture control
			// 设置图片属性 type为bitmap
			// 添加BMP图片资源
			// 选择picture control的image属性为添加的图片资源ID
			// 2. 动态添加图片
			/*static BOOL b = FALSE;
			HBITMAP hBmp = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(b?IDB_BITMAP2: IDB_BITMAP1));
			b = !b;
			SendDlgItemMessage(hwndDlg, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);*/
			SetTimer(hwndDlg,
				123,// 定时器ID
				300,//多少毫秒触发一次
				NULL);
		}
		else if (wId == IDC_BUTTON3 && wCode == BN_CLICKED)
		{
			//ListView_SetExtendedListViewStyleEx()
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETEXTENDEDLISTVIEWSTYLE,
				0, LVS_EX_CHECKBOXES|LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			// 1. 添加列标题
			//ListView_InsertColumn()
			LVCOLUMN lvc = {};
			lvc.pszText = (WCHAR*)L"第1列";
			lvc.cchTextMax = 3;
			lvc.cx = 80;
			lvc.mask = LVCF_TEXT| LVCF_WIDTH;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTCOLUMN, 0, (LPARAM)&lvc);
			lvc.pszText = (WCHAR*)L"第2列";
			lvc.cchTextMax = 3;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTCOLUMN, 1, (LPARAM)&lvc);
			// 2. 添加行标题
			LVITEM lvi = {};
			lvi.pszText = (WCHAR*)L"第1行";
			lvi.cchTextMax = 3;
			lvi.iItem = 0;// 第几行
			lvi.iSubItem = 0;//第几列
			lvi.mask = LVIF_TEXT;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTITEM,0, (LPARAM)&lvi);
			lvi.pszText = (WCHAR*)L"第2行";
			lvi.iItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTITEM, 0, (LPARAM)&lvi);
			// 3. 添加内容
			lvi.pszText = (WCHAR*)L"内容";
			lvi.iSubItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETITEMTEXT, 0, (LPARAM)&lvi);
			lvi.pszText = (WCHAR*)L"内容";
			lvi.iItem = 1;
			lvi.iSubItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETITEM, 0, (LPARAM)&lvi);

		}
		break;
	}
	case WM_TIMER: {
		if (wParam == 123)
		{
			static BOOL b = FALSE;
			HBITMAP hBmp = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(b ? IDB_BITMAP2 : IDB_BITMAP1));
			b = !b;
			
			SendDlgItemMessage(hwndDlg, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);
		}
		break;
	}
	case WM_HSCROLL: {
		if (LOWORD(wParam) == SB_THUMBTRACK)
		{
			WORD wPos = HIWORD(wParam);
			SendDlgItemMessage(hwndDlg, IDC_PROGRESS1, PBM_SETPOS, wPos, 0);
		}
		break;
	}
	case WM_CLOSE:
	{
		EndDialog(hwndDlg, 0);
		break;
	}
	default:
		break;
	}
	return 0;
}