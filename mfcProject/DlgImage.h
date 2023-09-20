#pragma once
#include "afxdialogex.h"


// DlgImage 대화 상자

class DlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(DlgImage)

public:
	DlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgImage();

	CImage m_Image;
	CWnd* m_pParent;
	int nCenterX;
	int nCenterY;
	int nRadius;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	void InitImage();
	void drawBorder(CDC* pDC);
	void drawCross(CDC* pDC);
};
