// TODO: ini 파일 제어 클래스

#include "Initialization.h"

#include <iostream>

const char* const ini_file_name_char = "./test.ini";
const char* const default_string_char = "value is non exist char";

const char* const app_name_char = "app name char";
const char* const key_name_char = "key name char";
const char* const value_char = "temp string char";

const std::string ini_file_name_string = "./test.ini";
const std::string default_string_string = "value is non exist string";

const std::string app_name_string = "app name string";
const std::string key_name_string = "key name string";
const std::string value_string = "temp string string";

const wchar_t* const ini_file_name_wchar_t = L"./test.ini";
const wchar_t* const default_string_wchar_t = L"value is non exist wchar_t";

const wchar_t* const app_name_wchar_t = L"app name wchar_t";
const wchar_t* const key_name_wchar_t = L"key name wchar_t";
const wchar_t* const value_wchar_t = L"temp string wchar_t";

const char* const app_name_int = "app name int";
const char* const key_name_int = "key name int";
const int value_int = 20211219;

int main()
{
	MOONG::INITIALIZATION::Initialization initializationA(ini_file_name_char, default_string_char);

	char buf_char[1024] = { 0 };
	wchar_t buf_wchar_t[1024] = { 0 };

#pragma region param char return char
	std::cout << "return code : " << initializationA.Write(app_name_char, key_name_char, value_char) << std::endl;

	initializationA.Read(app_name_char, key_name_char, buf_char, _countof(buf_char));
	if (initializationA.Get_default_string().Compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [값이 없음. 예외처리 필요.]" << std::endl;
	}

	initializationA.Read(app_name_char, "key name1", buf_char, _countof(buf_char));
	if (initializationA.Get_default_string().Compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [값이 없음. 예외처리 필요.]" << std::endl;
	}
#pragma endregion param char return char

#pragma region param string return char
	std::cout << "return code : " << initializationA.Write(app_name_string.c_str(), key_name_string.c_str(), value_string.c_str()) << std::endl;

	initializationA.Read(app_name_string.c_str(), key_name_string.c_str(), buf_char, _countof(buf_char));
	if (initializationA.Get_default_string().Compare(buf_char) != 0)
	{
		std::cout << "param string return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param string return char [값이 없음. 예외처리 필요.]" << std::endl;
	}

	initializationA.Read(app_name_string.c_str(), "key name1", buf_char, _countof(buf_char));
	if (initializationA.Get_default_string().Compare(buf_char) != 0)
	{
		std::cout << "param string return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param string return char [값이 없음. 예외처리 필요.]" << std::endl;
	}
#pragma endregion param string return char

#pragma region param wchar_t return char
	std::cout << "return code : " << initializationA.Write(app_name_wchar_t, key_name_wchar_t, value_wchar_t) << std::endl;

	initializationA.Read(app_name_wchar_t, key_name_wchar_t, buf_char, _countof(buf_char));
	if (initializationA.Get_default_string().Compare(buf_char) != 0)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [값이 없음. 예외처리 필요.]" << std::endl;
	}

	initializationA.Read(app_name_wchar_t, "key name1", buf_char, _countof(buf_char));
	if (initializationA.Get_default_string().Compare(buf_char) != 0)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [값이 없음. 예외처리 필요.]" << std::endl;
	}
#pragma endregion char

#pragma region param char return wchar_t
	std::cout << "return code : " << initializationA.Write(app_name_char, key_name_char, value_char) << std::endl;

	initializationA.Read(app_name_char, key_name_char, buf_wchar_t, _countof(buf_wchar_t));
	CStringA temp(buf_wchar_t);
	if (initializationA.Get_default_string() != temp)
	{
		std::cout << "param char return wchar_t [" << temp << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t[값이 없음. 예외처리 필요.]" << std::endl;
	}

	initializationA.Read(app_name_char, "key name1", buf_wchar_t, _countof(buf_wchar_t));
	temp = buf_wchar_t;
	if (initializationA.Get_default_string() != temp)
	{
		std::cout << "param char return wchar_t [" << temp << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [값이 없음. 예외처리 필요.]" << std::endl;
	}
#pragma endregion param char return wchar_t

#pragma region param int
	initializationA.Write(app_name_int, key_name_int, value_int);
#pragma endregion param int

	return EXIT_SUCCESS;
}