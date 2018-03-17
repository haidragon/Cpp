#pragma once


// CMyDlgA01 对话框

class CMyDlgA01 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgA01)

public:
	CMyDlgA01(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlgA01();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
