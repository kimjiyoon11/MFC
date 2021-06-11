
// SDI_testView.cpp : CSDI_testView Ŭ������ ����
//

#include "stdafx.h"
#include "SDI_test.h"

#include "SDI_testDoc.h"
#include "SDI_testView.h"
#include "DialogTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDI_testView

DialogTest m_Dlg;

IMPLEMENT_DYNCREATE(CSDI_testView, CView)

BEGIN_MESSAGE_MAP(CSDI_testView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDI_testView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_MESSAGE(WM_VIEW_MESSAGE1, &CSDI_testView::ViewMsg)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CSDI_testView ����/�Ҹ�

CSDI_testView::CSDI_testView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSDI_testView::~CSDI_testView()
{
}

BOOL CSDI_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSDI_testView �׸���



void CSDI_testView::OnDraw(CDC* /*pDC*/)
{
	/*CSDI_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;*/



}


// CSDI_testView �μ�


void CSDI_testView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CSDI_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSDI_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSDI_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CSDI_testView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSDI_testView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CSDI_testView ����

#ifdef _DEBUG
void CSDI_testView::AssertValid() const
{
	CView::AssertValid();
}

void CSDI_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

//CSDI_testDoc* CSDI_testView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
//{
//	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDI_testDoc)));
//	return (CSDI_testDoc*)m_pDocument;
//}
#endif //_DEBUG


// CSDI_testView �޽��� ó����

void CSDI_testView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_Dlg.Create(IDD_DIALOG1, this);
	m_Dlg.ShowWindow(SW_SHOWMAXIMIZED);

	UpdateWindow(); 
}

BOOL CSDI_testView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CSDI_testView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

}


int CSDI_testView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void CSDI_testView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if(m_Dlg.GetSafeHwnd())
	{
		m_Dlg.SetWindowPos(NULL,-1, -1, cx,cy, SWP_NOMOVE|SWP_NOZORDER); 
	}
}

//�޼��� View-> Dialog1
afx_msg LRESULT CSDI_testView::ViewMsg(WPARAM wParam, LPARAM lParam)
{
	CString* wParamMsg = (CString*)wParam;
	CString MSG;
	MSG.Format("%s", *wParamMsg);

	//AfxMessageBox(MSG+"VIEW1");
		
	msgHwnd = p_Dlg -> GetSafeHwnd();

	::SendMessage(msgHwnd, WM_USER_MESSAGE1, (WPARAM)&MSG,0);
	
	return 0;
}


