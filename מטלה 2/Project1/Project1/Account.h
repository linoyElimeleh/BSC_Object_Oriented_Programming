#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Person.h"
#include "Transaction.h"

class Transaction;

class Account
{

private:
	int transactionCount;
	Transaction** m_transactionList;
	Person** personsAccount;
	int personAccountCount;
	int numberAccount;
	double balance;

public:

	Account(Person** persons, int countOfPersons, double balance);
	Account(const Person& person, int countOfPersons, double balance);
	Account();
	Account(const Account& a);

	void setPersons(Person** persons, int countOfPersons);
	void setTotalPersons(int totalPersons);
	void setAccountNumber(int number);
	void setBalance(double balance);
	void setTransaction(Transaction** newTransaction, int count);
	void setNumTransaction(int number);

	Person** getPersons() const;
	int getTotalPersons()const;
	int getAccountNumber();
	double getBalance() const;
	Transaction** getTransaction();
	int getNumOfTransaction();

	void withdraw(double amount, const char* date);
	void deposit(double amount, const char* date);
	bool addPerson(const Person& newPerson, double	amount);
	bool deletePerson(const Person& oldPerson, int index);

	bool addTransaction(const Transaction& newTransaction);

	~Account();
};


#endif //Account.h

