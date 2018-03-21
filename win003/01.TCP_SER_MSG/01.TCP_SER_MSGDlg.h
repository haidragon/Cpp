
// 01.TCP_SER_MSGDlg.h : 头文件
//

#pragma once
#include "MyTCP.h"


// CMy01TCP_SER_MSGDlg 对话框
class CMy01TCP_SER_MSGDlg : public CDialogEx
{
// 构造
public:
	CMy01TCP_SER_MSGDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY01TCP_SER_MSG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMyTCP m_tcp;
	afx_msg void OnBnClickedButton1();
protected:
	afx_msg LRESULT OnMysocket(WPARAM wParam, LPARAM lParam);
public:
	CString m_edit;
};
