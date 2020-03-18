#ifndef _XM_DATA_TYPE_H_
#define _XM_DATA_TYPE_H_

// �Զ���
typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
#ifdef WIN32
typedef unsigned __int64	uint64;
typedef __int64	 int64;
#else
typedef unsigned long long	uint64;
typedef long long	int64;
#endif
typedef char	int8;
typedef short	int16;
typedef int		int32;

#include <string.h>

// ����
#include <string>
#include <vector>
#include <map>
#include <list>
typedef std::string	String;
typedef std::vector<uint8>		Uint8Array;
typedef std::vector<uint16>		Uint16Array;
typedef std::vector<uint32>		Uint32Array;
typedef std::vector<uint64>		Uint64Array;
typedef std::vector<int8>		Int8Array;
typedef std::vector<int16>		Int16Array;
typedef std::vector<int32>		Int32Array;
typedef std::vector<int64>		Int64Array;
typedef std::vector<float>		Float32Array;
typedef std::vector<double>		Float64Array;
typedef std::vector<std::string>	StringArray;
typedef std::map<std::string, std::string> StringMap;
typedef std::list<std::string> StringList;
typedef std::vector<Uint8Array> Uint8sArray;

#define macroStr(s) #s

// ��ȡ16λ���ݵĸ�8λ
#define GET16H(d)		((d)>>8&0xff)
// ��ȡ16λ���ݵĵ�8λ
#define GET16L(d)		((d)&0xff)
// ͨ���ߵ�8λ����16λ����
#define GET16T(h,l)		(((h)<<8&0xff00)|((l)&0xff))
// ����16λ���ݵĸߵ�8λ��ȡ����
#define GET16S(d)		GET16T(GET16L(d),GET16H(d))

#define GET32H(d)		((d)>>16&0xffff)
#define GET32L(d)		((d)&0xffff)

#ifdef WIN32
#ifndef snprintf
#define snprintf sprintf_s
#endif
#endif

#endif
