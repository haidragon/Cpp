
// MFC002Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC002.h"
#include "MFC002Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC002Dlg 对话框



CMFC002Dlg::CMFC002Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC002_DIALOG, pParent)
	, m_strShow(_T(""))
	, m_radioSex(0)
	, m_checkLove(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC002Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strShow);
	DDX_Radio(pDX, IDC_RADIO1, m_radioSex);
	DDX_Check(pDX, IDC_CHECK1, m_checkLove);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Control(pDX, IDC_BUTTON2, m_BtnAdd);
	DDX_Control(pDX, IDC_STATIC1, m_staticPic);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}

BEGIN_MESSAGE_MAP(CMFC002Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC002Dlg::OnBtn1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC002Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC002Dlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SLIDER1, &CMFC002Dlg::OnNMThemeChangedSlider1)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CMFC002Dlg::OnTRBNThumbPosChangingSlider1)
END_MESSAGE_MAP()


// CMFC002Dlg 消息处理程序

BOOL CMFC002Dlg::OnInitDialog()
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

void CMFC002Dlg::OnPaint()
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
HCURSOR CMFC002Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC002Dlg::OnBtn1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);// 控件到变量
	const TCHAR* szSex[] = {L"男",L"女",L"未知"};
	m_strShow = L"性别：";
	// m_radioSex绑定到第1个group属相为true的radio上
	m_strShow += szSex[m_radioSex];
	m_strShow += L"\r\n";
	const TCHAR* szlove[] = { L"否",L"是",L"不确定" };
	m_strShow += L"爱好(IT)：";
	// m_checkLove先绑定到check上，然后再把check改变为tri-state
	m_strShow += szlove[m_checkLove];
	UpdateData(FALSE);// 更新到控件上
}

// combobox
void CMFC002Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_combox.AddString(L"BJ");
	m_combox.AddString(L"sh");
	m_combox.AddString(L"gz");
	m_combox.AddString(L"sz");
	m_combox.SetCurSel(0);
	//m_BtnAdd.ShowWindow(SW_HIDE);
	m_BtnAdd.EnableWindow(FALSE);
}


void CMFC002Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	/*static bool b = false;
	CBitmap bmp;
	bmp.LoadBitmapW(b?IDB_BITMAP1:IDB_BITMAP2);
	m_staticPic.SetBitmap(bmp);
	b = !b;*/
	SetTimer(0x1001, 100, NULL);
	SetTimer(0x1002, 1000, NULL);

}


void CMFC002Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 0x1001)
	{
		static bool b = false;
		CBitmap bmp;
		bmp.LoadBitmapW(b ? IDB_BITMAP1 : IDB_BITMAP2);
		m_staticPic.SetBitmap(bmp);
		b = !b;
	}
	else if(nIDEvent == 0x1002)
	{
		// 在当前位置上偏移10
		// getpos  setpos
		// m_progress.OffsetPos(10);
		m_progress.SetStep(30);// 设置步进值，只需设置1次
		m_progress.StepIt();

	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMFC002Dlg::OnNMThemeChangedSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	//int nPos = m_slider.GetPos();
	//m_progress.SetPos(nPos);
	*pResult = 0;
}


void CMFC002Dlg::OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 此功能要求 Windows Vista 或更高版本。
	// _WIN32_WINNT 符号必须 >= 0x0600。
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	// 先修改控件属性  notify before move
	m_progress.SetPos(pNMTPC->dwPos);
	*pResult = 0;
}
