#pragma once
#include "afxcmn.h"


// ccmymodo 对话框

class ccmymodo : public CDialogEx
{
	DECLARE_DYNAMIC(ccmymodo)

public:
	ccmymodo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ccmymodo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	bool EnumModule(DWORD dwPID);
	CListCtrl myctrl;
	afx_msg void OnPaint();
};


extern DWORD pid;