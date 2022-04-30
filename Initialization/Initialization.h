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
			static const bool EMPTY = false;
			static const bool EXIST = true;
		}
	}
	
	class Initialization
	{
		
	public:
	protected:
	private:
		static std::string default_string_;
		static unsigned int default_value_;
		
	public:
		// 반환 값
		//		성공 : 0
		//		실패 : GetLastError() 에러 코드.
		static DWORD Write(const std::string app_name, const std::string key_name, const std::string value, const std::string file_path);
		static DWORD Write(const std::string app_name, const std::string key_name, int value, const std::string file_path);
		
		
		
		// 반환 값
		//		문자열 길이.
		static DWORD Read(const std::string app_name, const std::string key_name, std::string& output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, char* output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, wchar_t* output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, wchar_t* output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, int* output, const std::string file_path);
		static DWORD Read(const std::string app_name, const std::string key_name, const int default_value_on_failure, int* output, const std::string file_path);
		
		
		
		static bool CheckValueIsEmpty(const std::string value, const std::string check_value);
		static bool CheckValueIsEmpty(const std::string value);
		static bool CheckValueIsEmpty(const char* const value, const std::string check_value);
		static bool CheckValueIsEmpty(const wchar_t* const value, const std::string check_value);
		static bool CheckValueIsEmpty(const wchar_t* const value);
		static bool CheckValueIsEmpty(const std::vector<std::string> value, const std::string check_value);
		static bool CheckValueIsEmpty(const std::vector<std::string> value);
		static bool CheckValueIsEmpty(const unsigned int value, const unsigned int check_value);
		static bool CheckValueIsEmpty(const unsigned int value);
		
		
		
		static const std::string getDefaultString();
		static void setDefaultString(const std::string fail_string);
		
		static unsigned int getDefaultValue();
		static void setDefaultValue(const unsigned int fail_value);
	protected:
	private:
	};
}
#endif	// _INITIALIZATION_H_