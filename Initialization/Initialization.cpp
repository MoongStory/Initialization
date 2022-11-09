#include "Initialization.h"

#include <sstream>
#include <strsafe.h>

// https://github.com/MoongStory/ConvertDataType
#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

DWORD MOONG::Initialization::Write(const std::string app_name, const std::string key_name, const std::string value, const std::string file_path) noexcept(false)
{
	if (WritePrivateProfileStringA(app_name.c_str(), key_name.c_str(), value.c_str(), file_path.c_str()) == 0)
	{
		throw MOONG::ExceptionFunctionCallFailed();
	}

	return EXIT_SUCCESS;
}

DWORD MOONG::Initialization::Write(const std::string app_name, const std::string key_name, int value, const std::string file_path) noexcept(false)
{
	std::ostringstream convert_string;
	convert_string << value;

	try
	{
		return MOONG::Initialization::Write(app_name, key_name, convert_string.str(), file_path);
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}



DWORD MOONG::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path) noexcept(false)
{
	try
	{
		char* buf = new char[length_output];

		DWORD return_value = MOONG::Initialization::Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

		output = buf;

		delete[] buf;

		return return_value;
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

DWORD MOONG::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path) noexcept(false)
{
	try
	{
		char* buf = new char[length_output];

		DWORD return_value = GetPrivateProfileStringA(app_name.c_str(), key_name.c_str(), default_string_on_failure.c_str(), buf, length_output, file_path.c_str());

		if (strlen(buf) == 0)
		{
			return_value = (DWORD)(default_string_on_failure.length());

			StringCchCopyA(output, length_output, default_string_on_failure.c_str());
		}
		else
		{
			StringCchCopyA(output, length_output, buf);
		}

		delete[] buf;

		return return_value;
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

DWORD MOONG::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, wchar_t* output, DWORD length_output, const std::string file_path) noexcept(false)
{
	try
	{
		char* buf = new char[length_output];

		DWORD return_value = MOONG::Initialization::Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

		StringCchCopyW(output, length_output, MOONG::ConvertDataType::string_to_wstring(buf).c_str());

		delete[] buf;

		return return_value;
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

DWORD MOONG::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string delimiters, std::vector<std::string>& output, DWORD length_output, const std::string file_path) noexcept(false)
{
	try
	{
		output.clear();

		std::string buf;
		DWORD return_value = MOONG::Initialization::Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

		char* token = NULL;
#if _MSC_VER > 1200
		char* next_token = NULL;

		token = strtok_s((char*)(buf.c_str()), delimiters.c_str(), &next_token);

		while (token != NULL)
		{
			// Get next token:
			if (token != NULL)
			{
				output.push_back(token);

				token = strtok_s(NULL, delimiters.c_str(), &next_token);
			}
		}
#else
		token = strtok((char*)(buf.c_str()), delimiters.c_str());

		while (token != NULL)
		{
			output.push_back(token);

			// Get next token:
			token = strtok(NULL, delimiters.c_str()); // C4996
		}
#endif

		return return_value;
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

DWORD MOONG::Initialization::Read(const std::string app_name, const std::string key_name, const int default_value_on_failure, int* output, const std::string file_path) noexcept(false)
{
	try
	{
		std::string buf;

		std::ostringstream default_string_on_failure;
		default_string_on_failure << default_value_on_failure;

		DWORD return_value = MOONG::Initialization::Read(app_name.c_str(), key_name.c_str(), default_string_on_failure.str(), buf, 64, file_path.c_str());

		for (unsigned int i = 0; i < buf.length(); i++)
		{
			if (i == 0 && buf[i] == '-')
			{
				continue;
			}

			if (buf[i] < '0' || buf[i] > '9')
			{
				*output = default_value_on_failure;

				return_value = 0;

				for (int i = 1; (default_value_on_failure / i) >= 1; i *= 10)
				{
					return_value++;
				}

				if (return_value == 0)
				{
					return_value = 1;
				}

				return return_value;
			}
		}

		int int_value = 0;
		std::stringstream int_string_stream(buf);
		int_string_stream >> int_value;

		if (!int_string_stream.fail())
		{
			*output = int_value;

			return return_value;
		}
		else
		{
			*output = default_value_on_failure;

			return_value = 0;

			for (int i = 1; (default_value_on_failure / i) >= 1; i *= 10)
			{
				return_value++;
			}

			if (return_value == 0)
			{
				return_value = 1;
			}

			return return_value;
		}
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}