#ifndef _STR_H
#define _STR_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class Str
{
public://c'tors & d'tor
	Str();
	Str( const Str& other );
	Str( const char* str );
	~Str();

public://this operators
	bool	operator==( const Str& other ) const;
	bool	operator!=( const Str& other ) const;
	bool	operator>( const Str& other ) const;
	bool	operator<( const Str& other ) const;
	Str&	operator=( const Str& other );
	Str&	operator=( const char* str );
	char&	operator[]( int index ) const;
	Str&	operator++();
	Str		operator++( int );
	int		operator()( char ch ) const;
	Str		operator+( const Str& other ) const;
	Str&	operator+=( const Str& other );

public://cast operators
	operator int() const;

public://friend operators
	friend Str operator+( const char* str, const Str& other );
	friend Str operator*( int num, const Str& other );

private:
	char* m_str;
};

#endif // _STR_H