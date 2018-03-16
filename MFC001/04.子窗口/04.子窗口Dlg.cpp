
// 04.子窗口Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "04.子窗口.h"
#include "04.子窗口Dlg.h"
#include "afxdialogex.h"
#include "MyDlgNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04子窗口Dlg 对话框



CMy04子窗口Dlg::CMy04子窗口Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY04_DIALOG, pParent)
	, m_reg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy04子窗口Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_reg);
}

BEGIN_MESSAGE_MAP(CMy04子窗口Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy04子窗口Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy04子窗口Dlg 消息处理程序

BOOL CMy04子窗口Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy04子窗口Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy04子窗口Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy04子窗口Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_reg == L"12345")
	{
		// 登录成功，隐藏当前窗口，显示登录后的主界面
		//ShowWindow(SW_HIDE);
		//CMyDlgNew p;
		//p.DoModal();
		//ShowWindow(SW_SHOW);
		CMyDlgNew *p = new CMyDlgNew;
		p->Create(IDD_DIALOG1, this);
		p->ShowWindow(SW_SHOW);
	}
}
