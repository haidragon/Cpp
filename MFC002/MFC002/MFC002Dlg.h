
// MFC002Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMFC002Dlg 对话框
class CMFC002Dlg : public CDialogEx
{
// 构造
public:
	CMFC002Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC002_DIALOG };
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
	afx_msg void OnBtn1();
	CString m_strShow;
	int m_radioSex;
	int m_checkLove;
	CComboBox m_combox;
	afx_msg void OnBnClickedButton2();
	CButton m_BtnAdd;
	CStatic m_staticPic;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CProgressCtrl m_progress;
	CSliderCtrl m_slider;
	afx_msg void OnNMThemeChangedSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
