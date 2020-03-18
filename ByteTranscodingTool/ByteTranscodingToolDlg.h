
// ByteTranscodingToolDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CByteTranscodingToolDlg �Ի���
class CByteTranscodingToolDlg : public CDialogEx
{
// ����
public:
	CByteTranscodingToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BYTETRANSCODINGTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// �������͵ĸ�ѡ����
	CComboBox m_datatypeComboBox;
public:
	afx_msg void OnCbnDropdownComboDatatype();
	afx_msg void OnBnClickedButtonConvert();
	afx_msg void OnBnClickedButtonFloatConvert();
	afx_msg void OnBnClickedButtonDoubleConvert();
	afx_msg void OnBnClickedButtonInt16Convert();
	afx_msg void OnBnClickedButtonUint16Convert();
	afx_msg void OnBnClickedButtonInt32Convert();
	afx_msg void OnBnClickedButtonUint32Convert();
	afx_msg void OnBnClickedButtonInt64Convert();
	afx_msg void OnBnClickedButtonUint64Convert();

public:
	// ��ʼλ��ƫ����
	int m_nStartOffset;
	// �����ֽ�����
	CString m_strInput;
	// ���
	CString m_strResult;
	// �Ƿ�ΪС��
	BOOL m_bLittleEndian;
	// �Ƿ���ҪSwap
	BOOL m_bSwap;
	float m_floatVal;
	double m_doubleVal;
	short m_shortVal;
//	unsigned short m_ushortVal;
	int m_int32Val;
//	unsigned int m_uint32Val;
	long long m_int64Val;
//	unsigned long long m_uint64Val;
	CString m_strFloatResult;
	CString m_strDoubleResult;
	CString m_strInt16Result;
	CString m_strUint16Result;
//	CString m_strInt32Result;
	CString m_strUint32Result;
	CString m_strInt64Result;
	CString m_strUint64Result;
	// ��С�˵�Byte Swap��ѡ��
	int m_checkIndex;
	CString m_strInt32Result;
	// unsigned short
	CString m_strUint16Val;
	CString m_strUint32Val;
	CString m_strUint64Val;
};
