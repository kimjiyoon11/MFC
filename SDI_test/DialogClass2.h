#pragma once
#include "resource.h" 
#include "afxwin.h"

// DialogClass2 ��ȭ �����Դϴ�.

class DialogClass2 : public CDialog
{
	DECLARE_DYNAMIC(DialogClass2)

public:
	DialogClass2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DialogClass2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
		//afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	CEdit Dlg2_Edit;
	afx_msg void OnBnClickedButton2();

public:
	void DialogMessage(CString str);
};
