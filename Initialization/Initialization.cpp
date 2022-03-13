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

	return this->Write(file_path, app_name, key_name, convert_string.str());
}



DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string file_path, const std::string app_name, const std::string key_name, char* output, DWORD length_output) const
{
	return GetPrivateProfileStringA(app_name.c_str(), key_name.c_str(), this->getFailString().c_str(), output, length_output, file_path.c_str());
}

DWORD MOONG::INITIALIZATION::Initialization::Read(const std::string file_path, const std::string app_name, const std::string key_name, wchar_t* output, DWORD length_output) const
{
	char* buf = new char[length_output];

	DWORD return_value = this->Read(file_path, app_name, key_name, buf, length_output);

	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, output, length_output, buf, _TRUNCATE);

	delete[] buf;

	return return_value;
}

unsigned int MOONG::INITIALIZATION::Initialization::Read(const std::string file_path, const std::string app_name, const std::string key_name) const
{
	return GetPrivateProfileIntA(app_name.c_str(), key_name.c_str(), this->getFailValue(), file_path.c_str());
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