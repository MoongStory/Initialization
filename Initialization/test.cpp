// TODO: ini ���� ���� Ŭ����

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

const wchar_t* const ini_file_name_wchar_t = L"./test.ini";
const wchar_t* const fail_string_wchar_t = L"value is non exist wchar_t";

const wchar_t* const app_name_wchar_t = L"app name wchar_t";
const wchar_t* const key_name_wchar_t = L"key name wchar_t";
const wchar_t* const value_wchar_t = L"temp string wchar_t";

const char* const app_name_int = "app name int";
const char* const key_name_int = "key name int";
const int value_int = 20211219;

int main()
{
	MOONG::INITIALIZATION::Initialization initializationA(ini_file_name_char, fail_string_char, fail_value);
	//MOONG::INITIALIZATION::Initialization initializationA(ini_file_name_char);
	//MOONG::INITIALIZATION::Initialization initializationA(ini_file_name_string.c_str(), fail_string_string.c_str(), fail_value);
	//MOONG::INITIALIZATION::Initialization initializationA(ini_file_name_wchar_t, fail_string_wchar_t, fail_value);

	char buf_char[1024] = { 0 };
	wchar_t buf_wchar_t[1024] = { 0 };
	CStringA convert_wchar_to_char;

#pragma region param char return char
	std::cout << "write return code : " << initializationA.Write(app_name_char, key_name_char, value_char) << std::endl;

	std::cout << "read return code (������ ���) : " << initializationA.Read(app_name_char, key_name_char, buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_char, "key name1", buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
	{
		std::cout << "param char return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���ڷ� ���� �� �� ���� ���) : " << initializationA.Read(app_name_int, key_name_int, buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
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

#pragma region param string return char
	std::cout << "write return code : " << initializationA.Write(app_name_string.c_str(), key_name_string.c_str(), value_string.c_str()) << std::endl;

	std::cout << "read return code : (������ ���) " << initializationA.Read(app_name_string.c_str(), key_name_string.c_str(), buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
	{
		std::cout << "param string return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param string return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_string.c_str(), "key name1", buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
	{
		std::cout << "param string return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param string return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion param string return char

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param wchar_t return char
	std::cout << "write return code : " << initializationA.Write(app_name_wchar_t, key_name_wchar_t, value_wchar_t) << std::endl;

	std::cout << "read return code (������ ���) : " << initializationA.Read(app_name_wchar_t, key_name_wchar_t, buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_wchar_t, "key name1", buf_char, _countof(buf_char)) << std::endl;
	if (initializationA.Get_fail_string().Compare(buf_char) != 0)
	{
		std::cout << "param wchar_t return char [" << buf_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return char [" << buf_char << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion char

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param char return wchar_t
	std::cout << "write return code : " << initializationA.Write(app_name_char, key_name_char, value_char) << std::endl;

	std::cout << "read return code (������ ���) : " << initializationA.Read(app_name_char, key_name_char, buf_wchar_t, _countof(buf_wchar_t)) << std::endl;
	convert_wchar_to_char = buf_wchar_t;
	if (initializationA.Get_fail_string() != convert_wchar_to_char)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_char, "key name1", buf_wchar_t, _countof(buf_wchar_t)) << std::endl;
	convert_wchar_to_char = buf_wchar_t;
	if (initializationA.Get_fail_string() != convert_wchar_to_char)
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param char return wchar_t [" << convert_wchar_to_char << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion param char return wchar_t

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param wchar_t return wchar_t
	std::cout << "write return code : " << initializationA.Write(app_name_wchar_t, key_name_wchar_t, value_wchar_t) << std::endl;

	std::cout << "read return code (������ ���) : " << initializationA.Read(app_name_wchar_t, key_name_wchar_t, buf_wchar_t, _countof(buf_wchar_t)) << std::endl;
	convert_wchar_to_char = buf_wchar_t;
	if (initializationA.Get_fail_string() != convert_wchar_to_char)
	{
		std::cout << "param wchar_t return wchar_t [" << convert_wchar_to_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return wchar_t [" << convert_wchar_to_char << "] ���� ó�� �ʿ�" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "read return code (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_wchar_t, L"key name1", buf_wchar_t, _countof(buf_wchar_t)) << std::endl;
	convert_wchar_to_char = buf_wchar_t;
	if (initializationA.Get_fail_string() != convert_wchar_to_char)
	{
		std::cout << "param wchar_t return wchar_t [" << convert_wchar_to_char << "]" << std::endl;
	}
	else
	{
		std::cout << "param wchar_t return wchar_t [" << convert_wchar_to_char << "] ���� ó�� �ʿ�" << std::endl;
	}
#pragma endregion param wchar_t return wchar_t

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

#pragma region param int
	std::cout << "write return code : " << initializationA.Write(app_name_int, key_name_int, value_int) << std::endl;

	if (initializationA.Read(app_name_int, key_name_int) == initializationA.Get_fail_value())
	{
		std::cout << "read number return (������ ���) : ����ó�� �ʿ�." << std::endl;
	}
	else
	{
		std::cout << "read number return (������ ���) : " << initializationA.Read(app_name_int, key_name_int) << std::endl;
	}

	std::cout << std::endl;

	if (initializationA.Read(app_name_int, "key name1") == initializationA.Get_fail_value())
	{
		std::cout << "read number return (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_int, "key name1") << " (����ó�� �ʿ�)" << std::endl;
	}
	else
	{
		std::cout << "read number return (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_int, "key name1") << std::endl;
	}

	std::cout << std::endl;

	if (initializationA.Read(app_name_char, key_name_char) == initializationA.Get_fail_value())
	{
		std::cout << "read number return (���� �Ǵ� �׸��� ���� ���) : " << initializationA.Read(app_name_char, key_name_char) << " (����ó�� �ʿ�)" << std::endl;
	}
	else
	{
		std::cout << "read number return (���ڿ��� �� ���� ���� ���) : " << initializationA.Read(app_name_char, key_name_char) << "\n(���ڿ��� ���� �� ���� ���� ��� 0�� ���ϵǾ� fail_value�� 0 �̿��� �ٸ� ������ ������ ���� ��� ���� ó���� �ȵȴ�.)" << std::endl;
	}
#pragma endregion param int

	return EXIT_SUCCESS;
}