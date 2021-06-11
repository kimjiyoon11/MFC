#pragma once
#include "afxwin.h"

class ViewTest_1 :
	public CWnd
{
public:
	ViewTest_1(void);
	~ViewTest_1(void);
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	BOOL Dialog_View(bool DialogFlag);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT ViewMsg(WPARAM wParam, LPARAM lParam);
	
};
