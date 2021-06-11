// DialogTest.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SDI_test.h"
#include "DialogTest.h"
#include "Dock.h"
#include "MainFrm.h"
#include "ViewTest_1.h";



// DialogTest ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DialogTest, CDialog)

DialogTest::DialogTest(CWnd* pParent /*=NULL*/)
	: CDialog(DialogTest::IDD, pParent)
{

}

DialogTest::~DialogTest()
{
}

void DialogTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_1);
}


BEGIN_MESSAGE_MAP(DialogTest, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogTest::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogTest::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DialogTest::OnBnClickedButton3)
	ON_WM_SIZE()
	ON_MESSAGE(WM_USER_MESSAGE1, &DialogTest::DialogMsg)
END_MESSAGE_MAP()


// DialogTest �޽��� ó�����Դϴ�.

void DialogTest::OnBnClickedButton1()
{
	SetDlgItemText(IDC_EDIT1, "��ư1");

	p_Dlg = this;

	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	pMain -> DockingClass(TRUE);

	/*CString test123 = "test";

	double dValue = _tstof(test123);

	CString ParseTest;

	ParseTest.Format(_T("%f"), dValue);

	AfxMessageBox(ParseTest);*/
}

void DialogTest::OnBnClickedButton2() //�� ����
{
	SetDlgItemText(IDC_EDIT1, "��ư2"); 

	CDock *pView1 = (CDock *)GetActiveWindow();	
	pView1 -> ViewTest(TRUE);
}

void DialogTest::OnBnClickedButton3() // �� ���� ���̾�α�
{
	SetDlgItemText(IDC_EDIT1, "��ư3"); 
	
	ViewTest_1 *pDialog = (ViewTest_1 *)GetActiveWindow();	
	pDialog -> Dialog_View(TRUE);	
}

afx_msg LRESULT DialogTest::DialogMsg(WPARAM wParam, LPARAM lParam)
{
	CString* wParamMsg = (CString*)wParam;
	CString MSG;
	MSG.Format("%s", *wParamMsg);

	SetDlgItemText(IDC_EDIT1, MSG);

	return 0;
}

//void DialogTest::DialogClassTest(CString str){ //Dialog2���� ��ư Ŭ�� > Dialog1 IDC_EDIT1�� �ؽ�Ʈ���
//	
//	HWND hWnd;
//	hWnd = p_Dlg -> GetSafeHwnd();
//
//	//SetDlgItemTextW(hWnd, IDC_EDIT1, (LPCWSTR)(LPCTSTR)str);
//	
//	int strLen = strlen(str.GetBuffer(str.GetLength()));
//
//	WCHAR* strLPCWSTR = new WCHAR[strLen];
//
//	MultiByteToWideChar(0, 0, str, strLen + 1, strLPCWSTR, strLen + 1); // CString => LPCWSTR
//
//	SetDlgItemTextW(hWnd, IDC_EDIT1, strLPCWSTR);
//}