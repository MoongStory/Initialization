#include "Initialization.h"

// https://github.com/MoongStory/ConvertDataType
#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

#include <iostream>

const char* const INI_FILE_NAME_CHAR = "./test.ini";
const char* const DEFAULT_STRING_ON_FAIL_CHAR = "value is non exist char";
const int DEFAULT_VALUE_ON_FAIL = 30000;

const char* const APP_NAME_CHAR = "app name char";
const char* const KEY_NAME_CHAR = "key name char";
const char* const KEY_NAME_CHAR_EMPTY = "key name empty";
const char* const VALUE_CHAR = "temp string char";
const char* const VALUE_CHAR_EMPTY = "";

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
	char buf_char[1024] = { 0 };
	wchar_t buf_wchar_t[1024] = { 0 };
	std::string buf_string;
	std::string convert_wchar_to_char;
	int return_value = 0;

	try
	{
#pragma region param char return char
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_CHAR, KEY_NAME_CHAR, VALUE_CHAR, INI_FILE_NAME_CHAR) << std::endl;
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_CHAR, KEY_NAME_CHAR_EMPTY, VALUE_CHAR_EMPTY, INI_FILE_NAME_CHAR) << std::endl;

		std::cout << std::endl;

		std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR, "", buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
		if (strlen(buf_char) > 0)
		{
			std::cout << "param char return char [" << buf_char << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (�׸� �ְ� ���� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR_EMPTY, "", buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
		if (strlen(buf_char) > 0)
		{
			std::cout << "param char return char [" << buf_char << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, "key name1", "", buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
		if (strlen(buf_char) > 0)
		{
			std::cout << "param char return char [" << buf_char << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << MOONG::Initialization::Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
		if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(buf_char) != 0)
		{
			std::cout << "param char return char [" << buf_char << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_INT, KEY_NAME_INT, "", buf_char, _countof(buf_char), INI_FILE_NAME_CHAR) << std::endl;
		if (strlen(buf_char) > 0)
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
		std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR, "", buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

		convert_wchar_to_char = MOONG::ConvertDataType::wstring_to_string(buf_wchar_t);
		if (convert_wchar_to_char.length() > 0)
		{
			std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, "key name1", "", buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

		convert_wchar_to_char = MOONG::ConvertDataType::wstring_to_string(buf_wchar_t);
		if (convert_wchar_to_char.length() > 0)
		{
			std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return wchar_t [" << convert_wchar_to_char.c_str() << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << MOONG::Initialization::Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_wchar_t, _countof(buf_wchar_t), INI_FILE_NAME_CHAR) << std::endl;

		convert_wchar_to_char = MOONG::ConvertDataType::wstring_to_string(buf_wchar_t);
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
		std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR, "", buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_string.length() > 0)
		{
			std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, "key name1", "", buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_string.length() > 0)
		{
			std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << MOONG::Initialization::Read(APP_NAME_CHAR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
		if (CUSTOM_DEFAULT_STRING_ON_FAIL.compare(buf_string) != 0)
		{
			std::cout << "param char return string [" << buf_string.c_str() << "]" << std::endl;
		}
		else
		{
			std::cout << "param char return string [" << buf_string.c_str() << "] ���� ó�� �ʿ�" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_INT, KEY_NAME_INT, "", buf_string, 2048, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_string.length() > 0)
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
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_VECTOR, KEY_NAME_VECTOR, VALUE_VECTOR, INI_FILE_NAME_CHAR) << std::endl;

		std::cout << std::endl;

		std::vector<std::string> buf_vector;
		std::cout << "read return code (������ ���, �о���� ���ڿ��� ����) : " << MOONG::Initialization::Read(APP_NAME_VECTOR, KEY_NAME_VECTOR, "", ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_vector.size() > 0)
		{
			for (unsigned int i = 0; i < buf_vector.size(); i++)
			{
				std::cout << "param char return vector [" << buf_vector[i].c_str() << "]" << std::endl;
			}
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_VECTOR, "key name1", "", ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_vector.size() > 0)
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
				std::cout << "param char return vector [" << buf_vector[i].c_str() << "] ���� ó�� �ʿ�" << std::endl;
			}
		}

		std::cout << std::endl;

		std::cout << "read return code (���� �� Ŀ���� ���ڿ� ����) : " << MOONG::Initialization::Read(APP_NAME_VECTOR, "key name1", CUSTOM_DEFAULT_STRING_ON_FAIL, ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_vector.size() > 0)
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
				std::cout << "param char return vector [" << buf_vector[i].c_str() << "] ���� ó�� �ʿ�" << std::endl;
			}
		}

		std::cout << std::endl;

		std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_INT, KEY_NAME_INT, "", ";", buf_vector, 1024, INI_FILE_NAME_CHAR) << std::endl;
		if (buf_vector.size() > 0)
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
				std::cout << "param char return vector [" << buf_vector[i].c_str() << "] ���� ó�� �ʿ�" << std::endl;
			}
		}
#pragma endregion param char return vector

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

#pragma region param int
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_INT, KEY_NAME_INT, -1, INI_FILE_NAME_CHAR) << std::endl;
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_INT, "test000", "123456", INI_FILE_NAME_CHAR) << std::endl;
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_INT, "test001", "123a456", INI_FILE_NAME_CHAR) << std::endl;
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_INT, "test002", "a123456", INI_FILE_NAME_CHAR) << std::endl;

		std::cout << "read number return (������ ���) : " << MOONG::Initialization::Read(APP_NAME_INT, KEY_NAME_INT, 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (�׸� �ְ� ���� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR_EMPTY, 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (���� �Ǵ� �׸��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_INT, "key name1", 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (���� �� Ŀ���� �� ����) : " << MOONG::Initialization::Read(APP_NAME_INT, "key name1", CUSTOM_DEFAULT_VALUE_ON_FAIL, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != CUSTOM_DEFAULT_VALUE_ON_FAIL)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (���ڿ��� �� ���� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR, 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (���ڷθ� �̷���� ���ڿ��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_INT, "test000", 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (���� �߰��� ���ڰ� ���Ե� ���ڿ��� ���� ���) : " << MOONG::Initialization::Read(APP_NAME_INT, "test001", 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "read number return (�� �� ���� ������ ������ ���) : " << MOONG::Initialization::Read(APP_NAME_INT, "test002", 0, &return_value, INI_FILE_NAME_CHAR) << std::endl;
		if (return_value != 0)
		{
			std::cout << "return int[" << return_value << "]" << std::endl;
		}
		else
		{
			std::cout << "return int[" << return_value << "] (����ó�� �ʿ�)" << std::endl;
		}
#pragma endregion param int

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

#pragma region set file path
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_INT, KEY_NAME_INT, 777, "./temp.ini") << std::endl;
		std::cout << "write return code : " << MOONG::Initialization::Write(APP_NAME_CHAR, KEY_NAME_CHAR, "my input", "./temp.ini") << std::endl;

		std::cout << "read return code (������ ���) : " << MOONG::Initialization::Read(APP_NAME_CHAR, KEY_NAME_CHAR, "", buf_char, _countof(buf_char), "./temp.ini") << std::endl;
		if (strlen(buf_char) > 0)
		{
			std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
		}
		else
		{
			std::cout << "param wchar_t return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
		}

		MOONG::Initialization::Read(APP_NAME_INT, KEY_NAME_INT, 0, &return_value, "./temp.ini");
		if (return_value != 0)
		{
			std::cout << "read number return (������ ���) : " << return_value << std::endl;
		}
		else
		{
			std::cout << "read number return (������ ���) : ����ó�� �ʿ�." << std::endl;
		}
#pragma endregion set file path
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return EXIT_SUCCESS;
}