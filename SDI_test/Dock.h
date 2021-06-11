#pragma once
#include "afxdockablepane.h"

class CDock :
	public CDockablePane
{
public:
	CDock(void);
	~CDock(void);



public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT DockMsg(WPARAM wParam, LPARAM lParam);

public:
	void ViewTest(bool ViewFlag);

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
