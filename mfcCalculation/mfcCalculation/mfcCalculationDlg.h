
// mfcCalculationDlg.h: 헤더 파일
//

#pragma once
#include <string>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// CmfcCalculationDlg 대화 상자
class CmfcCalculationDlg : public CDialogEx
{
// 생성입니다.
public:
	CmfcCalculationDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	int nFirst;
	int nSecond;
	int nResult;
	double fResult;
	CString currentValue;
	CString formerValue;
	int calKind = 0;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	void SetValueText(int cal);
	void SetResultText();
	void SetContinueResultText();
	void ContinueCal(int cal);
public:
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtnPlus();
	afx_msg void OnBnClickedBtnMinus();
	afx_msg void OnBnClickedBtnMul();
	afx_msg void OnBnClickedBtnDiv();
	afx_msg void OnBnClickedBtnRes();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnClear();
};
