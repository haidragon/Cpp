
// MFCApplication2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include<TlHelp32.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, cclistctrl);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFCApplication2Dlg::OnNMClickList1)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	MessageBox(L"点击进程号列出当前进程的所有模块!!!!!");


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	EnumProcess();





	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
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
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CMFCApplication2Dlg::EnumProcess() {
	// 1. 先创建快照
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("快照error!\n");
		return false;
	}
	// 2. 开始遍历进程
	PROCESSENTRY32W psi = { sizeof(PROCESSENTRY32W) };
	BOOL bRet = Process32FirstW(hTool32, &psi);
	if (!bRet)
	{
		//printf("Process32FirstW error!\n");
		return false;
	}
	//printf("PID    EXE:\n");
	int i = 0;
	cclistctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	cclistctrl.GetClientRect(rc);
	nwidth = rc.Width();
	cclistctrl.InsertColumn(0, L"名称", 0, nwidth / 6);
	cclistctrl.InsertColumn(1, L"dwSize", 1, nwidth / 8);
	cclistctrl.InsertColumn(2, L"cntUsage", 2, nwidth / 8);
	cclistctrl.InsertColumn(3, L"PID", 3, nwidth / 8);
	cclistctrl.InsertColumn(4, L"th32DefaultHeapID", 4, nwidth / 8);
	cclistctrl.InsertColumn(5, L"th32ModuleID", 5, nwidth / 8);
	cclistctrl.InsertColumn(6, L"cntThreads", 6, nwidth / 8);
	cclistctrl.InsertColumn(7, L"th32ParentProcessID", 7, nwidth / 8);
	cclistctrl.InsertColumn(8, L"pcPriClassBase", 8, nwidth / 8);
	cclistctrl.InsertColumn(9, L"dwFlags", 9, nwidth / 8);


	do
	{


		//typedef struct tagPROCESSENTRY32 {
		//	DWORD     dwSize;
		//	DWORD     cntUsage;
		//	DWORD     th32ProcessID;
		//	ULONG_PTR th32DefaultHeapID;
		//	DWORD     th32ModuleID;
		//	DWORD     cntThreads;
		//	DWORD     th32ParentProcessID;
		//	LONG      pcPriClassBase;
		//	DWORD     dwFlags;
		//	TCHAR     szExeFile[MAX_PATH];
		//} PROCESSENTRY32, *PPROCESSENTRY32;
		//printf("%4d   %S\n", psi.th32ProcessID, psi.szExeFile);
		//	TCHAR     szExeFile[MAX_PATH];
		cclistctrl.InsertItem(i, psi.szExeFile);
		//	DWORD     dwSize;
		CString strdwSize;
		strdwSize.Format(L"%4d", psi.dwSize);
		cclistctrl.SetItemText(i, 1, strdwSize);
		//	DWORD     cntUsage;
		CString strcntUsage;
		strcntUsage.Format(L"%4d", psi.cntUsage);
		cclistctrl.SetItemText(i, 2, strcntUsage);
		//	DWORD     th32ProcessID;
		CString strcth32ProcessID;
		strcth32ProcessID.Format(L"%4d", psi.th32ProcessID);
		cclistctrl.SetItemText(i, 3, strcth32ProcessID);
		//	ULONG_PTR th32DefaultHeapID;
		CString strcth32DefaultHeapID;
		strcth32DefaultHeapID.Format(L"%4d", psi.th32DefaultHeapID);
		cclistctrl.SetItemText(i, 4, strcth32DefaultHeapID);
		//	ULONG_PTR th32ModuleID;
		CString strth32ModuleID;
		strth32ModuleID.Format(L"%4d", psi.th32ModuleID);
		cclistctrl.SetItemText(i, 5, strth32ModuleID);
		//	DWORD     cntThreads;
		CString cntThreads;
		cntThreads.Format(L"%4d", psi.cntThreads);
		cclistctrl.SetItemText(i, 6, cntThreads);
		//	DWORD     th32ParentProcessID;
		CString th32ParentProcessID;
		th32ParentProcessID.Format(L"%4d", psi.th32ParentProcessID);
		cclistctrl.SetItemText(i, 7, th32ParentProcessID);
		//	LONG      pcPriClassBase;
		CString pcPriClassBase;
		pcPriClassBase.Format(L"%4d", psi.pcPriClassBase);
		cclistctrl.SetItemText(i, 8, pcPriClassBase);
		//	DWORD     dwFlags;
		CString strcdwFlags;
		strcdwFlags.Format(L"%4d", psi.dwFlags);
		cclistctrl.SetItemText(i, 9, strcdwFlags);

		++i;
	} while (Process32NextW(hTool32, &psi));
	return true;
}

void CMFCApplication2Dlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int ccol = pNMItemActivate->iSubItem;
	int crow = pNMItemActivate->iItem;
	if (ccol == 3) {
		CString str = cclistctrl.GetItemText(crow, ccol);
		this->ShowWindow(SW_HIDE);
		//modo::pid = _ttoi(str);
	    pid = _ttoi(str);
		ccmymodo1  = new ccmymodo();
		ccmymodo1->DoModal();
		delete ccmymodo1;
		ccmymodo1 = nullptr;

		//MessageBox(str);
		this->ShowWindow(SW_SHOW);
	}

	*pResult = 0;
}
