#pragma once
#include "resource.h" 
#include "afxwin.h"


// DialogTest ��ȭ �����Դϴ�.

class DialogTest : public CDialog
{
	DECLARE_DYNAMIC(DialogTest)

public:
	DialogTest(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DialogTest();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1  };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void DialogClassTest(CString str);
	afx_msg LRESULT DialogMsg(WPARAM wParam, LPARAM lParam);
	CEdit Edit_1;
};
