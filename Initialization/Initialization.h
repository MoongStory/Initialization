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
			Initialization(const CStringA fail_string = "", const unsigned int fail_value = 0);

			// 반환 값
			//		성공 : 0
			//		실패 : GetLastError() 에러 코드.
			DWORD Write(CStringA file_path, CStringA app_name, CStringA key_name, CStringA value) const;
			DWORD Write(CStringA file_path, CStringA app_name, CStringA key_name, int value) const;



			// 반환 값
			//		문자열 길이.
			DWORD Read(CStringA file_path, CStringA app_name, CStringA key_name, char* output, DWORD length_output) const;
			DWORD Read(CStringA file_path, CStringA app_name, CStringA key_name, wchar_t* output, DWORD length_output) const;

			// 반환 값
			//		성공 : ini 파일에서 읽어들인 값.
			//		실패 : "Initialization" 클래스 생성 시 설정한 "fail_value" 값.
			//				설정하지 않았다면 헤더 파일의 생성자 파라미터 초기화 값.
			// "app_name"과 "key_name"이 존재하지만 값이 문자열로 설정되어 있을 경우 0을 반환하므로 주의할 것.
			unsigned int Read(CStringA file_path, CStringA app_name, CStringA key_name) const;



			CStringA Get_fail_string() const;
			unsigned int Get_fail_value() const;

		private:
			void Set_fail_string(CStringA fail_string);
			void Set_fail_value(const unsigned int fail_value);
			
		public:

		private:
			CStringA fail_string_;
			unsigned int fail_value_;
		};
	}
}
#endif	// _INITIALIZATION_H_