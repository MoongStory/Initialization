#include "Initialization.h"

#include <iostream>

const char* const INI_FILE_NAME_CHAR = "./test.ini";
const char* const DEFAULT_STRING_ON_FAIL_CHAR = "value is non exist char";
const int DEFAULT_VALUE_ON_FAIL = 30000;

const char* const APP_NAME_CHAR = "app name char";
const char* const KEY_NAME_CHAR = "key name char";
const char* const VALUE_CHAR = "temp string char";

const char* const APP_NAME_VECTOR = "app name vector";
const char* const KEY_NAME_VECTOR = "key name Vector";
const char* const VALUE_VECTOR = "a;b;;d;e";

const std::string CUSTOM_DEFAULT_STRING_ON_FAIL = "custom default string on fail";
const int CUSTOM_DEFAULT_VALUE_ON_FAIL = 7777777;

const char* const APP_NAME_INT = "app name int";
const char* const KEY_NAME_INT = "key name int";
const int VALUE_INT = 20211219;

int main()
{
	//MOONG::INITIALIZATION::Initialization initialization(DEFAULT_STRING_ON_FAIL_CHAR, DEFAULT_VALUE_ON_FAIL);
	MOONG::INITIALIZATION::Initialization initialization;
	//MOONG::INITIALIZATION::Initialization initialization(fail_string_string.c_str(), fail_value);
	//MOONG::INITIALIZATION::Initialization initialization(fail_string_wchar_t, fail_value);

	char buf_char[1024] = { 0 };
	wchar_t buf_wchar_t[1024] = { 0 };
	std::string buf_string;
	std::string convert_wchar_to_char;
	int return_value = 0;

#pragma region param char return char
	std::cout << "write return code : " << initialization.Write(APP_NAME_CHAR, KEY_NAME_CHAR, VALUE_CHAR, INI_FILE_NAME_CHAR) << std::endl;

	std::cout << std::endl;

	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if(initialization.CheckValueIsEmpty(buf_char) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initialization.Read(APP_NAME_CHAR, "key name1", buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if(initialization.CheckValueIsEmpty(buf_char) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (실패 시 커스텀 문자열 지정) : " << initialization.Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (숫자로 설정 된 값 읽은 경우) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if(initialization.CheckValueIsEmpty(buf_char) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}
#pragma endregion param char return char

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return wchar_t
	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

	initialization.CheckValueIsEmpty(buf_wchar_t);

	size_t new_size = (wcslen(buf_wchar_t) + 1) * 2;
	char* nstring = new char[new_size];
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if(initialization.CheckValueIsEmpty(convert_wchar_to_char) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initialization.Read(APP_NAME_CHAR, "key name1", buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

	initialization.CheckValueIsEmpty(buf_wchar_t);
	
	new_size = (wcslen(buf_wchar_t) + 1) * 2;
	nstring = new char[new_size];
	convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if(initialization.CheckValueIsEmpty(convert_wchar_to_char) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (실패 시 커스텀 문자열 지정) : " << initialization.Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

	initialization.CheckValueIsEmpty(buf_wchar_t);

	new_size = (wcslen(buf_wchar_t) + 1) * 2;
	nstring = new char[new_size];
	convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(convert_wchar_to_char) != 0)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] 예외 처리 필요" << std::endl;
	}
#pragma endregion param char return wchar_t

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return string
	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if(initialization.CheckValueIsEmpty(buf_string) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initialization.Read(APP_NAME_CHAR, "key name1", buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if(initialization.CheckValueIsEmpty(buf_string) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (실패 시 커스텀 문자열 지정) : " << initialization.Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (숫자로 설정 된 값 읽은 경우) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if(initialization.CheckValueIsEmpty(buf_string) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] 예외 처리 필요" << std::endl;
	}
#pragma endregion param char return string

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return vector
	std::cout << "write return code : " << initialization.Write(APP_NAME_VECTOR, KEY_NAME_VECTOR, VALUE_VECTOR, INI_FILE_NAME_CHAR) << std::endl;

	std::cout << std::endl;

	std::vector<std::string> buf_vector;
	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initialization.Read(APP_NAME_VECTOR, KEY_NAME_VECTOR, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.CheckValueIsEmpty(buf_vector) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "]" << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initialization.Read(APP_NAME_VECTOR, "key name1", ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.CheckValueIsEmpty(buf_vector) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "]" << std::endl;
		}
	}
	else
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "] 예외 처리 필요" << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << "read return code (실패 시 커스텀 문자열 지정) : " << initialization.Read(APP_NAME_VECTOR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.CheckValueIsEmpty(buf_vector, CUSTOM_DEFAULT_STRING_ON_FAIL) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "]" << std::endl;
		}
	}
	else
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "] 예외 처리 필요" << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << "read return code (숫자로 설정 된 값 읽은 경우) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.CheckValueIsEmpty(buf_vector) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "]" << std::endl;
		}
	}
	else
	{
		for (unsigned int i = 0; i < buf_vector.size(); i++)
		{
			std::cout << "param char return vector [" << buf_vector[i].c_str() << "] 예외 처리 필요" << std::endl;
		}
	}
#pragma endregion param char return vector

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param int
	std::cout << "write return code : " << initialization.Write(APP_NAME_INT, KEY_NAME_INT, VALUE_INT, INI_FILE_NAME_CHAR) << std::endl;

	return_value = initialization.Read(APP_NAME_INT, KEY_NAME_INT, INI_FILE_NAME_CHAR);
	if(initialization.CheckValueIsEmpty(return_value) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "read number return (정상인 경우) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, INI_FILE_NAME_CHAR) << std::endl;
	}
	else
	{
		std::cout << "read number return (정상인 경우) : 예외처리 필요." << std::endl;
	}

	std::cout << std::endl;

	return_value = initialization.Read(APP_NAME_INT, "key name1", INI_FILE_NAME_CHAR);
	if(initialization.CheckValueIsEmpty(return_value) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "read number return (섹션 또는 항목이 없는 경우) : " << initialization.Read(APP_NAME_INT, "key name1", INI_FILE_NAME_CHAR) << std::endl;
	}
	else
	{
		std::cout << "read number return (섹션 또는 항목이 없는 경우) : " << initialization.Read(APP_NAME_INT, "key name1", INI_FILE_NAME_CHAR) << " (예외처리 필요)" << std::endl;
	}

	std::cout << std::endl;

	return_value = initialization.Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, INI_FILE_NAME_CHAR);
	if(initialization.CheckValueIsEmpty(return_value, CUSTOM_DEFAULT_VALUE_ON_FAIL) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "read number return (실패 시 커스텀 값 지정) : " << initialization.Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, INI_FILE_NAME_CHAR) << std::endl;
	}
	else
	{
		std::cout << "read number return (실패 시 커스텀 값 지정) : " << (int)initialization.Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, INI_FILE_NAME_CHAR) << " (예외처리 필요)" << std::endl;
	}

	std::cout << std::endl;

	return_value = initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, INI_FILE_NAME_CHAR);
	if(initialization.CheckValueIsEmpty(return_value) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "read number return (문자열로 된 값을 읽은 경우) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, INI_FILE_NAME_CHAR) << "\n(문자열로 설정 된 값을 읽을 경우 0이 리턴되어 fail_value를 0 이외의 다른 값으로 설정해 놓은 경우 예외 처리가 안된다.)" << std::endl;
	}
	else
	{
		std::cout << "read number return (문자열로 된 값을 읽은 경우) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, INI_FILE_NAME_CHAR) << "\n(문자열로 설정 된 값을 읽을 경우 0이 리턴되어 fail_value를 0 이외의 다른 값으로 설정해 놓은 경우 예외 처리가 안된다.)" << std::endl;
	}
#pragma endregion param int

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region set file path
	std::cout << "write return code : " << initialization.Write(APP_NAME_INT, KEY_NAME_INT, 777, "./temp.ini") << std::endl;
	std::cout << "write return code : " << initialization.Write(APP_NAME_CHAR, KEY_NAME_CHAR, "my input", "./temp.ini") << std::endl;

	std::cout << "read return code (정상인 경우) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_char, _countof(buf_char), "./temp.ini") << std::endl;
	if(initialization.CheckValueIsEmpty(buf_char) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	return_value = initialization.Read(APP_NAME_INT, KEY_NAME_INT, "./temp.ini");
	if(initialization.CheckValueIsEmpty(return_value) == MOONG::INITIALIZATION::CHECK_VALUE::EXIST)
	{
		std::cout << "read number return (정상인 경우) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, "./temp.ini") << std::endl;
	}
	else
	{
		std::cout << "read number return (정상인 경우) : 예외처리 필요." << std::endl;
	}
#pragma endregion set file path

	return EXIT_SUCCESS;
}