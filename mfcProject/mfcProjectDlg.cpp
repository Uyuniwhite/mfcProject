
// mfcProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcProject.h"
#include "mfcProjectDlg.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcProjectDlg 대화 상자



CmfcProjectDlg::CmfcProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btn_Create, &CmfcProjectDlg::OnBnClickedBtnCreate)
	ON_BN_CLICKED(IDC_Get_Center, &CmfcProjectDlg::OnBnClickedGetCenter)
END_MESSAGE_MAP()


// CmfcProjectDlg 메시지 처리기

BOOL CmfcProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1000, 700);

	SetFontStyle();

	m_pDlgImage = new DlgImage;
	m_pDlgImage->Create(IDD_DlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcProjectDlg::OnBnClickedBtnCreate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	drawCircle();
}

void CmfcProjectDlg::drawCircle()
{	
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();
	int nRadius = GetDlgItemInt(IDC_Edit_Radius);
	

	memset(fm, 0xff, nWidth * nHeight);

	if (0 < nRadius && nRadius < 315) {
		std::cout << nRadius << std::endl;
		int nCenterX = rand() % (nWidth - 2 * nRadius) + nRadius;
		int nCenterY = rand() % (nHeight - 2 * nRadius) + nRadius;
		for (int j = 0; j < nHeight; j++) {
			for (int i = 0; i < nWidth; i++) {
				int dx = i - nCenterX;
				int dy = j - nCenterY;
				if (dx * dx + dy * dy <= nRadius * nRadius) {
					fm[j * nPitch + i] = 0;
				}
			}
		}

		m_pDlgImage->nCenterX = nCenterX;
		m_pDlgImage->nCenterY = nCenterY;
		m_pDlgImage->nRadius = nRadius;

		m_pDlgImage->Invalidate();
	}
	else {
		AfxMessageBox(_T("1 ~ 315 사이의 숫자를 입력하세요!"));
		SetDlgItemText(IDC_Edit_Radius, _T(""));
	}
}



void CmfcProjectDlg::OnBnClickedGetCenter()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();

	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j * nPitch + i] == 0) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	std::cout << dCenterX << "\t" << dCenterY << std::endl;
	
	CString CenterData;
	CenterData.Format(_T("원의 중심은 (%.0f, %.0f)입니다!"), dCenterX, dCenterY);
	SetDlgItemText(IDC_Center_label, CenterData);
}

void CmfcProjectDlg::SetFontStyle()
{
	CStatic* pSizeText1 = (CStatic*)GetDlgItem(IDC_Size_Text);
	CStatic* pSizeText2 = (CStatic*)GetDlgItem(IDC_Size_Text2);
	CStatic* pStaticText2 = (CStatic*)GetDlgItem(IDC_Center_label);

	if (true)
	{
		CFont font;
		font.CreatePointFont(30, _T("Arial"));

		pSizeText1->SetFont(&font);
		pSizeText2->SetFont(&font);
		pStaticText2->SetFont(&font);
	}
}
