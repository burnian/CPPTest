class iString
{
public:

	iString(const char *str = NULL)    // ��ͨ���캯��
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

	iString(const iString &other)        // �������캯��
	{
		int len = other.getLength();
		m_data = (char *)malloc(len + 1);
		m_length = len;
		copy(m_data, len, other.getData());
	};

	~iString(void)                        // ��������
	{
		free(m_data);
	};

	iString & operator= (const iString &other)    // ��ֵ����
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

	char *m_data;       // ���ڱ����ַ���
	int m_length;		// ��Ч�ַ������ȣ�������'\0'
};
