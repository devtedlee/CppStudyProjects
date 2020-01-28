#include "MyString.h"

namespace assignment1
{
	enum {
		FAILED = -1,
		ASCII_DIFF = 32
	};

	MyString::MyString(const char* s)
		: mLength(getCStringLength(s))
	{
		mString = new char[mLength + 1];
		copyCString(mString, s, mLength);
	}

	MyString::MyString(const MyString& other)
		: mLength(other.mLength)
	{
		mString = new char[mLength + 1];
		copyCString(mString, other.mString, mLength);
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		if (s[0] == '\0')
		{
			return;
		}

		size_t strLength = mLength + getCStringLength(s);
		char* str = appendCStringsMalloc(mString, s, strLength);

		delete[] mString;
		mString = str;
		mLength = strLength;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString newObj(mString);
		newObj.Append(other.mString);

		return newObj;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return FAILED;
		}

		size_t sLength = getCStringLength(s);
		if (sLength <= 0)
		{
			if (*s == '\0')
			{
				return 0;
			}

			return FAILED;
		}

		int lengthDiff = mLength - sLength;
		if (lengthDiff < 0)
		{
			return FAILED;
		}
		else if (lengthDiff == 0)
		{
			if (strCmp(mString, s) == 0)
			{
				return 0;
			}

			return FAILED;
		}
		
		for (int i = 0; i < lengthDiff + 1; ++i)
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

		return FAILED;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return FAILED;
		}

		size_t sLength = getCStringLength(s);
		if (sLength <= 0)
		{
			if (*s == '\0')
			{
				return mLength;
			}

			return FAILED;
		}

		int lengthDiff = mLength - sLength;
		if (lengthDiff < 0)
		{
			return FAILED;
		}
		else if (lengthDiff == 0)
		{
			if (mString == s)
			{
				return 0;
			}
			else
			{
				return FAILED;
			}
		}

		for (int i = mLength - 1; i > static_cast<int>(sLength - 2); --i)
		{
			const char* sP = &s[sLength - 1];
			char* strP = &mString[i];
			for (int si = sLength - 1; si > FAILED; --si)
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

		return FAILED;
	}

	void MyString::Interleave(const char* s)
	{
		size_t sLength = getCStringLength(s);
		if (sLength <= 0)
		{
			return;
		}

		size_t strLength = mLength + sLength;
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
		mLength = strLength;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index >= mLength)
		{
			return false;
		}

		char* str = new char[mLength];
		char* strP = str;
		for (size_t i = 0; i < mLength; ++i)
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
		--mLength;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		int lengthDiff = totalLength - mLength;
		if (lengthDiff <= 0)
		{
			return;
		}

		char* str = new char[totalLength + 1];
		str[totalLength] = '\0';

		char* strP = str;
		char* originP = mString;
		while (*strP != '\0')
		{
			if (lengthDiff != 0)
			{
				*strP = c;
				--lengthDiff;
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
		mLength = totalLength;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		int lengthDiff = totalLength - mLength;
		if (lengthDiff <= 0)
		{
			return;
		}

		char* str = new char[totalLength + 1];
		char* strP = str;
		char* originP = mString;
		for (unsigned int i = 0; i < totalLength; ++i)
		{
			if (i < totalLength - lengthDiff)
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
		mLength = totalLength;
	}

	void MyString::Reverse()
	{
		size_t ri = mLength - 1;
		for (size_t i = 0; i < mLength / 2; ++i)
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
		if (mLength != rhs.mLength)
		{
			return false;
		}

		if (strCmp(mString, rhs.mString) != 0)
		{
			return false;
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

		mLength = rhs.mLength;
		mString = new char[mLength + 1];
		copyCString(mString, rhs.mString, mLength);

		return *this;
	}

	void MyString::ToLower()
	{
		char* strP = mString;
		while (*strP != '\0')
		{
			if ('A' <= *strP && 'Z' >= *strP)
			{
				*strP = *strP + ASCII_DIFF;
			}
			++strP;
		}
	}

	void MyString::ToUpper()
	{
		char* strP = mString;
		while (*strP != '\0')
		{
			if ('a' <= *strP && 'z' >= *strP)
			{
				*strP = *strP - ASCII_DIFF;
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

	char* MyString::appendCStringsMalloc(const char* src1, const char* src2, const size_t length) const
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

	int MyString::strCmp(const char* str1, const char* str2) const
	{		
		const int EQUAL = 0;
		int result = 0;

		const char* str1P = str1;
		const char* str2P = str2;
		while (true)
		{
			result = *str1P - *str2P;
			if (result != 0)
			{
				return result;
			}
			
			if (*str1P == '\0' || *str2P == '\0')
			{
				if (*str1P == *str2P)
				{
					return EQUAL;
				}

				return result;
			}

			++str1P;
			++str2P;
		}
	}
}
