#pragma once


// CMyDlgC01 对话框

class CMyDlgC01 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgC01)

public:
	CMyDlgC01(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlgC01();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
