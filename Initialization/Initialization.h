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

	public:
		// 반환 값
		//		성공 : 0
		//		실패 : GetLastError() 에러 코드.
		static DWORD Write(const std::string app_name, const std::string key_name, const std::string value, const std::string file_path);
		static DWORD Write(const std::string app_name, const std::string key_name, int value, const std::string file_path);



		// 반환 값
		//		문자열 길이.
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path) noexcept(false);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path) noexcept(false);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, wchar_t* output, DWORD length_output, const std::string file_path) noexcept(false);
		static DWORD Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path) noexcept(false);
		static DWORD Read(const std::string app_name, const std::string key_name, const int default_value_on_failure, int* output, const std::string file_path) noexcept(false);
	protected:
	private:
	};
}
#endif	// _INITIALIZATION_H_