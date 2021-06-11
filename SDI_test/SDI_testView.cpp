
// SDI_testView.cpp : CSDI_testView 클래스의 구현
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDI_testView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_MESSAGE(WM_VIEW_MESSAGE1, &CSDI_testView::ViewMsg)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CSDI_testView 생성/소멸

CSDI_testView::CSDI_testView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSDI_testView::~CSDI_testView()
{
}

BOOL CSDI_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSDI_testView 그리기



void CSDI_testView::OnDraw(CDC* /*pDC*/)
{
	/*CSDI_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;*/



}


// CSDI_testView 인쇄


void CSDI_testView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CSDI_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSDI_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSDI_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CSDI_testView 진단

#ifdef _DEBUG
void CSDI_testView::AssertValid() const
{
	CView::AssertValid();
}

void CSDI_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

//CSDI_testDoc* CSDI_testView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
//{
//	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDI_testDoc)));
//	return (CSDI_testDoc*)m_pDocument;
//}
#endif //_DEBUG


// CSDI_testView 메시지 처리기

void CSDI_testView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_Dlg.Create(IDD_DIALOG1, this);
	m_Dlg.ShowWindow(SW_SHOWMAXIMIZED);

	UpdateWindow(); 
}

BOOL CSDI_testView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CSDI_testView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

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

//메세지 View-> Dialog1
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


