
// 05.cursoriconDlg.h : 头文件
//

#pragma once


// CMy05cursoriconDlg 对话框
class CMy05cursoriconDlg : public CDialogEx
{
// 构造
public:
	CMy05cursoriconDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY05CURSORICON_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CToolBar m_toolbar1;
	CToolBar m_toolbar2;
	afx_msg void On工具栏1号();
	afx_msg void On图片栏1号();
	CStatusBar m_status;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void On哈哈();
	afx_msg void On动态();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};
