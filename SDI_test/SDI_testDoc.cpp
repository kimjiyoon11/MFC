
// SDI_testDoc.cpp : CSDI_testDoc 클래스의 구현
//

#include "stdafx.h"
#include "SDI_test.h"

#include "SDI_testDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDI_testDoc

IMPLEMENT_DYNCREATE(CSDI_testDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDI_testDoc, CDocument)
END_MESSAGE_MAP()


// CSDI_testDoc 생성/소멸

CSDI_testDoc::CSDI_testDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CSDI_testDoc::~CSDI_testDoc()
{
}

BOOL CSDI_testDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CSDI_testDoc serialization

void CSDI_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CSDI_testDoc 진단

#ifdef _DEBUG
void CSDI_testDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDI_testDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSDI_testDoc 명령
