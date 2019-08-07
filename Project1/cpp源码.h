#pragma once
#include <iostream>

	

namespace wr{

	/*
	*strlen 源码分析
	*/
	int strlen_wr(const char *p) {
		const char * char_p = NULL;
		const unsigned long int *longword_ptr = NULL;
		register unsigned long int longword, magic_bits;

		//寻找对齐边界
		
		for (char_p = p; (unsigned long int)char_p & (sizeof(unsigned long int) - 1)!=0;++char_p) {
			if (char_p = '\0') {
				
				return char_p - p;
			}
		}

		longword_ptr = reinterpret_cast<const unsigned long int *>(p);
		magic_bits = 0x7efefeff;
		for (;;) {
			longword = *longword_ptr++;
			if ((((longword + magic_bits) ^ ~longword)&~magic_bits) != 0) {
				const char *cp = (const char*)(longword_ptr - 1);
				if (cp[0] == '\0')
					return cp - p;
				if (cp[1] == '\0')
					return cp - p + 1;
				if (cp[2] == '\0')
					return cp - p + 2;
				if (cp[3] == '\0')
					return cp - p + 3;
			}
		
		}

	}


	/*class string_s {
	public:
		string_s() {};
		string_s(const char *str) {
			if (str == NULL) {
				length = 0;
				m_data = new char[1];
				m_data[0] = '\0';
			}
			else {
				length = strlen(str);
				m_data = new char[length + 1];
				strncpy(m_data,str, length +1);
			}
			
		}

		string_s(const string_s &str) {
			length = str.length;
			m_data = new char[length + 1];
			strcpy(m_data,str.m_data);
		}

		string_s& operator=(const string_s&str) {
			if (&str == this)
				return;
			delete[] m_data;
			length = str.length;
			m_data = new char[length + 1];
			strcpy(m_data,str.m_data);
			return *this;
		}
		~string_s() {
			delete[] m_data;
		}
	private:
		char *m_data;
		size_t length;
	};*/
}
