// MyTab.cpp : 实现文件
//

#include "stdafx.h"
#include "02.Table.h"
#include "MyTab.h"
#include "MyDlgA.h"
#include "MyDlgB.h"
#include "MyDlgC.h"


// CMyTab

IMPLEMENT_DYNAMIC(CMyTab, CTabCtrl)

CMyTab::CMyTab()
{

}

CMyTab::~CMyTab()
{
}


BEGIN_MESSAGE_MAP(CMyTab, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTab::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTab 消息处理程序




void CMyTab::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	InsertItem(0, L"A");
	InsertItem(1, L"B");
	InsertItem(2, L"C");
	m_child[0] = new CMyDlgA;
	m_child[0]->Create(IDD_DIALOG1,this);
	m_child[1] = new CMyDlgB;
	m_child[1]->Create(IDD_DIALOG2,this);
	m_child[2] = new CMyDlgC;
	m_child[2]->Create(IDD_DIALOG3,this);
	// 把子窗口移动到和客户区一样大
	CRect rt = {};
	GetClientRect(&rt);
	rt.DeflateRect(0, 25, 0, 0);
	m_child[0]->MoveWindow(&rt);
	m_child[0]->ShowWindow(SW_SHOW);
	CTabCtrl::PreSubclassWindow();
}


void CMyTab::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int nSel = GetCurSel();
	// 隐藏之前的窗口，只显示现在点击的这个标签所在的窗口
	for (int i=0;i<3;i++)
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
