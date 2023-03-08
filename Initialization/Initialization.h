/*******************************************************************************
MIT License

Copyright (c) 2023 Moong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

// https://github.com/MoongStory/Initialization

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _INITIALIZATION_H_
#define _INITIALIZATION_H_

#include <iostream>
#include <wtypes.h>
#include <vector>

#if _MSC_VER <= 1200
	// Visual Studio 6.0에서만 발생.
	#pragma warning(disable: 4786) // identifier was truncated to '255' characters in the browser information.
#endif

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
		static DWORD write(const std::string app_name, const std::string key_name, const std::string value, const std::string file_path);
		static DWORD write(const std::string app_name, const std::string key_name, int value, const std::string file_path);



		// 반환 값
		//		문자열 길이.
		static DWORD read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path);
		static DWORD read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path);
		static DWORD read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, wchar_t* output, DWORD length_output, const std::string file_path);
		static DWORD read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path);
		static DWORD read(const std::string app_name, const std::string key_name, const int default_value_on_failure, int* output, const std::string file_path);
	protected:
	private:
	};
}
#endif	// _INITIALIZATION_H_