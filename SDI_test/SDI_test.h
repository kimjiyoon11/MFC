
// SDI_test.h : SDI_test ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSDI_testApp:
// �� Ŭ������ ������ ���ؼ��� SDI_test.cpp�� �����Ͻʽÿ�.
//

class CSDI_testApp : public CWinAppEx
{
public:
	CSDI_testApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;
	BOOL  test_1;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDI_testApp theApp;
