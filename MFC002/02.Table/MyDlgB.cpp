// MyDlgB.cpp : 实现文件
//

#include "stdafx.h"
#include "02.Table.h"
#include "MyDlgB.h"
#include "afxdialogex.h"


// CMyDlgB 对话框

IMPLEMENT_DYNAMIC(CMyDlgB, CDialogEx)

CMyDlgB::CMyDlgB(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CMyDlgB::~CMyDlgB()
{
}

void CMyDlgB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgB, CDialogEx)
END_MESSAGE_MAP()


// CMyDlgB 消息处理程序
