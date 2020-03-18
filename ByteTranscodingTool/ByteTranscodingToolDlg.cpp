
// ByteTranscodingToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ByteTranscodingTool.h"
#include "ByteTranscodingToolDlg.h"
#include "afxdialogex.h"

#include "ByteConvertTools.h"
#include "func.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CByteTranscodingToolDlg �Ի���



CByteTranscodingToolDlg::CByteTranscodingToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CByteTranscodingToolDlg::IDD, pParent)
	, m_nStartOffset(0)
	, m_strInput(_T(""))
	, m_strResult(_T(""))
	, m_bLittleEndian(FALSE)
	, m_bSwap(FALSE)
	, m_floatVal(0)
	, m_doubleVal(0)
	, m_shortVal(0)
	, m_int32Val(0)
	, m_int64Val(0)
	, m_strFloatResult(_T(""))
	, m_strDoubleResult(_T(""))
	, m_strInt16Result(_T(""))
	, m_strUint16Result(_T(""))
	, m_strInt32Result(_T(""))
	, m_strUint32Result(_T(""))
	, m_strInt64Result(_T(""))
	, m_strUint64Result(_T(""))
	, m_checkIndex(0)
	, m_strUint16Val(_T(""))
	, m_strUint32Val(_T(""))
	, m_strUint64Val(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CByteTranscodingToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DATATYPE, m_datatypeComboBox);
	DDX_Text(pDX, IDC_EDIT_STARTPOS, m_nStartOffset);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
	DDX_Check(pDX, IDC_CHECK_LITTLE, m_bLittleEndian);
	DDX_Check(pDX, IDC_CHECK_SWAP, m_bSwap);
	DDX_Text(pDX, IDC_EDIT_FLOAT_INPUT, m_floatVal);
	DDX_Text(pDX, IDC_EDIT_DOUBLE_INPUT, m_doubleVal);
	DDX_Text(pDX, IDC_EDIT_INT16_INPUT, m_shortVal);
	DDX_Text(pDX, IDC_EDIT_INT32_INPUT, m_int32Val);
	//  DDX_Text(pDX, IDC_EDIT_UINT32_INPUT, m_uint32Val);
	DDX_Text(pDX, IDC_EDIT_INT64_INTPUT, m_int64Val);
	//  DDX_Text(pDX, IDC_EDIT_UINT64_INTPUT, m_uint64Val);
	DDX_Text(pDX, IDC_EDIT_FLOAT_OUTPUT, m_strFloatResult);
	DDX_Text(pDX, IDC_EDIT_DOUBLE_OUTPUT, m_strDoubleResult);
	DDX_Text(pDX, IDC_EDIT_INT16_OUTPUT, m_strInt16Result);
	DDX_Text(pDX, IDC_EDIT_UINT16_OUTPUT, m_strUint16Result);
	//  DDX_Text(pDX, IDC_EDIT_INT32_INPUT, m_strInt32Result);
	DDX_Text(pDX, IDC_EDIT_UINT32_OUTPUT, m_strUint32Result);
	DDX_Text(pDX, IDC_EDIT_INT64_OUTPUT, m_strInt64Result);
	DDX_Text(pDX, IDC_EDIT_UINT64_OUTPUT, m_strUint64Result);
	DDX_Radio(pDX, IDC_RADIO_BIG_ENDIAN, m_checkIndex);
	DDX_Text(pDX, IDC_EDIT_INT32_OUTPUT, m_strInt32Result);
	DDX_Text(pDX, IDC_EDIT_UINT16_INPUT, m_strUint16Val);
	DDX_Text(pDX, IDC_EDIT_UINT32_INPUT, m_strUint32Val);
	DDX_Text(pDX, IDC_EDIT_UINT64_INTPUT, m_strUint64Val);
}

BEGIN_MESSAGE_MAP(CByteTranscodingToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonConvert)
	ON_CBN_DROPDOWN(IDC_COMBO_DATATYPE, &CByteTranscodingToolDlg::OnCbnDropdownComboDatatype)
	ON_BN_CLICKED(IDC_BUTTON_FLOAT_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonFloatConvert)
	ON_BN_CLICKED(IDC_BUTTON_DOUBLE_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonDoubleConvert)
	ON_BN_CLICKED(IDC_BUTTON_INT16_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonInt16Convert)
	ON_BN_CLICKED(IDC_BUTTON_UINT16_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonUint16Convert)
	ON_BN_CLICKED(IDC_BUTTON_INT32_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonInt32Convert)
	ON_BN_CLICKED(IDC_BUTTON_UINT32_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonUint32Convert)
	ON_BN_CLICKED(IDC_BUTTON_INT64_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonInt64Convert)
	ON_BN_CLICKED(IDC_BUTTON_UINT64_CONVERT, &CByteTranscodingToolDlg::OnBnClickedButtonUint64Convert)
END_MESSAGE_MAP()


// CByteTranscodingToolDlg ��Ϣ�������

BOOL CByteTranscodingToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	// Ϊ��ѡ������һЩ����
	m_datatypeComboBox.InsertString(0, "int16");
	m_datatypeComboBox.InsertString(1, "int32");
	m_datatypeComboBox.InsertString(2, "int64");
	m_datatypeComboBox.InsertString(3, "uint16");
	m_datatypeComboBox.InsertString(4, "uint32");
	m_datatypeComboBox.InsertString(5, "uint64");
	m_datatypeComboBox.InsertString(6, "float");
	m_datatypeComboBox.InsertString(7, "double");


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CByteTranscodingToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CByteTranscodingToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CByteTranscodingToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CByteTranscodingToolDlg::OnBnClickedButtonConvert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ӿؼ��������,����������ݺ���Խ���״̬�ж� 
	UpdateData(TRUE);

	// 1.��ȡ�����ϵ����ã������������ͣ��Ƿ��Ǵ�С�ˡ�Swap��
	// ��ȡCOMBoBox��ѡ�����λ�ã�Ȼ��õ���Ӧλ�õ�����
	int nIndex = m_datatypeComboBox.GetCurSel();
	CString strDataTypeText;
	m_datatypeComboBox.GetLBText(nIndex, strDataTypeText);
	//MessageBox(_T(strDataTypeText.GetBuffer(0)), _T("info"));

	CString strInput = m_strInput;
	// �ж�������ֽ������Ƿ�Ϸ�
	if (strInput.IsEmpty())
	{
		MessageBox("�����16�����ֽ�����Ϊ��", "error", MB_ICONINFORMATION);
	}

	int nStartPos = m_nStartOffset;
	if (nStartPos < 0 || nStartPos > strInput.GetLength())
	{
		MessageBox("�������ʼƫ�Ʋ��Ϸ�", "error", MB_OKCANCEL);
	}

	if (strDataTypeText == "int16")
	{
		int16 i16;

		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(i16) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		//uint8 bytesArr1[2] = { 0xC3, 0xF5 };
		ByteConvertTools::get_data(i16, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(i16);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "uint16")
	{
		uint16 u16;
		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(u16) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		//uint8 bytesArr1[2] = { 0xC3, 0xF5 };
		ByteConvertTools::get_data(u16, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(u16);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "int32")
	{
		int32 i32;
		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(i32) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		//uint8 bytesArr1[2] = { 0xC3, 0xF5 };
		ByteConvertTools::get_data(i32, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(i32);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "uint32")
	{
		uint32 u32;
		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(uint32) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		//uint8 bytesArr1[2] = { 0xC3, 0xF5, 0x48, 0x40 };
		ByteConvertTools::get_data(u32, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(u32);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "int64")
	{
		int64 i64;

		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(int64) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		ByteConvertTools::get_data(i64, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(i64);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "uint64")
	{
		uint64 u64;

		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(uint64) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		//uint8 bytesArr1[2] = { 0xC3, 0xF5, 0x48, 0x40 };
		ByteConvertTools::get_data(u64, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(u64);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "float")
	{
		float f32;
		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(float) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}
		
		//uint8 bytesArr1[4] = { 0xC3, 0xF5, 0x48, 0x40 };
		ByteConvertTools::get_data(f32, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(f32);
		m_strResult = strResult1.c_str();
	}
	else if (strDataTypeText == "double")
	{
		double d32;
		std::string strIn = m_strInput.GetBuffer(0);
		std::string strSubtemp = strIn.substr(m_nStartOffset * 2, sizeof(double) * 2);
		Uint8Array byteArr;
		for (int i = 0; i <= strSubtemp.size() - 2; i += 2)
		{
			String ss = strSubtemp.substr(i, 2);
			int iTemp;
			Math::Tools::to_int(iTemp, ss, 16);
			byteArr.push_back(iTemp);
		}

		//uint8 bytesArr1[4] = { 0xC3, 0xF5, 0x48, 0x40 };
		ByteConvertTools::get_data(d32, byteArr, 0, m_bLittleEndian, m_bSwap);

		std::string strResult1 = std::to_string(d32);
		m_strResult = strResult1.c_str();
	}

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnCbnDropdownComboDatatype()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//����������ĸ߶�
	CRect rc;
	//����������Ի����У�����ʹ�� GetDlgItem(IDC_COMBO)->GetClientRect(&rc); ��ȡ�ؼ��Ĵ�С
	GetDlgItem(IDC_COMBO_DATATYPE)->GetClientRect(&rc);
	//SetWindowPos�������棬����������е�100���ͱ�ʾ�����б���ʾ�ĸ߶�
	m_datatypeComboBox.SetWindowPos(NULL, 0, 0, rc.Width(), rc.Height() + 150, SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW);
}

void CByteTranscodingToolDlg::OnBnClickedButtonFloatConvert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ӿؼ��������,����������ݺ���Խ���״̬�ж� 
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	ByteConvertTools::convertToBytesArray(tmp8, m_floatVal, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strFloatResult.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonDoubleConvert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	ByteConvertTools::convertToBytesArray(tmp8, m_doubleVal, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strDoubleResult.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonInt16Convert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	ByteConvertTools::convertToBytesArray(tmp8, m_shortVal, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strInt16Result.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonUint16Convert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	// ������ѡ�ĵ�ѡ��ť�жϴ�С�˺�Byte Swap�����(��4��)
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	// �ȴӽ����л�ȡunsinged short�Ķ�ӦCString������ֵ��ת����unsinged short
	std::string strUint16Temp = m_strUint16Val.GetBuffer(0);
	// ����MFC�пؼ��󶨵ı�����֧��unsinged short��ʽ�ģ��ʶ�ʹ��CString���棬Ȼ��ת����unsinged short
	//int i32Val = std::stoi(strUint16Temp);
	int i32Val;
	bool bSuccessd = Math::Tools::to_int(i32Val, strUint16Temp);
	if (i32Val < 0 || i32Val >= pow(2, 16) || !bSuccessd
		|| !ByteConvertTools::isStrNumber(strUint16Temp))
	{
		MessageBox("�����unsinged short�Ͳ��Ϸ�(��ΧΪ��[0, 65535]), ����������!", "error", MB_OKCANCEL);
		m_strUint16Result = "";

		UpdateData(FALSE);

		return;
	}

	unsigned short uint16Val = i32Val;
	ByteConvertTools::convertToBytesArray(tmp8, uint16Val, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strUint16Result.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonInt32Convert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	ByteConvertTools::convertToBytesArray(tmp8, m_int32Val, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strInt32Result.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonUint32Convert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	// �ȴӽ����л�ȡunsinged int�Ķ�ӦCString������ֵ��ת����unsinged int
	std::string strUint32Temp = m_strUint32Val.GetBuffer(0);
	int64 i64Val;
	bool bSuccessed = Math::Tools::to_int64(i64Val, strUint32Temp);
	if (i64Val < 0 || (i64Val > pow(2, 32) - 1) || !bSuccessed || 
		!ByteConvertTools::isStrNumber(strUint32Temp))
	{
		MessageBox("�����unsinged int���Ϸ�(��ΧΪ��[0, 4294967295]),����������!", "error", MB_OKCANCEL);
		m_strUint32Result = "";

		UpdateData(FALSE);

		return;
	}

	uint32 uint32Val = i64Val;

	ByteConvertTools::convertToBytesArray(tmp8, uint32Val, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strUint32Result.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonInt64Convert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	ByteConvertTools::convertToBytesArray(tmp8, m_int64Val, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strInt64Result.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}


void CByteTranscodingToolDlg::OnBnClickedButtonUint64Convert()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Uint8Array tmp8;
	bool isLittleEndian;
	bool isByteSwap;
	switch (m_checkIndex)
	{
	case 0:	// ��� abcd
		isLittleEndian = false;
		isByteSwap = false;
		break;
	case 1:	// С�� dcba
		isLittleEndian = true;
		isByteSwap = false;
		break;
	case 2: // ��� Byte swap  cdab
		isLittleEndian = false;
		isByteSwap = true;
		break;
	case 3: // С�� Byte swap badc
		isLittleEndian = true;
		isByteSwap = true;
		break;
	default:
		break;
	}

	// �ȴӽ����л�ȡunsinged long long�Ķ�ӦCString������ֵ��ת����unsinged long long
	std::string strUint64Temp = m_strUint64Val.GetBuffer(0);
	int64 i64Val;
	uint64 uint64Val;

	bool bSuccessed1 = Math::Tools::to_int64(i64Val, strUint64Temp);

	bool bSuccessed2 = Math::Tools::to_uint64(uint64Val, strUint64Temp);

	if (i64Val < 0 || (i64Val > pow(2, 64) - 1) || !bSuccessed1 || !bSuccessed2
		|| !ByteConvertTools::isStrNumber(strUint64Temp))
	{
		MessageBox("�����uint64�Ͳ��Ϸ�(��ΧΪ��[0, 9223372036854775807])", "error", MB_OKCANCEL);
		m_strUint64Result = "";

		UpdateData(FALSE);

		return;
	}

	ByteConvertTools::convertToBytesArray(tmp8, uint64Val, isLittleEndian, isByteSwap);
	String sstr;
	for (int i = 0; i < tmp8.size(); i++)
	{
		char ss[5];
		sprintf(ss, "%02X", tmp8[i]);
		sstr += ss;
	}
	m_strUint64Result.Format("%s", sstr.c_str());

	UpdateData(FALSE);
}
