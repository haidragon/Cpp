// MyDlgA01.cpp : 实现文件
//

#include "stdafx.h"
#include "04.table01.h"
#include "MyDlgA01.h"
#include "afxdialogex.h"


// CMyDlgA01 对话框

IMPLEMENT_DYNAMIC(CMyDlgA01, CDialogEx)

CMyDlgA01::CMyDlgA01(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlgA01::~CMyDlgA01()
{
}

void CMyDlgA01::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgA01, CDialogEx)
END_MESSAGE_MAP()


// CMyDlgA01 消息处理程序
