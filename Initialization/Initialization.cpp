#include "Initialization.h"

#include <sstream>
#include <strsafe.h>

MOONG::INITIALIZATION::Initialization::Initialization(const std::string default_string, const unsigned int default_value)
{
	this->setDefaultString(default_string);
	this->setDefaultValue(default_value);
}



DWORD MOONG::INITIALIZATION::Initialization::Write(const std::string app_name, const std::string key_name, const std::string value, const std::string file_path) const
{
	if (WritePrivateProfileStringA(app_name.c_str(), key_name.c_str(), value.c_str(), file_path.c_str()) == 0)
	{
		return GetLastError();
	}

	return EXIT_SUCCESS;
}

DWORD MOONG::INITIALIZATION::Initialization::Write(const std::string app_name, const std::string key_name, int value, const std::string file_path) const
{
	std::ostringstream convert_string;
	convert_string << value;

	return this->Write(app_name, key_name, convert_string.str(), file_path);
}



DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, std::string& output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getDefaultString(), output, length_output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path) const
{
	char* buf = new char[length_output];

	DWORD return_value = this->Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

	output = buf;

	delete[] buf;

	return return_value;
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, char* output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getDefaultString(), output, length_output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path) const
{
	char* buf = new char[length_output];

	DWORD return_value = GetPrivateProfileStringA(app_name.c_str(), key_name.c_str(), default_string_on_failure.c_str(), buf, length_output, file_path.c_str());

	if(strlen(buf) == 0)
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

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, wchar_t* output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getDefaultString(), output, length_output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, wchar_t* output, DWORD length_output, const std::string file_path) const
{
	char* buf = new char[length_output];

	DWORD return_value = this->Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

#if _MSC_VER > 1200
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, output, length_output, buf, _TRUNCATE);
#else
	mbstowcs(output, buf, length_output);
#endif

	delete[] buf;

	return return_value;
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getDefaultString(), delimit, output, length_output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path) const
{
	output.clear();

	std::string buf;
	DWORD return_value = this->Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

	char* token = NULL;
#if _MSC_VER > 1200
	char* next_token = NULL;

	token = strtok_s((char*)(buf.c_str()), delimit.c_str(), &next_token);

	while (token != NULL)
	{
		// Get next token:
		if (token != NULL)
		{
			output.push_back(token);

			token = strtok_s(NULL, delimit.c_str(), &next_token);
		}
	}
#else
	token = strtok((char*)(buf.c_str()), delimit.c_str());

	while (token != NULL)
	{
		output.push_back(token);

		// Get next token:
		token = strtok(NULL, delimit.c_str()); // C4996
	}
#endif

	return return_value;
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, int* output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getDefaultValue(), output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const int default_value_on_failure, int* output, const std::string file_path) const
{
	std::string buf;

	std::ostringstream default_string_on_failure;
	default_string_on_failure << default_value_on_failure;

	DWORD return_value = this->Read(app_name.c_str(), key_name.c_str(), default_string_on_failure.str(), buf, 64, file_path.c_str());

	for(unsigned int i = 0; i < buf.length(); i++)
	{
		if(buf[i] < '0' || buf[i] > '9')
		{
			*output = (int)(this->getDefaultValue());

			return_value = 0;

			for(int i = 1; (this->getDefaultValue() / i) >= 1; i *= 10)
			{
				return_value++;
			}

			if(return_value == 0)
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
		*output = (int)(this->getDefaultValue());

		return_value = 0;

		for (int i = 1; (this->getDefaultValue() / i) >= 1; i *= 10)
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



bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const std::string value, const std::string check_value) const
{
	if (check_value.compare(value) == 0)
	{
		return MOONG::INITIALIZATION::CHECK_VALUE::EMPTY;
	}

	return MOONG::INITIALIZATION::CHECK_VALUE::EXIST;
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const std::string value) const
{
	return this->CheckValueIsEmpty(value, this->getDefaultString());
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const char* const value, const std::string check_value) const
{
	std::string temp_value = value;

	return this->CheckValueIsEmpty(temp_value, check_value);
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const wchar_t* const value, const std::string check_value) const
{
	size_t new_size = (wcslen(value) + 1);
	char* nstring = new char[new_size];

#if _MSC_VER > 1200
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, nstring, new_size, value, _TRUNCATE);
#else
	wcstombs(nstring, value, new_size);
#endif

	bool return_value = this->CheckValueIsEmpty(nstring, check_value);

	delete[] nstring;

	return return_value;
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const wchar_t* const value) const
{
	return this->CheckValueIsEmpty(value, this->getDefaultString());
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const std::vector<std::string> value, const std::string check_value) const
{
	if (value.size() != 1)
	{
		return MOONG::INITIALIZATION::CHECK_VALUE::EXIST;
	}
	
	return this->CheckValueIsEmpty(value[0], check_value);
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const std::vector<std::string> value) const
{
	return this->CheckValueIsEmpty(value, this->getDefaultString());
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const unsigned int value, const unsigned int check_value) const
{
	if (value == check_value)
	{
		return MOONG::INITIALIZATION::CHECK_VALUE::EMPTY;
	}
	
	return MOONG::INITIALIZATION::CHECK_VALUE::EXIST;
}

bool MOONG::INITIALIZATION::Initialization::CheckValueIsEmpty(const unsigned int value) const
{
	return this->CheckValueIsEmpty(value, this->getDefaultValue());
}



const std::string MOONG::INITIALIZATION::Initialization::getDefaultString() const
{
	return this->default_string_;
}

unsigned int MOONG::INITIALIZATION::Initialization::getDefaultValue() const
{
	return this->default_value_;
}

void MOONG::INITIALIZATION::Initialization::setDefaultString(const std::string fail_string)
{
	this->default_string_ = fail_string;
}

void MOONG::INITIALIZATION::Initialization::setDefaultValue(const unsigned int fail_value)
{
	this->default_value_ = fail_value;
}