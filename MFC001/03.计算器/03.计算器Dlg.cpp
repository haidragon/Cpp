
// 03.计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "03.计算器.h"
#include "03.计算器Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03计算器Dlg 对话框



CMy03计算器Dlg::CMy03计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY03_DIALOG, pParent)
	, m_EditResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy03计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EditResult);
}

BEGIN_MESSAGE_MAP(CMy03计算器Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BUTTON1, IDC_BUTTON0, &CMy03计算器Dlg::OnCmdRange)
	//ON_BN_CLICKED(IDC_BUTTON0, &CMy03计算器Dlg::OnBnClickedButton0)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMy03计算器Dlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CMy03计算器Dlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON3, &CMy03计算器Dlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON4, &CMy03计算器Dlg::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_BUTTON5, &CMy03计算器Dlg::OnBnClickedButton5)
	//ON_BN_CLICKED(IDC_BUTTON6, &CMy03计算器Dlg::OnBnClickedButton6)
	//ON_BN_CLICKED(IDC_BUTTON7, &CMy03计算器Dlg::OnBnClickedButton7)
	//ON_BN_CLICKED(IDC_BUTTON8, &CMy03计算器Dlg::OnBnClickedButton8)
	//ON_BN_CLICKED(IDC_BUTTON9, &CMy03计算器Dlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CMy03计算器Dlg 消息处理程序

BOOL CMy03计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_EditResult = L"123+456";
	//DWORD dwOp1, dwOp2;
	//WCHAR wOpChar;
	//swscanf_s(m_EditResult.GetBuffer(), L"%d%c%d", &dwOp1, &wOpChar,1, &dwOp2);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy03计算器Dlg::OnPaint()
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
HCURSOR CMy03计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy03计算器Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"3";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"4";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"2";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"6";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"5";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"7";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"9";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnCmdRange(UINT uID)
{
	// 1 1001
	// 2 1002
	// 9 1009
	// 0 1010
	UpdateData(TRUE);
	if (uID == IDC_BUTTON0)
	{
		uID = IDC_BUTTON1 - 1;
	}
	if (m_EditResult[0] == L'0')
	{
		m_EditResult.Format(L"%d", uID - IDC_BUTTON1 + 1);
	}
	else
	{
		m_EditResult.Format(L"%s%d", m_EditResult, uID - IDC_BUTTON1 + 1);
	}
	//m_EditResult += L"8";
	UpdateData(FALSE);
}

void CMy03计算器Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"8";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_EditResult += L"0";
	UpdateData(FALSE);
}


void CMy03计算器Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_EditResult[0] == L'0')
	{
		m_EditResult = L"1";
	}
	else
	{
		m_EditResult += L"1";
	}
	UpdateData(FALSE);
}
