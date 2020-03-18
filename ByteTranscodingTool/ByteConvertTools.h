#pragma once
#include "type.h"
#include <algorithm>
#include <array>
#include <regex>	// for std::regex_match

namespace ByteConvertTools
{
	// �����byte�����л�ȡָ�����͵�����
	// ֧��int16,int32,int64,float,double
	template<typename T>
	bool get_data(T& _return, const uint8* buffer, size_t buffersize,
		uint16 offset_bytes, bool isLittle, bool isSwapByte)
	{
		uint32 totalByteNum = buffersize;
		uint32 byteNum = sizeof(T);
		uint32 regNum = byteNum / 2;
		uint32 startPos = offset_bytes;
		uint32 endPos = startPos + byteNum;
		if ((regNum == 0 || byteNum % 2 != 0) || (startPos > totalByteNum || endPos > totalByteNum)) {
			return false;
		}
		// ��ȡģ�����T�ľ�������(int16,int32,int64,float,double)
		auto& type = typeid(T);
		if ((type == typeid(double) || type == typeid(int64) || type == typeid(uint64)) ||
			(type == typeid(float) || type == typeid(uint32) || type == typeid(int32)) ||
			(type == typeid(int16) || type == typeid(uint16))) {
			Uint8Array tmp8; Uint16Array tmp16(regNum);
			/*
				��ͬ�ļ������ϵ�ṹʹ�ò�ͬ���ֽ�˳��洢���ݡ�
				����ˡ���ʾ�����Ч�ֽ��ڵ��ʵ���ˡ������λ�ֽڴ�����ֽ�����ĵ�λ
				��С�ˡ���ʾ�����Ч�ֽ��ڵ��ʵ��Ҷˡ������λ�ֽڴ�����ֽ�����ĸ�λ
			*/
			if (isLittle) {
				// С���ֽ��� dcba
				std::copy(buffer + startPos, buffer + endPos, std::back_inserter(tmp8));
			}
			else {
				// ����ֽ������ֽ�������з�ת abcd
				std::reverse_copy(buffer + startPos, buffer + endPos, std::back_inserter(tmp8));
			}
			memcpy(tmp16.data(), tmp8.data(), byteNum);
			if (isSwapByte)
			{
				std::reverse(tmp16.begin(), tmp16.end());
				Uint8Array tmp1(byteNum);
				memcpy(tmp1.data(), tmp16.data(), byteNum);
				std::reverse(tmp1.begin(), tmp1.end());
				memcpy(tmp16.data(), tmp1.data(), byteNum);
			}
			memcpy(&_return, tmp16.data(), byteNum);
			return true;
		}
		return false;
	}

	template<typename T>
	bool get_data(T& _return, const Uint8Array& buffer,
		uint16 offset_bytes, bool isLittle, bool isSwapByte)
	{
		return get_data(_return, buffer.data(), buffer.size(), offset_bytes, isLittle, isSwapByte);
	}

	// �жϱ�̨�����Ǵ���ֽ�����С���ֽ���
	bool isLittleEndian()
	{
		int iData = 1;
		char *p = (char*)&iData;
		if (*p == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}

	template <typename T>
	void swapBytes(T& var)
	{
		static_assert(std::is_pod<T>::value, "Type must be POD type for safety");
		std::array<char, sizeof(T)> varArray;
		std::memcpy(varArray.data(), &var, sizeof(T));
		for (int i = 0; i < static_cast<int>(sizeof(var) / 2); i++)
			std::swap(varArray[sizeof(var) - 1 - i], varArray[i]);
		std::memcpy(&var, varArray.data(), sizeof(T));
	}

	// ��int16,int32,int64,float,double��ת����16�����ֽ�����
	template<typename T>
	bool convertToBytesArray(Uint8Array& _return, const T value, bool isLittle, bool isSwapByte)
	{
		uint32 byteNum = sizeof(T);

		// ��T����(int16,int32,int64,float,double��)�����ݿ�����tmp8��
		Uint8Array tmp8(byteNum);
		Uint16Array tmp16(byteNum / 2);

		bool isLocalMachineLittleEndian = isLittleEndian();

		if (isLittle == isLocalMachineLittleEndian)	// �����С��
		{
			memcpy(tmp8.data(), &value, byteNum);
		} 
		else {
			memcpy(tmp8.data(), &value, byteNum);
			// ��С���ֽ���ת���ɴ���ֽ�����߽�����ֽ���ת����С���ֽ���
			std::reverse(tmp8.begin(), tmp8.end());
		}
		
		// �������ڵ������ֽ�
		memcpy(tmp16.data(), tmp8.data(), byteNum);
		if (isSwapByte)
		{
			std::reverse(tmp16.begin(), tmp16.end());
			Uint8Array tmp1(byteNum);
			memcpy(tmp1.data(), tmp16.data(), byteNum);
			std::reverse(tmp1.begin(), tmp1.end());
			memcpy(tmp16.data(), tmp1.data(), byteNum);
		}
		memcpy(tmp8.data(), tmp16.data(), byteNum);

		_return = tmp8;

		return true;
	}

	// c++��������ʽ�ж�ƥ���ַ����е�������ֵ������������С����������MFC�༭���ж���ֵ
	static bool isStrNumber(String strInput)
	{
		//����ƥ����ֵ�������� С�� ����
		std::string strPattern{ "-[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?" };
		std::regex re(strPattern);
		bool retMatchStr = false;

		retMatchStr = std::regex_match(strInput, re);

		return retMatchStr;
	}
};

