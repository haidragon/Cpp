// MyDlgC.cpp : 实现文件
//

#include "stdafx.h"
#include "02.Table.h"
#include "MyDlgC.h"
#include "afxdialogex.h"


// CMyDlgC 对话框

IMPLEMENT_DYNAMIC(CMyDlgC, CDialogEx)

CMyDlgC::CMyDlgC(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CMyDlgC::~CMyDlgC()
{
}

void CMyDlgC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgC, CDialogEx)
END_MESSAGE_MAP()


// CMyDlgC 消息处理程序
