#include "Account.h"

Transaction::Transaction(Account* s, Account* d, double amount, const char* date) : m_source(s), m_destination(d)
{
	this->amount = amount;
	this->date = new char[strlen(date) + 1];
	for (int i = 0; i < strlen(date) + 1; i++)
	{
		this->date[i] = date[i];
	}
	//strcpy(this->date, date);
}
Transaction::Transaction(const Transaction& t) :m_source(t.m_source), m_destination(t.m_destination)
{
	this->amount = t.amount;
	this->date = new char[strlen(t.date) + 1];
	for (int i = 0; i < strlen(t.date) + 1; i++)
	{
		this->date[i] = t.date[i];
	}
	//strcpy(this->date, t.date);
}

void Transaction::setSource(Account* sor)
{
	if (sor != nullptr)
	{
		this->m_source = sor;
	}
}
void Transaction::setDes(Account* des)
{
	if (des != nullptr)
	{
		this->m_destination = des;
	}
}
void Transaction::setAmount(const double amount)
{
	this->amount = amount;
}
void Transaction::setDate(const char* date)
{
	delete this->date;
	this->date = new char[strlen(date) + 1];
	for (int i = 0; i < strlen(date) + 1; i++)
	{
		this->date[i] = date[i];
	}
	//	strcpy(this->date, date);

}
Account* Transaction::getSource() const
{
	return this->m_source;
}
Account* Transaction::getDes() const
{
	return this->m_destination;
}

double Transaction::getAmount() const
{
	return this->amount;
}
char* Transaction::getDate() const
{
	return this->date;
}


