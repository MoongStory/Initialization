// TODO: ini 파일 제어 클래스

#include "Initialization.h"

#include <iostream>

const char* const ini_file_name_char = "./test.ini";
const char* const default_string_char = "value is non exist char";

const char* const app_name_char = "app name char";
const char* const key_name_char = "key name char";
const char* const vlaue_char = "temp string char";

const std::string ini_file_name_string = "./test.ini";
const std::string default_string_string = "value is non exist string";

const std::string app_name_string = "app name string";
const std::string key_name_string = "key name string";
const std::string vlaue_string = "temp string string";

int main()
{
	MOONG::INITIALIZATION::Initialization initializationA(ini_file_name_char, default_string_char);

	char buf[1024] = { 0 };

#pragma region char
	std::cout << initializationA.Write(app_name_char, key_name_char, vlaue_char) << std::endl;

	initializationA.Read(app_name_char, key_name_char, buf, sizeof(buf));
	if (initializationA.Get_default_string().Compare(buf) != 0)
	{
		std::cout << "[" << buf << "]" << std::endl;
	}
	else
	{
		std::cout << "[값이 없음. 예외처리 필요.]" << std::endl;
	}

	initializationA.Read(app_name_char, "key name1", buf, sizeof(buf));
	if (initializationA.Get_default_string().Compare(buf) != 0)
	{
		std::cout << "[" << buf << "]" << std::endl;
	}
	else
	{
		std::cout << "[값이 없음. 예외처리 필요.]" << std::endl;
	}
#pragma endregion char

#pragma region string
	std::cout << initializationA.Write(app_name_string.c_str(), key_name_string.c_str(), vlaue_string.c_str()) << std::endl;

	initializationA.Read(app_name_string.c_str(), key_name_string.c_str(), buf, sizeof(buf));
	if (initializationA.Get_default_string().Compare(buf) != 0)
	{
		std::cout << "[" << buf << "]" << std::endl;
	}
	else
	{
		std::cout << "[값이 없음. 예외처리 필요.]" << std::endl;
	}

	initializationA.Read(app_name_string.c_str(), "key name1", buf, sizeof(buf));
	if (initializationA.Get_default_string().Compare(buf) != 0)
	{
		std::cout << "[" << buf << "]" << std::endl;
	}
	else
	{
		std::cout << "[값이 없음. 예외처리 필요.]" << std::endl;
	}
#pragma endregion string

	system("pause");

	return EXIT_SUCCESS;
}