// MyTab01.cpp : 实现文件
//

#include "stdafx.h"
#include "04.table01.h"
#include "MyTab01.h"


// CMyTab01

IMPLEMENT_DYNAMIC(CMyTab01, CTabCtrl)

CMyTab01::CMyTab01()
{

}

CMyTab01::~CMyTab01()
{
}

// 标题  对话框  对话框ID
void CMyTab01::MyInsertItem(DWORD dwCount, ...)
{
	va_list va;
	va_start(va, dwCount);
	m_dwCount = dwCount;
	for (DWORD i = 0 ; i< dwCount;i++)
	{
		TCHAR* pHeader = va_arg(va, TCHAR*);
		CDialogEx*pWnd = va_arg(va, CDialogEx*);
		UINT uID = va_arg(va, UINT);
		InsertItem(i, pHeader);
		pWnd->Create(uID, this);
		m_child[i] = pWnd;
	}
	va_end(va);
	// 把子窗口移动到和客户区一样大
	CRect rt = {};
	GetClientRect(&rt);
	rt.DeflateRect(0, 25, 0, 0);
	m_child[0]->MoveWindow(&rt);
	m_child[0]->ShowWindow(SW_SHOW);
}

BEGIN_MESSAGE_MAP(CMyTab01, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTab01::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTab01 消息处理程序




void CMyTab01::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int nSel = GetCurSel();
	// 隐藏之前的窗口，只显示现在点击的这个标签所在的窗口
	for (int i = 0; i < m_dwCount; i++)
	{
		m_child[i]->ShowWindow(SW_HIDE);
	}
	// 把子窗口移动到和客户区一样大
	CRect rt = {};
	GetClientRect(&rt);
	rt.DeflateRect(0, 25, 0, 0);
	m_child[nSel]->MoveWindow(&rt);
	m_child[nSel]->ShowWindow(SW_SHOW);
}
