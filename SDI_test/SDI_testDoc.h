
// SDI_testDoc.h : CSDI_testDoc Ŭ������ �������̽�
//


#pragma once


class CSDI_testDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CSDI_testDoc();
	DECLARE_DYNCREATE(CSDI_testDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CSDI_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


