#include "Initialization.h"

#include <sstream>
#include <strsafe.h>

MOONG::INITIALIZATION::Initialization::Initialization(const std::string fail_string, const unsigned int fail_value)
{
	this->setFailString(fail_string);
	this->setFailValue(fail_value);
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



DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, char* output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getFailString(), output, length_output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, char* output, DWORD length_output, const std::string file_path) const
{
	return GetPrivateProfileStringA(app_name.c_str(), key_name.c_str(), default_string_on_failure.c_str(), output, length_output, file_path.c_str());
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, wchar_t* output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getFailString(), output, length_output, file_path);
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
	//wcstombs(nstring, ipstringbuffer, new_size);
#endif

	delete[] buf;

	return return_value;
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, std::string& output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getFailString(), output, length_output, file_path);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string default_string_on_failure, std::string& output, DWORD length_output, const std::string file_path) const
{
	char* buf = new char[length_output];

	DWORD return_value = this->Read(app_name, key_name, default_string_on_failure, buf, length_output, file_path);

	output = buf;

	delete[] buf;

	return return_value;
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, std::string delimit, std::vector<std::string>& output, DWORD length_output, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getFailString(), delimit, output, length_output, file_path);
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

unsigned int MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const std::string file_path) const
{
	return this->Read(app_name, key_name, this->getFailValue(), file_path);
}

unsigned int MOONG::INITIALIZATION::Initialization::Read(const std::string app_name, const std::string key_name, const int default_value_on_failure, const std::string file_path) const
{
	return GetPrivateProfileIntA(app_name.c_str(), key_name.c_str(), default_value_on_failure, file_path.c_str());
}



const std::string MOONG::INITIALIZATION::Initialization::getFailString() const
{
	return this->fail_string_;
}

unsigned int MOONG::INITIALIZATION::Initialization::getFailValue() const
{
	return this->fail_value_;
}

void MOONG::INITIALIZATION::Initialization::setFailString(const std::string fail_string)
{
	this->fail_string_ = fail_string;
}

void MOONG::INITIALIZATION::Initialization::setFailValue(const unsigned int fail_value)
{
	this->fail_value_ = fail_value;
}