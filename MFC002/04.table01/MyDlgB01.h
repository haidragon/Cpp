#pragma once


// CMyDlgB01 对话框

class CMyDlgB01 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgB01)

public:
	CMyDlgB01(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlgB01();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
