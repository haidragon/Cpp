// MyDlgC01.cpp : 实现文件
//

#include "stdafx.h"
#include "04.table01.h"
#include "MyDlgC01.h"
#include "afxdialogex.h"


// CMyDlgC01 对话框

IMPLEMENT_DYNAMIC(CMyDlgC01, CDialogEx)

CMyDlgC01::CMyDlgC01(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CMyDlgC01::~CMyDlgC01()
{
}

void CMyDlgC01::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgC01, CDialogEx)
END_MESSAGE_MAP()


// CMyDlgC01 消息处理程序
