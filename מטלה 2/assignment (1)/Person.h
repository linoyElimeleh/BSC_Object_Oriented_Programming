#ifndef PERSON_H
#define PERSON_H

#include <string.h>
#include <iostream>
using namespace std;


class Person {


public:
	Person();
	Person(const char *m_newName, const int m_newId);
	Person(const Person &p);

	void setName(const char* m_newName);
	void setId(const int m_newId);
	char* getName() const ;
	int getId() const ;


	~Person();
};



#endif // !PERSON_H
