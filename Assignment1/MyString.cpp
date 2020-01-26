#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mStringLength(getCStringLength(s))
	{
		mString = new char[mStringLength + 1];
		copyCString(mString, s, mStringLength);
	}

	MyString::MyString(const MyString& other)
		: mStringLength(other.mStringLength)
	{
		mString = new char[mStringLength + 1];
		copyCString(mString, other.mString, mStringLength);
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mStringLength;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		size_t sLength = getCStringLength(s);
		if (sLength == 0)
		{
			return;
		}

		size_t strLength = mStringLength + sLength;
		char* str = appendCStrings(mString, s, strLength);

		delete[] mString;
		mString = str;
		mStringLength = strLength;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		char* str = appendCStrings(mString, other.mString, mStringLength + other.mStringLength);

		MyString newObj(str);

		delete[] str;

		return newObj;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return -1;
		}

		size_t sLength = getCStringLength(s);
		if (sLength <= 0)
		{
			if (*s == '\0')
			{
				return 0;
			}

			return -1;
		}

		int deviation = mStringLength - sLength;
		if (deviation < 0)
		{
			return -1;
		}
		else if (deviation == 0)
		{
			if (mString == s)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		
		for (int i = 0; i < deviation + 1; ++i)
		{
			const char* sP = s;
			char* strP = &mString[i];
			while (*sP != '\0')
			{
				if (*sP != *strP)
				{
					break;
				}

				++sP;
				++strP;

				if (*sP == '\0')
				{
					return i;
				}
			}
		}

		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return -1;
		}

		size_t sLength = getCStringLength(s);
		if (sLength <= 0)
		{
			if (*s == '\0')
			{
				return mStringLength;
			}

			return -1;
		}

		int deviation = mStringLength - sLength;
		if (deviation < 0)
		{
			return -1;
		}
		else if (deviation == 0)
		{
			if (mString == s)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}

		for (int i = mStringLength - 1; i > static_cast<int>(sLength - 2); --i)
		{
			const char* sP = &s[sLength - 1];
			char* strP = &mString[i];
			for (int si = sLength - 1; si > -1; --si)
			{
				if (*sP != *strP)
				{
					break;
				}

				--sP;
				--strP;

				if (si == 0)
				{
					return i - (sLength - 1);
				}
			}
		}

		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		size_t sLength = getCStringLength(s);
		if (sLength <= 0)
		{
			return;
		}

		size_t strLength = mStringLength + sLength;
		char* str = new char[strLength + 1];
		str[strLength] = '\0';
		
		char* strP = str;
		char* originP = mString;
		const char* sP = s;
		while (*strP != '\0')
		{
			if (*originP != '\0')
			{
				*strP = *originP;
				++strP;
				++originP;
			}

			if (*strP == '\0') 
			{
				break;
			}

			if (*sP != '\0')
			{
				*strP = *sP;
				++strP;
				++sP;
			}
		}

		delete[] mString;
		mString = str;
		mStringLength = strLength;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index >= mStringLength)
		{
			return false;
		}

		char* str = new char[mStringLength];
		char* strP = str;
		for (size_t i = 0; i < mStringLength; ++i)
		{
			if (i == index) 
			{
				continue;
			}
			*strP = mString[i];
			++strP;
		}
		*strP = '\0';

		delete[] mString;
		mString = str;
		--mStringLength;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		int deviation = totalLength - mStringLength;
		if (deviation <= 0)
		{
			return;
		}

		char* str = new char[totalLength + 1];
		str[totalLength] = '\0';

		char* strP = str;
		char* originP = mString;
		while (*strP != '\0')
		{
			if (deviation != 0)
			{
				*strP = c;
				--deviation;
			}
			else
			{
				*strP = *originP;
				++originP;
			}
			++strP;
		}

		delete[] mString;
		mString = str;
		mStringLength = totalLength;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		int deviation = totalLength - mStringLength;
		if (deviation <= 0)
		{
			return;
		}

		char* str = new char[totalLength + 1];
		char* strP = str;
		char* originP = mString;
		for (unsigned int i = 0; i < totalLength; ++i)
		{
			if (i < totalLength - deviation)
			{
				*strP = *originP;
				++originP;
			}
			else
			{
				*strP = c;
			}
			++strP;
		}
		*strP = '\0';

		delete[] mString;
		mString = str;
		mStringLength = totalLength;
	}

	void MyString::Reverse()
	{
		size_t ri = mStringLength - 1;
		for (size_t i = 0; i < mStringLength / 2; ++i)
		{
			char temp = mString[i];
			mString[i] = mString[ri];
			mString[ri] = temp;
			
			--ri;
			if (i == ri)
			{
				break;
			}
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mStringLength != rhs.mStringLength)
		{
			return false;
		}

		char* strP = mString;
		char* rhsStrP = rhs.mString;
		while (*strP != '\0')
		{
			if (*strP != *rhsStrP)
			{
				return false;
			}

			++strP;
			++rhsStrP;
		}

		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (mString == rhs.mString)
		{
			return *this;
		}

		delete[] mString;

		mStringLength = rhs.mStringLength;
		mString = new char[mStringLength + 1];
		copyCString(mString, rhs.mString, mStringLength);

		return *this;
	}

	void MyString::ToLower()
	{
		const int ASCII_DEVIATION = 32;
		const int UPPER_CASE_START = 64;
		const int UPPER_CASE_END = 91;

		char* strP = mString;
		while (*strP != '\0')
		{
			int asciiNum = static_cast<int>(*strP);
			if (UPPER_CASE_START < asciiNum && UPPER_CASE_END > asciiNum)
			{
				*strP = static_cast<char>(asciiNum + ASCII_DEVIATION);
			}
			++strP;
		}
	}

	void MyString::ToUpper()
	{
		const int ASCII_DEVIATION = 32;
		const int LOWER_CASE_START = 96;
		const int LOWER_CASE_END = 123;

		char* strP = mString;
		while (*strP != '\0')
		{
			int asciiNum = static_cast<int>(*strP);
			if (LOWER_CASE_START < asciiNum && LOWER_CASE_END > asciiNum)
			{
				*strP = static_cast<char>(asciiNum - ASCII_DEVIATION);
			}

			++strP;
		}
	}

	size_t MyString::getCStringLength(const char* src) const
	{
		const char* srcP = src;
		size_t length = 0;

		if (src == nullptr)
		{
			return length;
		}

		while (*srcP != '\0')
		{
			++length;
			++srcP;
		}

		return length;
	}

	void MyString::copyCString(char* dest, const char* src, const size_t length)
	{
		char* destP = dest;
		const char* srcP = src;

		for (size_t i = 0; i < length; ++i)
		{
			*destP = *srcP;

			++destP;
			++srcP;
		}

		*destP = '\0';
	}

	char* MyString::appendCStrings(const char* src1, const char* src2, const size_t length) const
	{
		char* str = new char[length + 1];
		char* strP = str;
		
		while (*src1 != '\0')
		{
			*strP = *src1;

			++strP;
			++src1;
		}

		while (*src2 != '\0')
		{
			*strP = *src2;

			++strP;
			++src2;
		}

		*strP = '\0';

		return str;
	}
}
