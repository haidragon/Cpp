
// 01.ListTreeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "01.ListTree.h"
#include "01.ListTreeDlg.h"
#include "afxdialogex.h"

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


// CMy01ListTreeDlg 对话框



CMy01ListTreeDlg::CMy01ListTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY01LISTTREE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy01ListTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_mfcTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_mfcList);
}

BEGIN_MESSAGE_MAP(CMy01ListTreeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMy01ListTreeDlg::OnNMClickList1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CMy01ListTreeDlg::OnTvnSelchangedTree1)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CMy01ListTreeDlg::OnNMClickTree1)
END_MESSAGE_MAP()


// CMy01ListTreeDlg 消息处理程序

BOOL CMy01ListTreeDlg::OnInitDialog()
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
	InitImgList();
	InitList();
	InitTree();
	m_mfcTree.SetRelatedList(&m_mfcList);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy01ListTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy01ListTreeDlg::OnPaint()
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
HCURSOR CMy01ListTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy01ListTreeDlg::InitList()
{
	// 设置扩展风格  带网格  整行选中
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	// 设置list的关联图标数组
	m_list.SetImageList(&m_img, LVSIL_SMALL);
	// 设置行列信息
	// 1. 先设置列标题
	m_list.InsertColumn(0, L"第1列", 0, 80);
	m_list.InsertColumn(1, L"第2列", 0, 80);
	m_list.InsertColumn(2, L"第3列", 0, 80);
	// 2. 再插入行信息   行标题  行内容
	for (int i=0;i<20;i++)
	{
		TCHAR szShow[20] = {};
		swprintf_s(szShow, 20, L"第%d行",i+1);
		// 行标题 
		m_list.InsertItem(i, szShow,i%4);
		// 行内容
		swprintf_s(szShow, 20, L"第%d行%d列", i + 1,1);
		m_list.SetItemText(i, 1, szShow);
		swprintf_s(szShow, 20, L"第%d行%d列", i + 1, 2);
		m_list.SetItemText(i, 2, szShow);
	}

}

void CMy01ListTreeDlg::InitImgList()
{
	// 每个icon的信息  大小等
	// 创建一成员为32*32大小使用32位色的icon数组，
	// 数组初始空间大小为4个，满了之后按1递增
	m_img.Create(32, 32, ILC_COLOR32, 4, 1);
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON1));
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON2));
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON3));
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON4));

}



void CMy01ListTreeDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CString str = m_list.GetItemText(pNMItemActivate->iItem, pNMItemActivate->iSubItem);
	MessageBox(str.GetBuffer());
}

void CMy01ListTreeDlg::InitTree()
{
	// 设置关联图标
	m_tree.SetImageList(&m_img, TVSIL_NORMAL);
	// 1级节点
	HTREEITEM hParent = m_tree.InsertItem(
		L"SDK",// 插入文本
		0,// 正常情况下显示的图标在数组中的索引
		3,// 该节点被点击的时候显示的图标在数组中的索引
		TVI_ROOT,// 父节点
		TVI_LAST// 插入方式
	);
	// 2级节点
	m_tree.InsertItem(L"SDK001", 1,3,hParent, TVI_LAST);
	m_tree.InsertItem(L"SDK002", 2,3,hParent, TVI_LAST);
	// 1级节点
	hParent = m_tree.InsertItem(L"MFC", 0,3,TVI_ROOT, TVI_LAST);
	m_tree.InsertItem(L"MFC001", 1, 3, hParent, TVI_LAST);
	m_tree.InsertItem(L"MFC002", 2, 3, hParent, TVI_LAST);
}


void CMy01ListTreeDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_tree.Invalidate();
}


void CMy01ListTreeDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CPoint pt;
	GetCursorPos(&pt);
	// 屏幕坐标转客户区坐标 
	m_tree.ScreenToClient(&pt);
	UINT uFlags = 0;
	//TVHT_ONITEMLABEL 
	HTREEITEM hTree  = m_tree.HitTest(pt, &uFlags);
	if (uFlags == TVHT_ONITEMLABEL || 
		uFlags == TVHT_ONITEMICON)
	{
		CString str = m_tree.GetItemText(hTree);
		MessageBox(str);
	}
	
}
