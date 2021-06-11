
// SDI_test.h : SDI_test 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CSDI_testApp:
// 이 클래스의 구현에 대해서는 SDI_test.cpp을 참조하십시오.
//

class CSDI_testApp : public CWinAppEx
{
public:
	CSDI_testApp();


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
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
