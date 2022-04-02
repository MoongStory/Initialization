// https://github.com/MoongStory/Initialization

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _INITIALIZATION_H_
#define _INITIALIZATION_H_

#include <iostream>
#include <wtypes.h>
#include <vector>

namespace MOONG
{
	namespace INITIALIZATION
	{
		namespace CHECK_VALUE
		{
			const bool EMPTY = false;
			const bool EXIST = true;
		};

		class Initialization
		{
		public:
			Initialization(const std::string default_string = "999999999", const unsigned int default_value = 999999999);

			// 반환 값
			//		성공 : 0
			//		실패 : GetLastError() 에러 코드.
			DWORD Write(const std::string app_name, const std::string key_name, const std::string value, const std::string file_path) const;
			DWORD Write(const std::string app_name, const std::string key_name, int value, const std::string file_path) const;



			// 반환 값
			//		문자열 길이.
			DWORD Read(const std::string app_name, const std::string key_name, std::string& output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, char* output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, wchar_t* output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, wchar_t* output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path) const;
			DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path) const;

			// 반환 값
			//		성공 : ini 파일에서 읽어들인 값.
			//		실패 : "Initialization" 클래스 생성 시 설정한 "fail_value" 값.
			//				설정하지 않았다면 헤더 파일의 생성자 파라미터 초기화 값.
			// "app_name"과 "key_name"이 존재하지만 값이 문자열로 설정되어 있을 경우 0을 반환하므로 주의할 것.
			unsigned int Read(const std::string app_name, const std::string key_name, const std::string file_path) const;
			unsigned int Read(const std::string app_name, const std::string key_name, const int default_value_on_failure, const std::string file_path) const;

			

			bool CheckValueIsEmpty(const std::string value, const std::string check_value) const;
			bool CheckValueIsEmpty(const std::string value) const;
			bool CheckValueIsEmpty(const char* const value, const std::string check_value) const;
			bool CheckValueIsEmpty(const wchar_t* const value, const std::string check_value) const;
			bool CheckValueIsEmpty(const wchar_t* const value) const;
			bool CheckValueIsEmpty(const std::vector<std::string> value, const std::string check_value) const;
			bool CheckValueIsEmpty(const std::vector<std::string> value) const;
			bool CheckValueIsEmpty(const unsigned int value, const unsigned int check_value) const;
			bool CheckValueIsEmpty(const unsigned int value) const;
		private:
			const std::string getDefaultString() const;
			void setDefaultString(const std::string fail_string);
			
			unsigned int getDefaultValue() const;
			void setDefaultValue(const unsigned int fail_value);
			
		public:

		private:
			std::string default_string_;
			unsigned int default_value_;
		};
	}
}
#endif	// _INITIALIZATION_H_