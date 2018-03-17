#pragma once


// CMyTab

class CMyTab : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTab)

public:
	CMyTab();
	virtual ~CMyTab();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
	CDialogEx* m_child[3];
public:
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
};


