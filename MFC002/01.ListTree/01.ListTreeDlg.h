
// 01.ListTreeDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"


// CMy01ListTreeDlg 对话框
class CMy01ListTreeDlg : public CDialogEx
{
// 构造
public:
	CMy01ListTreeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY01LISTTREE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	// 初始化list
	void InitList();
	// 初始化图标数组
	CImageList m_img;
	void InitImgList();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	// 初始化树控件
	CTreeCtrl m_tree;
	void  InitTree();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CMFCShellTreeCtrl m_mfcTree;
	CMFCShellListCtrl m_mfcList;
};
