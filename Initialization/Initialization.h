// https://github.com/MoongStory/Initialization

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _INITIALIZATION_H_
#define _INITIALIZATION_H_

#include <iostream>
#include <wtypes.h>

namespace MOONG
{
	namespace INITIALIZATION
	{
		class Initialization
		{
		public:
			Initialization(const std::string fail_string = "", const unsigned int fail_value = 0);

			// ��ȯ ��
			//		���� : 0
			//		���� : GetLastError() ���� �ڵ�.
			DWORD Write(const std::string file_path, const std::string app_name, const std::string key_name, const std::string value) const;
			DWORD Write(const std::string file_path, const std::string app_name, const std::string key_name, int value) const;



			// ��ȯ ��
			//		���ڿ� ����.
			DWORD Read(const std::string file_path, const std::string app_name, const std::string key_name, char* output, DWORD length_output) const;
			DWORD Read(const std::string file_path, const std::string app_name, const std::string key_name, wchar_t* output, DWORD length_output) const;

			// ��ȯ ��
			//		���� : ini ���Ͽ��� �о���� ��.
			//		���� : "Initialization" Ŭ���� ���� �� ������ "fail_value" ��.
			//				�������� �ʾҴٸ� ��� ������ ������ �Ķ���� �ʱ�ȭ ��.
			// "app_name"�� "key_name"�� ���������� ���� ���ڿ��� �����Ǿ� ���� ��� 0�� ��ȯ�ϹǷ� ������ ��.
			unsigned int Read(const std::string file_path, const std::string app_name, const std::string key_name) const;



			const std::string getFailString() const;
			unsigned int getFailValue() const;

		private:
			void setFailString(const std::string fail_string);
			void setFailValue(const unsigned int fail_value);
			
		public:

		private:
			std::string fail_string_;
			unsigned int fail_value_;
		};
	}
}
#endif	// _INITIALIZATION_H_