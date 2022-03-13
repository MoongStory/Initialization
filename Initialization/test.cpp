#include "Initialization.h"

#include <iostream>

const char* const ini_file_name_char = "./test.ini";
const char* const fail_string_char = "value is non exist char";
const int fail_value = 30000;

const char* const app_name_char = "app name char";
const char* const key_name_char = "key name char";
const char* const value_char = "temp string char";

const std::string ini_file_name_string = "./test.ini";
const std::string fail_string_string = "value is non exist string";

const std::string app_name_string = "app name string";
const std::string key_name_string = "key name string";
const std::string value_string = "temp string string";

const char* const app_name_int = "app name int";
const char* const key_name_int = "key name int";
const int value_int = 20211219;

int main()
{
	MOONG::INITIALIZATION::Initialization initializationA(fail_string_char, fail_value);
	//MOONG::INITIALIZATION::Initialization initializationA();
	//MOONG::INITIALIZATION::Initialization initializationA(fail_string_string.c_str(), fail_value);
	//MOONG::INITIALIZATION::Initialization initializationA(fail_string_wchar_t, fail_value);

	char buf_char[1024] = { 0 };
	wchar_t buf_wchar_t[1024] = { 0 };
	std::string buf_string;
	std::string convert_wchar_to_char;

#pragma region param char return char
	std::cout << "write return code : " << initializationA.Write(app_name_char, key_name_char, value_char, ini_file_name_char) << std::endl;

	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initializationA.Read(app_name_char, key_name_char, buf_char, _countof(buf_char), ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_char, "key name1", buf_char, _countof(buf_char), ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (숫자로 설정 된 값 읽은 경우) : " << initializationA.Read(app_name_int, key_name_int, buf_char, _countof(buf_char), ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_char) != 0)
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

#pragma region param string return char
	std::cout << "write return code : " << initializationA.Write(app_name_string.c_str(), key_name_string.c_str(), value_string.c_str(), ini_file_name_char) << std::endl;

	std::cout << "read return code : (정상인 경우, 읽어들인 문자열의 길이) " << initializationA.Read(app_name_string.c_str(), key_name_string.c_str(), buf_char, _countof(buf_char), ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param string return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param string return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_string.c_str(), "key name1", buf_char, _countof(buf_char), ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param string return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param string return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}
#pragma endregion param string return char

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return wchar_t
	std::cout << "write return code : " << initializationA.Write(app_name_char, key_name_char, value_char, ini_file_name_char) << std::endl;

	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initializationA.Read(app_name_char, key_name_char, buf_wchar_t, _countof(buf_wchar_t), ini_file_name_char) << std::endl;

	size_t new_size = (wcslen(buf_wchar_t) + 1) * 2;
	char* nstring = new char[new_size];
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if (initializationA.getFailString() != convert_wchar_to_char)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_char, "key name1", buf_wchar_t, _countof(buf_wchar_t), ini_file_name_char) << std::endl;
	
	new_size = (wcslen(buf_wchar_t) + 1) * 2;
	nstring = new char[new_size];
	convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if (initializationA.getFailString() != convert_wchar_to_char)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "] 예외 처리 필요" << std::endl;
	}
#pragma endregion param char return wchar_t

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return string
	std::cout << "write return code : " << initializationA.Write(app_name_char, key_name_char, value_char, ini_file_name_char) << std::endl;

	std::cout << "read return code (정상인 경우, 읽어들인 문자열의 길이) : " << initializationA.Read(app_name_char, key_name_char, buf_string, 2048, ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_char, "key name1", buf_string, 2048, ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] 예외 처리 필요" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (숫자로 설정 된 값 읽은 경우) : " << initializationA.Read(app_name_int, key_name_int, buf_string, 2048, ini_file_name_char) << std::endl;
	if (initializationA.getFailString().compare(buf_string) != 0)
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

#pragma region param int
	std::cout << "write return code : " << initializationA.Write(app_name_int, key_name_int, value_int, ini_file_name_char) << std::endl;

	if (initializationA.Read(ini_file_name_char, app_name_int, key_name_int) == initializationA.getFailValue())
	{
		std::cout << "read number return (정상인 경우) : 예외처리 필요." << std::endl;
	}
	else
	{
		std::cout << "read number return (정상인 경우) : " << initializationA.Read(app_name_int, key_name_int, ini_file_name_char) << std::endl;
	}

	std::cout << std::endl;

	if (initializationA.Read(app_name_int, "key name1", ini_file_name_char) == initializationA.getFailValue())
	{
		std::cout << "read number return (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_int, "key name1", ini_file_name_char) << " (예외처리 필요)" << std::endl;
	}
	else
	{
		std::cout << "read number return (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_int, "key name1", ini_file_name_char) << std::endl;
	}

	std::cout << std::endl;

	if (initializationA.Read(app_name_char, key_name_char, ini_file_name_char) == initializationA.getFailValue())
	{
		std::cout << "read number return (섹션 또는 항목이 없는 경우) : " << initializationA.Read(app_name_char, key_name_char, ini_file_name_char) << " (예외처리 필요)" << std::endl;
	}
	else
	{
		std::cout << "read number return (문자열로 된 값을 읽은 경우) : " << initializationA.Read(app_name_char, key_name_char, ini_file_name_char) << "\n(문자열로 설정 된 값을 읽을 경우 0이 리턴되어 fail_value를 0 이외의 다른 값으로 설정해 놓은 경우 예외 처리가 안된다.)" << std::endl;
	}
#pragma endregion param int

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region set file path
	std::cout << "write return code : " << initializationA.Write(app_name_int, key_name_int, 777, "./temp.ini") << std::endl;
	std::cout << "write return code : " << initializationA.Write(app_name_char, key_name_char, "my input", "./temp.ini") << std::endl;

	std::cout << "read return code (정상인 경우) : " << initializationA.Read(app_name_char, key_name_char, buf_char, _countof(buf_char), "./temp.ini") << std::endl;
	if (initializationA.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [" << buf_char << "] 예외 처리 필요" << std::endl;
	}

	if (initializationA.Read(app_name_int, key_name_int, "./temp.ini") == initializationA.getFailValue())
	{
		std::cout << "read number return (정상인 경우) : 예외처리 필요." << std::endl;
	}
	else
	{
		std::cout << "read number return (정상인 경우) : " << initializationA.Read(app_name_int, key_name_int, "./temp.ini") << std::endl;
	}
#pragma endregion set file path

	return EXIT_SUCCESS;
}