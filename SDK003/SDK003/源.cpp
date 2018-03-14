#include <windows.h>
#include "resource.h"
#include <commctrl.h>

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
		SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETEXTENDEDLISTVIEWSTYLE,
			0,
			LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		// 添加列
		const TCHAR *pCol[] = { L"第1列" ,L"第2列",L"第3列" };
		for (size_t i = 0; i < 3; i++)
		{
			LVCOLUMN lvc = {};
			lvc.cx = 80;
			lvc.pszText = (WCHAR*)pCol[i];
			lvc.cchTextMax = 3;
			lvc.mask = LVCF_TEXT | LVCF_WIDTH;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTCOLUMN,i, (LPARAM)&lvc);
		}
		// 添加行信息 行标题  及内容
		for (size_t i = 0; i < 20; i++)
		{
			LVITEM lvi = {};
			lvi.pszText = (WCHAR*)L"123";
			lvi.cchTextMax = 3;
			lvi.iItem = i;
			lvi.iSubItem = 0;
			lvi.mask = LVIF_TEXT;
			// 标题
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTITEM, 0, (LPARAM)&lvi);
			// 内容
			//lvi.pszText = (WCHAR*)L"123";
			lvi.iSubItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETITEM, 0, (LPARAM)&lvi);
			lvi.iSubItem = 2;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETITEM, 0, (LPARAM)&lvi);
		}
		break;
	}
	case WM_COMMAND:
	{
		MessageBox(0, 0, 0, 0);
		if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
		{
			SetDlgItemText(hwndDlg, IDC_EDIT1, L"123");
			//GetModuleHandle(0);
		}
		break;
	}
	case WM_NOTIFY: {
		NMHDR* pNm = (NMHDR*)lParam;
		// 是不是list控件的单击消息
		if (pNm->code == NM_CLICK && pNm->idFrom == IDC_LIST1)
		{
			TCHAR text[10] = {};
			LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
			LVITEM lvi = {};
			lvi.iItem = lpnmitem->iItem;
			lvi.iSubItem = lpnmitem->iSubItem;
			lvi.pszText = text;
			lvi.cchTextMax = 10;
			lvi.mask = LVIF_TEXT;
			SendMessage(pNm->hwndFrom, LVM_GETITEM, 0, (LPARAM)&lvi);
			//SetDlgItemText(hwndDlg, IDC_EDIT1, text);
			MessageBox(hwndDlg, text, 0, MB_OK);
		}
		break;
	}
	case WM_CLOSE: {
		EndDialog(hwndDlg, 0);
		break;
	}
	default:
		break;
	}
	return 0;
}

