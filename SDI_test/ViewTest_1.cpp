#include "StdAfx.h"
#include "ViewTest_1.h"
#include "DialogClass2.h"
#include "resource.h" 
#include "Dock.h"
//#include "typeinfo.h"

ViewTest_1::ViewTest_1(void)
{
}

ViewTest_1::~ViewTest_1(void)
{
}
BEGIN_MESSAGE_MAP(ViewTest_1, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_MESSAGE(WM_USER_MESSAGE1, ViewTest_1::ViewMsg)
END_MESSAGE_MAP()

DialogClass2 m_Dlg2;

int ViewTest_1::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

		pDialog_1 = this;
	
	return 0;
}

BOOL ViewTest_1::Dialog_View(bool DialogFlag){

	if(!m_Dlg2)
	{
		m_Dlg2.Create(IDD_DIALOG2,pDialog_1);
		m_Dlg2.ShowWindow(SW_SHOWMAXIMIZED);
	}
	return 0;
}

void ViewTest_1::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if(m_Dlg2.GetSafeHwnd())
	{
		m_Dlg2.SetWindowPos(NULL,0,0,cx,cy,SWP_NOZORDER);
	}
}

//¸Þ¼¼Áö (ºä -> Dock)

afx_msg LRESULT ViewTest_1::ViewMsg(WPARAM wParam, LPARAM lParam)
{
	//int i;
	//CString str;
	//i = sizeof(wParam);
	//str.Format(_T("%d"), i);
	//AfxMessageBox(str);


	CString* wParamMsg = (CString*)wParam;
	CString MSG;
	MSG.Format("%s", *wParamMsg);

	msgHwnd = pDockTest -> GetSafeHwnd();

	::SendMessage(msgHwnd,WM_USER_MESSAGE1,(WPARAM)&MSG,0);

	return 0;
}

