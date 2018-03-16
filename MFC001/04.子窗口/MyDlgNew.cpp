// MyDlgNew.cpp : 实现文件
//

#include "stdafx.h"
#include "04.子窗口.h"
#include "MyDlgNew.h"
#include "afxdialogex.h"


// CMyDlgNew 对话框

IMPLEMENT_DYNAMIC(CMyDlgNew, CDialogEx)

CMyDlgNew::CMyDlgNew(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlgNew::~CMyDlgNew()
{
}

void CMyDlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgNew, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlgNew::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyDlgNew 消息处理程序


void CMyDlgNew::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//delete this;
	CDialogEx::OnClose();
}


void CMyDlgNew::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//HWND hParent = GetParent()->m_hWnd;
	this->m_hWnd;
	MessageBox(0);
}
