#pragma once


// CMyTab01

class CMyTab01 : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTab01)

public:
	CMyTab01();
	virtual ~CMyTab01();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void MyInsertItem(DWORD dwCount, ...);
	CDialogEx* m_child[100];
	DWORD m_dwCount;
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
};


