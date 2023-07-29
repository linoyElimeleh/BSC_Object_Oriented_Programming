#include "Person.h"

Person::Person()
{
	this->id = 00000000;
	this->name = nullptr;

}

Person::Person(const char* m_newName, const int m_newId)
{
	this->id = m_newId;
	this->name = new char[strlen(m_newName) + 1];
	for (int i = 0; i < strlen(m_newName) + 1; i++)
	{
		this->name[i] = m_newName[i];
	}

	//strcpy(this->name, m_newName);
}
Person::Person(const Person& p)
{
	this->id = p.getId();
	this->name = new char[strlen(p.getName()) + 1];
	for (int i = 0; i < strlen(p.getName()) + 1; i++)
	{
		this->name[i] = p.getName()[i];
	}
	//strcpy(this->name, p.getName());
}

void Person::setName(const char* m_newName)
{
	if (m_newName != nullptr)
	{
		this->name = new char[strlen(m_newName) + 1];
		for (int i = 0; i < strlen(m_newName) + 1; i++)
		{
			this->name[i] = m_newName[i];
		}
	}

	//strcpy(this->name, m_newName);
}
void Person::setId(const int m_newId)
{
	this->id = m_newId;

}

char* Person::getName() const
{
	return this->name;
}
int Person::getId() const
{
	return this->id;
}

Person::~Person()
{
	if (name != NULL)
	{
		delete[] name;

	}
}



