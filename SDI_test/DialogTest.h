#pragma once
#include "resource.h" 
#include "afxwin.h"


// DialogTest 대화 상자입니다.

class DialogTest : public CDialog
{
	DECLARE_DYNAMIC(DialogTest)

public:
	DialogTest(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DialogTest();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1  };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void DialogClassTest(CString str);
	afx_msg LRESULT DialogMsg(WPARAM wParam, LPARAM lParam);
	CEdit Edit_1;
};
