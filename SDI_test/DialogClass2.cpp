// DialogClass2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SDI_test.h"
#include "DialogClass2.h"
#include "DialogTest.h"
#include "MainFrm.h"
#include "ViewTest_1.h"
#include "Dock.h"

// DialogClass2 대화 상자입니다.

IMPLEMENT_DYNAMIC(DialogClass2, CDialog)

DialogClass2::DialogClass2(CWnd* pParent /*=NULL*/)
	: CDialog(DialogClass2::IDD, pParent)
{

}

DialogClass2::~DialogClass2()
{
}

void DialogClass2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Dlg2_Edit);
}


BEGIN_MESSAGE_MAP(DialogClass2, CDialog)
ON_BN_CLICKED(IDC_BUTTON1, &DialogClass2::OnBnClickedButton1)
ON_BN_CLICKED(IDC_RADIO1, &DialogClass2::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_BUTTON2, &DialogClass2::OnBnClickedButton2)
END_MESSAGE_MAP()

CString msgStr;
CString dataType;

void DialogClass2::OnBnClickedButton1()
{
	int msgInt = 15;

	msgStr.Format(_T("%d"), msgInt);

	SetDlgItemInt(IDC_EDIT1,msgInt);

	DialogMessage(msgStr);

	//msgHwnd = pDialog_1 -> GetSafeHwnd();

	//::SendMessage(msgHwnd,WM_USER_MESSAGE1,msgInt,0);
}

void DialogClass2::OnBnClickedRadio1()
{	
	double msgDouble = 53.63648;
	
	msgStr.Format(_T("%f"), msgDouble);

	DialogMessage(msgStr);
}

void DialogClass2::OnBnClickedButton2()
{
	GetDlgItemText(IDC_EDIT1, msgStr);

	DialogMessage(msgStr);
}

//메세지 (다이얼로그2 -> 뷰(View_Test1))
void DialogClass2::DialogMessage(CString msgStr)
{
	SetDlgItemText(IDC_EDIT1,msgStr);

	msgHwnd = pDialog_1 -> GetSafeHwnd();

	::SendMessage(msgHwnd,WM_USER_MESSAGE1,(WPARAM)&msgStr,0);

	//SetDlgItemText(IDC_EDIT1, NULL);
}