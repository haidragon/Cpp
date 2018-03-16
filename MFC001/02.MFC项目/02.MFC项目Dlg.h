
// 02.MFC项目Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy02MFC项目Dlg 对话框
class CMy02MFC项目Dlg : public CDialogEx
{
// 构造
public:
	CMy02MFC项目Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY02MFC_DIALOG };
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
	CString m_str;
	afx_msg void OnBnClickedButton1();
	CString m_str2;
	CEdit m_edit;
	afx_msg void 按钮2被点击了();
	afx_msg void 自定义按钮3被点击了();
	CButton m_btn;
};
