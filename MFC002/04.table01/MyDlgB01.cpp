// MyDlgB01.cpp : 实现文件
//

#include "stdafx.h"
#include "04.table01.h"
#include "MyDlgB01.h"
#include "afxdialogex.h"


// CMyDlgB01 对话框

IMPLEMENT_DYNAMIC(CMyDlgB01, CDialogEx)

CMyDlgB01::CMyDlgB01(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CMyDlgB01::~CMyDlgB01()
{
}

void CMyDlgB01::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgB01, CDialogEx)
END_MESSAGE_MAP()


// CMyDlgB01 消息处理程序
