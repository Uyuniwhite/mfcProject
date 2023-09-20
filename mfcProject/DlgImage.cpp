// DlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "mfcProject.h"
#include "afxdialogex.h"
#include "DlgImage.h"


// DlgImage 대화 상자

IMPLEMENT_DYNAMIC(DlgImage, CDialogEx)

DlgImage::DlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgImage, pParent)
{
	m_pParent = pParent;
}

DlgImage::~DlgImage()
{
}

void DlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DlgImage 메시지 처리기


BOOL DlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 640, 640);
	InitImage();
	


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void DlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 640;
	int nBpp = 8;

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_Image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}


void DlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_Image)
	{
		m_Image.Draw(dc, 0, 0);
	}
	drawBorder(&dc);
	drawCross(&dc);
	
}

void DlgImage::drawBorder(CDC* pDC)
{
	if (m_Image)
	{	
		CRect rect(nCenterX - nRadius, nCenterY - nRadius, nCenterX + nRadius, nCenterY + nRadius);
		CPen pen(PS_SOLID, 3, RGB(255, 255, 0)); 
		CPen* pOldPen = pDC->SelectObject(&pen);

		CBrush brush(RGB(176, 196, 222));
		CBrush* pOldBrush = pDC->SelectObject(&brush);

		pDC->Ellipse(rect);

		pDC->SelectObject(pOldPen);

	}
	
}


void DlgImage::drawCross(CDC* pDC)
{
	pDC->MoveTo(nCenterX - nRadius / 10, nCenterY);
	pDC->LineTo(nCenterX + nRadius / 10, nCenterY);
	pDC->MoveTo(nCenterX, nCenterY - nRadius / 10);
	pDC->LineTo(nCenterX, nCenterY + nRadius / 10);
}