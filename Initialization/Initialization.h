// https://github.com/MoongStory/Initialization

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _INITIALIZATION_H_
#define _INITIALIZATION_H_

#include <atlstr.h>

namespace MOONG
{
	namespace INITIALIZATION
	{
		class Initialization
		{
		public:
			Initialization(CStringA ini_file_path, CStringA default_string);

			// TODO: 숫자 읽고 쓰는 함수도 추가.
			int Read(CStringA app_name, CStringA key_name, char* output, DWORD length_output);
			int Read(CStringA app_name, CStringA key_name, wchar_t* output, DWORD length_output);
			//int Read(CStringA app_name, CStringA key_name, int);


			// 0 : 성공.
			// GetLastError() 에러 코드 : 실패.
			int Write(CStringA app_name, CStringA key_name, CStringA value);
			int Write(CStringA app_name, CStringA key_name, int value);

			CStringA Get_default_string();

		private:
			CStringA Get_ini_file_path();
			void Set_ini_file_path(CStringA ini_file_path);

			void Set_default_string(CStringA default_string);
			
		public:

		private:
			CStringA ini_file_path_;
			CStringA default_string_;
		};
	}
}
#endif	// _INITIALIZATION_H_