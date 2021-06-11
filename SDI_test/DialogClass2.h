#pragma once
#include "resource.h" 
#include "afxwin.h"

// DialogClass2 대화 상자입니다.

class DialogClass2 : public CDialog
{
	DECLARE_DYNAMIC(DialogClass2)

public:
	DialogClass2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DialogClass2();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
