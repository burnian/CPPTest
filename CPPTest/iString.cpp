class iString
{
public:

	iString(const char *str = NULL)    // 普通构造函数
	{
		if (str == NULL)
		{
			m_data = (char *)malloc(1);
			m_data = "\0";
			m_length = 0;
			return;
		}
		int len = 0;
		while (str[len] != '\0')
		{
			len++;
		}
		m_data = (char *)malloc(len + 1);
		m_length = len;
		copy(m_data, m_length, str);
	};

	iString(const iString &other)        // 拷贝构造函数
	{
		int len = other.getLength();
		m_data = (char *)malloc(len + 1);
		m_length = len;
		copy(m_data, len, other.getData());
	};

	~iString(void)                        // 析构函数
	{
		free(m_data);
	};

	iString & operator= (const iString &other)    // 赋值函数
	{
		if (this == &other)
		{
			return *this;
		}
		free(m_data);
		int len = other.getLength();
		m_data = (char *)malloc(len + 1);
		m_length = len;
		copy(m_data, len, other.getData());
		return *this;
	};

	char *copy(char *strDest, int len, const char *strSrc)
	{
		int i = 0;
		for (; i < len; i++)
		{
			strDest[i] = strSrc[i];
		}
		strDest[i] = '\0';
		return strDest;
	}

	char *copy(char *strDest, char *strSrc)
	{
		int i = 0;
		while (strSrc[i] != '\0')
		{
			strDest[i] = strSrc[i];
			i++;
		}
		strDest[i] = '\0';
		return strDest;
	}

	char* getData() const { return m_data; }

	int getLength() const { return m_length; }

private:

	char *m_data;       // 用于保存字符串
	int m_length;		// 有效字符串长度，不包括'\0'
};
