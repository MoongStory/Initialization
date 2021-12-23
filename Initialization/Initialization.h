// https://github.com/MoongStory/Initialization

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _INITIALIZATION_H_
#define _INITIALIZATION_H_

#include <atlstr.h>

namespace MOONG
{
	namespace INITIALIZATION
	{
		class Initialization
		{
		public:
			Initialization(const CStringA fail_string = "", const unsigned int fail_value = 0);

			// ��ȯ ��
			//		���� : 0
			//		���� : GetLastError() ���� �ڵ�.
			DWORD Write(CStringA file_path, CStringA app_name, CStringA key_name, CStringA value);
			DWORD Write(CStringA file_path, CStringA app_name, CStringA key_name, int value);



			// ��ȯ ��
			//		���ڿ� ����.
			DWORD Read(CStringA file_path, CStringA app_name, CStringA key_name, char* output, DWORD length_output);
			DWORD Read(CStringA file_path, CStringA app_name, CStringA key_name, wchar_t* output, DWORD length_output);

			// ��ȯ ��
			//		���� : ini ���Ͽ��� �о���� ��.
			//		���� : "Initialization" Ŭ���� ���� �� ������ "fail_value" ��.
			//				�������� �ʾҴٸ� ��� ������ ������ �Ķ���� �ʱ�ȭ ��.
			// "app_name"�� "key_name"�� ���������� ���� ���ڿ��� �����Ǿ� ���� ��� 0�� ��ȯ�ϹǷ� ������ ��.
			unsigned int Read(CStringA file_path, CStringA app_name, CStringA key_name);



			CStringA Get_fail_string();
			unsigned int Get_fail_value();

		private:
			void Set_fail_string(CStringA fail_string);
			void Set_fail_value(const unsigned int fail_value);
			
		public:

		private:
			CStringA fail_string_;
			unsigned int fail_value_;
		};
	}
}
#endif	// _INITIALIZATION_H_