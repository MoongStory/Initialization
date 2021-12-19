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
			Initialization(const CStringA ini_file_path, const CStringA fail_string = "", const UINT fail_value = 0);

			// ��ȯ ��
			//		���ڿ� ����.
			DWORD Read(CStringA app_name, CStringA key_name, char* output, DWORD length_output);
			DWORD Read(CStringA app_name, CStringA key_name, wchar_t* output, DWORD length_output);

			// ��ȯ ��
			//		���� : ini ���Ͽ��� �о���� ��.
			//		���� : "Initialization" Ŭ���� ���� �� ������ "fail_value" ��.
			//				�������� �ʾҴٸ� ��� ������ ������ �Ķ���� �ʱ�ȭ ��.
			// "app_name"�� "key_name"�� ���������� ���� ���ڿ��� �����Ǿ� ���� ��� 0�� ��ȯ�ϹǷ� ������ ��.
			UINT Read(CStringA app_name, CStringA key_name);



			// ��ȯ ��
			//		���� : 0
			//		���� : GetLastError() ���� �ڵ�.
			DWORD Write(CStringA app_name, CStringA key_name, CStringA value);
			DWORD Write(CStringA app_name, CStringA key_name, int value);



			CStringA Get_fail_string();
			UINT Get_fail_value();

		private:
			CStringA Get_ini_file_path();
			void Set_ini_file_path(CStringA ini_file_path);

			void Set_fail_string(CStringA fail_string);
			void Set_fail_value(const UINT fail_value);
			
		public:

		private:
			CStringA ini_file_path_;
			CStringA fail_string_;
			UINT fail_value_;
		};
	}
}
#endif	// _INITIALIZATION_H_