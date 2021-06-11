#include "StdAfx.h"
#include "Dock.h"
#include "ViewTest_1.h"
#include "MainFrm.h"
#include "SDI_testView.h"


CDock::CDock(void)
{
}
CDock::~CDock(void)
{
}

ViewTest_1 m_viewChild;

BEGIN_MESSAGE_MAP(CDock, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_MESSAGE(WM_USER_MESSAGE1, CDock::DockMsg)
END_MESSAGE_MAP()

//ViewTest_1 m_viewChild;
//ddddd


BOOL CDock::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CDockablePane::OnCommand(wParam, lParam);
}

int CDock::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
		
	pDockTest = this;

	return 0;
}

void CDock::ViewTest(bool ViewFlag)
{
	if(m_viewChild){
		AfxMessageBox("�̹� ������");	
	}
	else{
		if(ViewFlag = TRUE){
			m_viewChild.Create(_T("STATIC"), _T("txtViewTest_1"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(0, 0, 1000, 1000), pDockTest, 0);
		}	
		else if(ViewFlag = FALSE){
			AfxMessageBox("Fail");	
		}
	}		
}

void CDock::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
		
	if(m_viewChild.GetSafeHwnd())
	{
		m_viewChild.SetWindowPos(NULL,0,0,cx,cy,SWP_NOZORDER);
	}
}



//�޼��� (Dock -> MainFrame)
afx_msg LRESULT CDock::DockMsg(WPARAM wParam, LPARAM lParam)
{
	CString* wParamMsg = (CString*)wParam;
	CString MSG;
	MSG.Format("%s", *wParamMsg);

	//AfxMessageBox(MSG + " Dock");

	CMainFrame *pMain_1 = (CMainFrame *)AfxGetMainWnd();
	msgHwnd = pMain_1 -> GetSafeHwnd();

	::SendMessage(msgHwnd, WM_USER_MESSAGE1, (WPARAM)&MSG,0);

	return 0;
}