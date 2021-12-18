#include "Initialization.h"

MOONG::INITIALIZATION::Initialization::Initialization(CStringA ini_file_path, CStringA default_string)
{
	this->Set_ini_file_path(ini_file_path);
	this->Set_default_string(default_string);
}

int MOONG::INITIALIZATION::Initialization::Read(CStringA app_name, CStringA key_name, char* output, DWORD size_output)
{
	GetPrivateProfileStringA(app_name.GetBuffer(), key_name.GetBuffer(), this->Get_default_string().GetBuffer(), output, size_output, this->Get_ini_file_path());

	return EXIT_SUCCESS;
}

int MOONG::INITIALIZATION::Initialization::Write(CStringA app_name, CStringA key_name, CStringA value)
{
	if (WritePrivateProfileStringA(app_name.GetBuffer(), key_name.GetBuffer(), value.GetBuffer(), this->Get_ini_file_path().GetBuffer()) == 0)
	{
		return GetLastError();
	}

	return EXIT_SUCCESS;
}

CStringA MOONG::INITIALIZATION::Initialization::Get_ini_file_path()
{
	return this->ini_file_path_;
}

void MOONG::INITIALIZATION::Initialization::Set_ini_file_path(CStringA ini_file_path)
{
	this->ini_file_path_ = ini_file_path;
}

CStringA MOONG::INITIALIZATION::Initialization::Get_default_string()
{
	return this->default_string_;
}

void MOONG::INITIALIZATION::Initialization::Set_default_string(CStringA default_string)
{
	this->default_string_ = default_string;
}
