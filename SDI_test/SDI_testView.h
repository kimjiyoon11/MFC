
// SDI_testView.h : CSDI_testView 클래스의 인터페이스
//


#pragma once


class CSDI_testView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSDI_testView();
	DECLARE_DYNCREATE(CSDI_testView)

// 특성입니다.
public:
	//CSDI_testDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSDI_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT ViewMsg(WPARAM wParam, LPARAM lParam);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // SDI_testView.cpp의 디버그 버전
inline CSDI_testDoc* CSDI_testView::GetDocument() const
   { return reinterpret_cast<CSDI_testDoc*>(m_pDocument); }
#endif

