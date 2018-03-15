#include<windows.h>
#include <stdio.h>
#include"resource.h"

HWND hCalcEdit;
HWND hcalc;
LRESULT  CALLBACK NewDialogProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam);
BOOL CALLBACK EnumChildProc(
	_In_  HWND hwnd,
	_In_  LPARAM lParam
)
{
	if (GetDlgCtrlID(hwnd) == lParam)
	{
		hCalcEdit = hwnd;
		return false;
	}
	return true;
}

int TosendMessage(HWND hDialog, HWND hCalc, int nId) {

	WPARAM	wParam = MAKEWPARAM(nId, BN_CLICKED);
	SendMessage(hCalc, WM_COMMAND, wParam, 0);

	TCHAR	szText[MAX_PATH] = { 0 };
	GetWindowText(hCalcEdit, szText, MAX_PATH);		    	//获得计算器的值
	SetDlgItemText(hDialog, 1001, szText);					//给自己的id为1010的控件设置值
	return 0;
}

DLGPROC g_oldProc=NULL;

INT_PTR CALLBACK DialogProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{

	switch (uMsg)
	{
	case WM_CLOSE:
	{
		EndDialog(hwndDlg, 0);
		return 0;
	}break;
	case WM_COMMAND:
	{
		int wCid = LOWORD(wParam);
		int wCode = HIWORD(wParam);
		switch (wCid)
		{
		case IDC_BUTTON1:
		{
			TosendMessage(hwndDlg, hcalc, 0x84);
		}break;
		case IDC_BUTTON2:
		{
			TosendMessage(hwndDlg, hcalc, 0x85);
		}break;
		case IDC_BUTTON3:
		{
			TosendMessage(hwndDlg, hcalc, 0x86);
		}break;
		case IDC_BUTTON4:
		{
			TosendMessage(hwndDlg, hcalc, 0x87);
		}break;
		case IDC_BUTTON5:
		{
			char buf[20];
			sprintf_s(buf,20,"%x", lParam);
			MessageBoxA(0,buf,0,0);
			TosendMessage(hwndDlg, hcalc, 0x88);
		}break;
		case IDC_BUTTON6:
		{
			//GetDlgItem(hwndDlg,IDC_BUTTON5);
			g_oldProc=(DLGPROC)SetWindowLong(GetDlgItem(hwndDlg, IDC_BUTTON5), GWL_WNDPROC, (LONG)NewDialogProc);
			MessageBox(0,L"更改数字5 的回调函数",0,0);
		}break;

		default:
			break;
		}

	}break;

	default:
		break;
	}
	return  0; 
}



int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow
)
{

	hcalc = FindWindow(0, L"计算器");
	EnumChildWindows(hcalc, EnumChildProc, 0x96);//获取计算器的Edit 数据
//	HMODULE
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogProc);

	return 0;
}

LRESULT  CALLBACK NewDialogProc(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	{
		MessageBox(0,L"被单击",0,0);
		return 0;
	}break;
	default:
		break;
	}
	return g_oldProc(hwndDlg, uMsg, wParam, lParam);
}

