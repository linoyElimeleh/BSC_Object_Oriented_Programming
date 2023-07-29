#include "str.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


Str::Str()
{
	this->m_str = new char[strlen("none") + 1];
	strcpy(this->m_str, "none");
}
Str::Str(const Str& other)
{
	this->m_str = new char[strlen(other.m_str) + 1];
	strcpy(this->m_str, other.m_str);
}
Str::Str(const char* str)
{
	this->m_str = new char[strlen(str) + 1];
	strcpy(this->m_str, str);
}
Str::~Str()
{
	delete this->m_str;
}
bool Str::operator==(const Str& other) const
{
	if (strlen(other.m_str) != strlen(this->m_str))
	{
		return false;
	}
	for (int i = 0; i < strlen(this->m_str) + 1; i++)
	{
		if (this->m_str[i] != other.m_str[i])
		{
			return false;
		}
	}
	return true;
}

bool Str::operator!=(const Str& other) const
{
	if (strlen(other.m_str) != strlen(this->m_str))
	{
		return true;
	}
	for (int i = 0; i < strlen(this->m_str) + 1; i++)
	{
		if (this->m_str[i] != other.m_str[i])
		{
			return true;
		}
	}
	return false;
}

bool	Str::operator>(const Str& other) const
{
	if (strcmp(this->m_str, other.m_str) > 0)
	{
		return true;
	}
	return false;
}
bool	Str::operator<(const Str& other) const
{
	if (strcmp(this->m_str, other.m_str) < 0)
	{
		return true;
	}
	return false;
}
Str& Str::operator=(const Str& other)
{
	this->m_str = other.m_str;
	return *this;
}
Str& Str::operator=(const char* str)
{
	strcpy(this->m_str, str);
	return *this;
}
char& Str::operator[](int index) const
{
	return this->m_str[index];
}

Str& Str::operator++()
{
	return *this;

}
Str		Str::operator++(int)
{
	return *this;
}

Str::operator int() const
{
	return strlen(this->m_str);
}
int		Str::operator()(char ch) const
{

	for (int i = 0; i < strlen(this->m_str) + 1; i++)
	{
		if (this->m_str[i] = ch)
			return i;
	}
	return -1;
}
Str		Str::operator+(const Str& other) const
{
	strcat(this->m_str, other.m_str);
	return *this;
}
Str& Str::operator+=(const Str& other)
{
	strcat(this->m_str, other.m_str);
	return *this;
}
Str operator+(const char* str, const Str& other)
{
	strcat(other.m_str, str);
	return other;
}
 Str operator*(int num, const Str& other)
{
	for(int i=0;i<num-1;i++)
	{
		strcat(other.m_str, other.m_str);
	}
	return  other;
}
