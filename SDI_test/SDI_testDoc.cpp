
// SDI_testDoc.cpp : CSDI_testDoc Ŭ������ ����
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


// CSDI_testDoc ����/�Ҹ�

CSDI_testDoc::CSDI_testDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CSDI_testDoc::~CSDI_testDoc()
{
}

BOOL CSDI_testDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CSDI_testDoc serialization

void CSDI_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CSDI_testDoc ����

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


// CSDI_testDoc ���
