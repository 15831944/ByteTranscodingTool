
// ByteTranscodingTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CByteTranscodingToolApp: 
// �йش����ʵ�֣������ ByteTranscodingTool.cpp
//

class CByteTranscodingToolApp : public CWinApp
{
public:
	CByteTranscodingToolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CByteTranscodingToolApp theApp;