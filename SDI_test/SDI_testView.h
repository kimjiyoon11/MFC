
// SDI_testView.h : CSDI_testView Ŭ������ �������̽�
//


#pragma once


class CSDI_testView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSDI_testView();
	DECLARE_DYNCREATE(CSDI_testView)

// Ư���Դϴ�.
public:
	//CSDI_testDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CSDI_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // SDI_testView.cpp�� ����� ����
inline CSDI_testDoc* CSDI_testView::GetDocument() const
   { return reinterpret_cast<CSDI_testDoc*>(m_pDocument); }
#endif

