#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mStringLength(getCStringLength(s))
		, mString(copyCString(s))
	{
	}

	MyString::MyString(const MyString& other)
		: mStringLength(other.mStringLength)
		, mString(copyCString(other.mString))
	{
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
	}

	MyString MyString::operator+(const MyString& other) const
	{
		return MyString("temporary");
	}

	int MyString::IndexOf(const char* s)
	{
		return 0;
	}

	int MyString::LastIndexOf(const char* s)
	{
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (mString == rhs.mString)
		{
			return *this;
		}

		delete[] mString;

		mStringLength = rhs.mStringLength;
		mString = copyCString(rhs.mString);

		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}

	size_t MyString::getCStringLength(const char* src) const
	{
		const char* srcP = src;
		size_t length = 0;

		while (*srcP != '\0')
		{
			++length;
			++srcP;
		}

		return length;
	}

	char* MyString::copyCString(const char* src) const
	{
		const char* srcP = src;
		size_t length = getCStringLength(src);
		char* copy = new char[length + 1];

		char* copyP = copy;
		while (*srcP != '\0')
		{
			*copyP = *srcP;

			++copyP;
			++srcP;
		}
		*copyP = '\0';

		return copy;
	}
}
