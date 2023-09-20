
// mfcCalculationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcCalculation.h"
#include "mfcCalculationDlg.h"
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


// CmfcCalculationDlg 대화 상자



CmfcCalculationDlg::CmfcCalculationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCalculationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcCalculationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_0, &CmfcCalculationDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN_1, &CmfcCalculationDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN_2, &CmfcCalculationDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN_3, &CmfcCalculationDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN_4, &CmfcCalculationDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN_5, &CmfcCalculationDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN_6, &CmfcCalculationDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN_7, &CmfcCalculationDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN_8, &CmfcCalculationDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN_9, &CmfcCalculationDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_PLUS, &CmfcCalculationDlg::OnBnClickedBtnPlus)
	ON_BN_CLICKED(IDC_BTN_MINUS, &CmfcCalculationDlg::OnBnClickedBtnMinus)
	ON_BN_CLICKED(IDC_BTN_MUL, &CmfcCalculationDlg::OnBnClickedBtnMul)
	ON_BN_CLICKED(IDC_BTN_DIV, &CmfcCalculationDlg::OnBnClickedBtnDiv)
	ON_BN_CLICKED(IDC_BTN_RES, &CmfcCalculationDlg::OnBnClickedBtnRes)
	ON_BN_CLICKED(IDC_BTN_DEL, &CmfcCalculationDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CmfcCalculationDlg::OnBnClickedBtnClear)
END_MESSAGE_MAP()


// CmfcCalculationDlg 메시지 처리기

BOOL CmfcCalculationDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcCalculationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcCalculationDlg::OnPaint()
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
HCURSOR CmfcCalculationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CmfcCalculationDlg::OnBnClickedBtn0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_CURRENT, currentValue);
	int lenCurrentValue = currentValue.GetLength();
	if (lenCurrentValue != 0) {
		currentValue += '0';
		SetDlgItemText(IDC_CURRENT, currentValue);
	}
}


void CmfcCalculationDlg::OnBnClickedBtn1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '1';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '2';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '3';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '4';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '5';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '6';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '7';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '8';
	SetDlgItemText(IDC_CURRENT, currentValue);
}


void CmfcCalculationDlg::OnBnClickedBtn9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue += '9';
	SetDlgItemText(IDC_CURRENT, currentValue);
}



void CmfcCalculationDlg::OnBnClickedBtnPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_CURRENT, currentValue);
	SetValueText(1);
}


void CmfcCalculationDlg::OnBnClickedBtnMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_CURRENT, currentValue);
	SetValueText(2);
}


void CmfcCalculationDlg::OnBnClickedBtnMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_CURRENT, currentValue);
	SetValueText(3);
}


void CmfcCalculationDlg::OnBnClickedBtnDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_CURRENT, currentValue);
	SetValueText(4);
}


void CmfcCalculationDlg::OnBnClickedBtnRes()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calKind != 0) {
		GetDlgItemText(IDC_CURRENT, currentValue);

		nFirst = _ttoi(formerValue);
		nSecond = _ttoi(currentValue);

		if (calKind == 1) {
			nResult = nFirst + nSecond;
		}
		else if (calKind == 2) {
			nResult = nFirst - nSecond;
		}
		else if (calKind == 3) {
			nResult = nFirst * nSecond;
		}
		else if (calKind == 4) {
			if (nFirst % nSecond == 0) {
				nResult = nFirst / nSecond;
				calKind = 5;
			}
			fResult = double(nFirst) / double(nSecond);
		}

		SetResultText();

		calKind = 0;
		currentValue = "";
	}
	
}

void CmfcCalculationDlg::SetResultText()
{
	CString sResult;

	if (calKind != 4) {
		sResult.Format(_T("%d"), nResult);
		SetDlgItemText(IDC_CURRENT, sResult);
	}
	else {
		sResult.Format(_T("%f"), fResult);
		SetDlgItemText(IDC_CURRENT, sResult);
	}
	
	SetDlgItemText(IDC_FORMER, _T(""));
}

void CmfcCalculationDlg::SetValueText(int cal)
{
	int lenCurrentValue = currentValue.GetLength();
	CString dataValue;

	if (lenCurrentValue != 0) {
		GetDlgItemText(IDC_CURRENT, formerValue);

		if (cal == 1) {
			dataValue.Format(_T("%s + "), formerValue);
		}
		else if (cal == 2) {
			dataValue.Format(_T("%s - "), formerValue);
		}
		else if (cal == 3) {
			dataValue.Format(_T("%s × "), formerValue);
		}
		else if (cal == 4) {
			dataValue.Format(_T("%s ÷ "), formerValue);
		}
		
		SetDlgItemText(IDC_FORMER, dataValue);
		SetDlgItemText(IDC_CURRENT, _T(""));
		currentValue = "";
		calKind = cal;
	}
}



void CmfcCalculationDlg::OnBnClickedBtnDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_CURRENT, currentValue);
	GetDlgItemText(IDC_FORMER, formerValue);
	
	int lenCurrentValue = currentValue.GetLength();

	if (lenCurrentValue != 0) {
		currentValue.Delete(lenCurrentValue -1, 1);
		SetDlgItemText(IDC_CURRENT, currentValue);
	}
}


void CmfcCalculationDlg::OnBnClickedBtnClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	currentValue = "";
	formerValue = "";
	SetDlgItemText(IDC_CURRENT, currentValue);
	SetDlgItemText(IDC_FORMER, formerValue);
}
