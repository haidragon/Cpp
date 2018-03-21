
// 01.TCP_SER_MSGDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "01.TCP_SER_MSG.h"
#include "01.TCP_SER_MSGDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01TCP_SER_MSGDlg 对话框



CMy01TCP_SER_MSGDlg::CMy01TCP_SER_MSGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY01TCP_SER_MSG_DIALOG, pParent)
	, m_edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy01TCP_SER_MSGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
}
#define WM_MYSOCKET WM_USER+1
BEGIN_MESSAGE_MAP(CMy01TCP_SER_MSGDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy01TCP_SER_MSGDlg::OnBnClickedButton1)
	ON_MESSAGE(WM_MYSOCKET, &CMy01TCP_SER_MSGDlg::OnMysocket)
END_MESSAGE_MAP()


// CMy01TCP_SER_MSGDlg 消息处理程序

BOOL CMy01TCP_SER_MSGDlg::OnInitDialog()
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

void CMy01TCP_SER_MSGDlg::OnPaint()
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
HCURSOR CMy01TCP_SER_MSGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy01TCP_SER_MSGDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 启动服务器
	if (m_tcp.InitServer("127.0.0.1", 0x1234))
	{
		MessageBox(L"服务器启动成功！");
	}
	else
	{
		MessageBox(L"服务器启动失败！");
		return;
	}
	// 把所有的阻塞操作都交给窗口管理
	// 把m_socket的FD_ACCEPT | FD_CLOSE事件托管给窗口m_hWnd
	// 当需要m_socket响应ACCEPT或close时，窗口通过WM_MYSOCKET(自定义的)通知你
	// 我通过函数OnMysocket(自定义的)来处理该消息
	WSAAsyncSelect(m_tcp.m_socket, m_hWnd, WM_MYSOCKET, FD_ACCEPT | FD_CLOSE);
}


afx_msg LRESULT CMy01TCP_SER_MSGDlg::OnMysocket(WPARAM wParam, LPARAM lParam)
{
	// wparam : socket  托管时候的第1个参数
	// lparam: loword event 托管时候的第4个参数
	// lparam: hiword error code
	SOCKET s = wParam;
	WORD wEvent = WSAGETSELECTEVENT(lParam);
	WORD wErrorCode = WSAGETSELECTERROR(lParam);
	if (wErrorCode)
	{
		if (m_tcp.TcpClientExit(s))
		{
			UpdateData(TRUE);
			m_edit += L"客户端退出\r\n";
			UpdateData(FALSE);
		}
		return 0;
	}
	switch (wEvent)
	{
	case FD_ACCEPT:
	{
		// 接收客户端连接
		SOCKET s = m_tcp.TcpAccept();
		if (s == INVALID_SOCKET)
		{
			return 0;
		}
		// 把该客户端的网络事件托管给窗口
		WSAAsyncSelect(s, m_hWnd, WM_MYSOCKET, FD_READ | FD_CLOSE);
	}
	break;
	case FD_READ: {
		char buf[1024] = {};
		int nRet = m_tcp.TcpRecv(s, buf, 1024);
		if (nRet == SOCKET_ERROR) return 0;
		UpdateData(TRUE);
		m_edit += CString(buf);
		m_edit += L"\r\n";
		UpdateData(FALSE);
		break;
	}
	case FD_CLOSE:
	{
		if (m_tcp.TcpClientExit(s))
		{
			UpdateData(TRUE);
			m_edit += L"客户端退出\r\n";
			UpdateData(FALSE);
		}
		break;
	}
	default:
		break;
	}
	return 0;
}
