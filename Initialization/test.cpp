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
const int CUSTOM_DEFAULT_VALUE_ON_FAIL = -1;

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

#pragma region param char return char
	std::cout << "write return code : " << initialization.Write(APP_NAME_CHAR, KEY_NAME_CHAR, VALUE_CHAR, INI_FILE_NAME_CHAR) << std::endl;

	std::cout << std::endl;

	std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initialization.Read(APP_NAME_CHAR, "key name1", buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << initialization.Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion param char return char

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return wchar_t
	std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

	size_t new_size = (wcslen(buf_wchar_t) + 1) * 2;
	char* nstring = new char[new_size];
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if (initialization.getFailString().compare(convert_wchar_to_char) != 0)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initialization.Read(APP_NAME_CHAR, "key name1", buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;
	
	new_size = (wcslen(buf_wchar_t) + 1) * 2;
	nstring = new char[new_size];
	convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, buf_wchar_t, _TRUNCATE);

	convert_wchar_to_char = nstring;
	delete[] nstring;
	if (initialization.getFailString().compare(convert_wchar_to_char) != 0)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << initialization.Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

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
		std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion param char return wchar_t

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return string
	std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.getFailString().compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initialization.Read(APP_NAME_CHAR, "key name1", buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.getFailString().compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << initialization.Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
	if (initialization.getFailString().compare(buf_string) != 0)
	{
		std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion param char return string

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return vector
	std::cout << "write return code : " << initialization.Write(APP_NAME_VECTOR, KEY_NAME_VECTOR, VALUE_VECTOR, INI_FILE_NAME_CHAR) << std::endl;

	std::cout << std::endl;

	std::vector<std::string> buf_vector;
	std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << initialization.Read(APP_NAME_VECTOR, KEY_NAME_VECTOR, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	for (unsigned int i = 0; i < buf_vector.size(); i++)
	{
		std::cout << "param char return vector [" << buf_vector[i] << "]" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initialization.Read(APP_NAME_VECTOR, "key name1", ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	for (unsigned int i = 0; i < buf_vector.size(); i++)
	{
		std::cout << "param char return vector [" << buf_vector[i] << "]" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << initialization.Read(APP_NAME_VECTOR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	for (unsigned int i = 0; i < buf_vector.size(); i++)
	{
		std::cout << "param char return vector [" << buf_vector[i] << "]" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
	for (unsigned int i = 0; i < buf_vector.size(); i++)
	{
		std::cout << "param char return vector [" << buf_vector[i] << "]" << std::endl;
	}
#pragma endregion param char return vector

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param int
	std::cout << "write return code : " << initialization.Write(APP_NAME_INT, KEY_NAME_INT, VALUE_INT, INI_FILE_NAME_CHAR) << std::endl;

	if (initialization.Read(APP_NAME_INT, KEY_NAME_INT, INI_FILE_NAME_CHAR) == initialization.getFailValue())
	{
		std::cout << "read number return (������ ���) : ����ó�� �ʿ�." << std::endl;
	}
	else
	{
		std::cout << "read number return (������ ���) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, INI_FILE_NAME_CHAR) << std::endl;
	}

	std::cout << std::endl;

	if (initialization.Read(APP_NAME_INT, "key name1", INI_FILE_NAME_CHAR) == initialization.getFailValue())
	{
		std::cout << "read number return (���� �Ǵ� �׸��� ���� ���) : " << initialization.Read(APP_NAME_INT, "key name1", INI_FILE_NAME_CHAR) << " (����ó�� �ʿ�)" << std::endl;
	}
	else
	{
		std::cout << "read number return (���� �Ǵ� �׸��� ���� ���) : " << initialization.Read(APP_NAME_INT, "key name1", INI_FILE_NAME_CHAR) << std::endl;
	}

	std::cout << std::endl;

	if (initialization.Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, INI_FILE_NAME_CHAR) == CUSTOM_DEFAULT_VALUE_ON_FAIL)
	{
		std::cout << "read number return (���� �� Ŀ���� �� ����) : " << (int)initialization.Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, INI_FILE_NAME_CHAR) << " (����ó�� �ʿ�)" << std::endl;
	}
	else
	{
		std::cout << "read number return (���� �� Ŀ���� �� ����) : " << initialization.Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, INI_FILE_NAME_CHAR) << std::endl;
	}

	std::cout << std::endl;

	if (initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, INI_FILE_NAME_CHAR) == initialization.getFailValue())
	{
		std::cout << "read number return (���ڿ��� �� ���� ���� ���) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, INI_FILE_NAME_CHAR) << " (����ó�� �ʿ�)" << std::endl;
	}
	else
	{
		std::cout << "read number return (���ڿ��� �� ���� ���� ���) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, INI_FILE_NAME_CHAR) << "\n(���ڿ��� ���� �� ���� ���� ��� 0�� ���ϵǾ� fail_value�� 0 �̿��� �ٸ� ������ ������ ���� ��� ���� ó���� �ȵȴ�.)" << std::endl;
	}
#pragma endregion param int

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region set file path
	std::cout << "write return code : " << initialization.Write(APP_NAME_INT, KEY_NAME_INT, 777, "./temp.ini") << std::endl;
	std::cout << "write return code : " << initialization.Write(APP_NAME_CHAR, KEY_NAME_CHAR, "my input", "./temp.ini") << std::endl;

	std::cout << "read return code (������ ���) : " << initialization.Read(APP_NAME_CHAR, KEY_NAME_CHAR, buf_char, _countof(buf_char), "./temp.ini") << std::endl;
	if (initialization.getFailString().compare(buf_char) != 0)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	if (initialization.Read(APP_NAME_INT, KEY_NAME_INT, "./temp.ini") == initialization.getFailValue())
	{
		std::cout << "read number return (������ ���) : ����ó�� �ʿ�." << std::endl;
	}
	else
	{
		std::cout << "read number return (������ ���) : " << initialization.Read(APP_NAME_INT, KEY_NAME_INT, "./temp.ini") << std::endl;
	}
#pragma endregion set file path

	return EXIT_SUCCESS;
}