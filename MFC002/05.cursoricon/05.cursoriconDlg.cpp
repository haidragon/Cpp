
// 05.cursoriconDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "05.cursoricon.h"
#include "05.cursoriconDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy05cursoriconDlg 对话框



CMy05cursoriconDlg::CMy05cursoriconDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY05CURSORICON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy05cursoriconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy05cursoriconDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy05cursoriconDlg::OnBnClickedButton1)
	ON_COMMAND(ID_BUTTON32771, &CMy05cursoriconDlg::On工具栏1号)
	ON_COMMAND(0x5001, &CMy05cursoriconDlg::On图片栏1号)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32776, &CMy05cursoriconDlg::On哈哈)
	ON_COMMAND(0x7001, &CMy05cursoriconDlg::On动态)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CMy05cursoriconDlg 消息处理程序

BOOL CMy05cursoriconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 工具栏
	m_toolbar1.Create(this);
	m_toolbar1.LoadToolBar(IDR_TOOLBAR1);
	m_toolbar2.Create(this);
	m_toolbar2.LoadBitmapW(IDB_BITMAP1);
	UINT uId[] = {0x5001,0x5002,0x5003};
	m_toolbar2.SetButtons(uId,3);
	// 状态栏
	m_status.Create(this);
	// 设置状态栏为几栏
	UINT uId2[] = { 0x6001,0x6002,0x6003 };
	m_status.SetIndicators(uId2, 3);
	// 设置状态栏的样式 和文本
	m_status.SetPaneInfo(0, 0x6001, SBPS_NORMAL, 80);
	m_status.SetPaneInfo(1, 0x6002, SBPS_NORMAL, 80);
	m_status.SetPaneInfo(2, 0x6003, SBPS_NORMAL, 80);
	m_status.SetPaneText(0, L"我是一号状态栏");
	m_status.SetPaneText(1, L"我是二号状态栏");
	m_status.SetPaneText(2, L"我是三号状态栏");

	// 显示工具栏状态栏等
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy05cursoriconDlg::OnPaint()
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
HCURSOR CMy05cursoriconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 改变图标
void CMy05cursoriconDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HICON hIcon = AfxGetApp()->LoadIconW(IDI_ICON1);
	SetIcon(hIcon,FALSE);
}


void CMy05cursoriconDlg::On工具栏1号()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"我是工具栏1号");
}

void CMy05cursoriconDlg::On图片栏1号()
{
	MessageBox(L"我是图片栏1号");
}


void CMy05cursoriconDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetCursorPos(&point);
	::ScreenToClient(m_hWnd,&point);
	CString str;
	str.Format(L"x:%d,y:%d", point.x, point.y);
	m_status.SetPaneText(0, str.GetBuffer());
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMy05cursoriconDlg::On哈哈()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"我是哈哈");
}


void CMy05cursoriconDlg::On动态()
{
	MessageBox(L"我是动态");
}

void CMy05cursoriconDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPoint pt;
	GetCursorPos(&pt);
	CMenu mu;
	mu.LoadMenuW(IDR_MENU2);
	CMenu *pSub = mu.GetSubMenu(0);
	// 给pSub号加个菜单项
	pSub->AppendMenuW(MF_STRING, 0x7001, L"我是动态弹出2号");
	TrackPopupMenu(pSub->m_hMenu, TPM_LEFTALIGN, pt.x, pt.y,
		NULL, m_hWnd, NULL);
	CDialogEx::OnRButtonUp(nFlags, point);
}
