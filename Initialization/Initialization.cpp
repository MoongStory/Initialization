#include "Initialization.h"

#include <strsafe.h>

MOONG::INITIALIZATION::Initialization::Initialization(const CStringA ini_file_path, const CStringA fail_string, const unsigned int fail_value)
{
	this->Set_ini_file_path(ini_file_path);
	this->Set_fail_string(fail_string);
	this->Set_fail_value(fail_value);
}



DWORD MOONG::INITIALIZATION::Initialization::Write(CStringA file_path, CStringA app_name, CStringA key_name, CStringA value)
{
	if (WritePrivateProfileStringA(app_name.GetBuffer(), key_name.GetBuffer(), value.GetBuffer(), file_path.GetBuffer()) == 0)
	{
		return GetLastError();
	}

	return EXIT_SUCCESS;
}

DWORD MOONG::INITIALIZATION::Initialization::Write(CStringA file_path, CStringA app_name, CStringA key_name, int value)
{
	CStringA convert_string;
	convert_string.Format("%d", value);

	return this->Write(file_path, app_name, key_name, convert_string);
}

DWORD MOONG::INITIALIZATION::Initialization::Write(CStringA app_name, CStringA key_name, CStringA value)
{
	return this->Write(this->Get_ini_file_path(), app_name, key_name, value);
}

DWORD MOONG::INITIALIZATION::Initialization::Write(CStringA app_name, CStringA key_name, int value)
{
	return this->Write(this->Get_ini_file_path(), app_name, key_name, value);
}



DWORD MOONG::INITIALIZATION::Initialization::Read(CStringA file_path, CStringA app_name, CStringA key_name, char* output, DWORD length_output)
{
	return GetPrivateProfileStringA(app_name.GetBuffer(), key_name.GetBuffer(), this->Get_fail_string().GetBuffer(), output, length_output, file_path.GetBuffer());
}

DWORD MOONG::INITIALIZATION::Initialization::Read(CStringA app_name, CStringA key_name, char* output, DWORD length_output)
{
	return this->Read(this->Get_ini_file_path(), app_name, key_name, output, length_output);
}

DWORD MOONG::INITIALIZATION::Initialization::Read(CStringA file_path, CStringA app_name, CStringA key_name, wchar_t* output, DWORD length_output)
{
	char* buf = new char[length_output];

	DWORD return_value = this->Read(file_path, app_name, key_name, buf, length_output);

	CStringW convert(buf);

	delete[] buf;

	StringCchCopyW(output, length_output, convert.GetBuffer());

	return return_value;
}

DWORD MOONG::INITIALIZATION::Initialization::Read(CStringA app_name, CStringA key_name, wchar_t* output, DWORD length_output)
{
	return this->Read(this->Get_ini_file_path(), app_name, key_name, output, length_output);
}

unsigned int MOONG::INITIALIZATION::Initialization::Read(CStringA file_path, CStringA app_name, CStringA key_name)
{
	return GetPrivateProfileIntA(app_name.GetBuffer(), key_name.GetBuffer(), this->Get_fail_value(), file_path.GetBuffer());
}

unsigned int MOONG::INITIALIZATION::Initialization::Read(CStringA app_name, CStringA key_name)
{
	return this->Read(this->Get_ini_file_path(), app_name, key_name);
}



CStringA MOONG::INITIALIZATION::Initialization::Get_ini_file_path()
{
	return this->ini_file_path_;
}

void MOONG::INITIALIZATION::Initialization::Set_ini_file_path(CStringA ini_file_path)
{
	this->ini_file_path_ = ini_file_path;
}

CStringA MOONG::INITIALIZATION::Initialization::Get_fail_string()
{
	return this->fail_string_;
}

unsigned int MOONG::INITIALIZATION::Initialization::Get_fail_value()
{
	return this->fail_value_;
}

void MOONG::INITIALIZATION::Initialization::Set_fail_string(CStringA fail_string)
{
	this->fail_string_ = fail_string;
}

void MOONG::INITIALIZATION::Initialization::Set_fail_value(const unsigned int fail_value)
{
	this->fail_value_ = fail_value;
}
