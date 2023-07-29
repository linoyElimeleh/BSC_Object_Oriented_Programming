#ifndef BANK_H
#define BANK_H

#include "Account.h"

class Bank {
	char* name;
	int code;
	 Account** arrayAccount;
	int arrayAccountCount;
	double balance;
	
public:
	Bank();
	Bank(const char *name, const int code);

	void setBankName(const char *bank);
	void setAccount(Account **account, int numbeOfAccounts);
	void setNumberOfAccount(int numbeOfAccounts);
	void setTotal(double total); 
	void setCode(const int code); 

	char* getBankName() const;
	Account** getAccount() ;
	int getNumberOfAccount();
	double getTotal();  
	int getCode() const;

	bool addAccount(const Account &account);
	bool addAccount(const Person &per, double amount);
	bool addPerson(const Person &newPerson, int index, double amount);

	bool deleteAccount(Account *account, int index);
	bool deletePerson(const Person& p);


	~Bank();
};
#endif // BANK_H
