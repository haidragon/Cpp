// MyDlgA.cpp : 实现文件
//

#include "stdafx.h"
#include "02.Table.h"
#include "MyDlgA.h"
#include "afxdialogex.h"


// CMyDlgA 对话框

IMPLEMENT_DYNAMIC(CMyDlgA, CDialogEx)

CMyDlgA::CMyDlgA(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlgA::~CMyDlgA()
{
}

void CMyDlgA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgA, CDialogEx)
END_MESSAGE_MAP()


// CMyDlgA 消息处理程序
