class CMyString {
public:
	CMyString(char* pData = nullptr) {};
	CMyString(const CMyString& str) {};
	CMyString operator=(const CMyString&t) {
		return t;
	};
private:
	char * m_pData;
};