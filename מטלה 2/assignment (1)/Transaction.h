#ifndef  TRANSACTION_H
#define TRANSACTION_H
#include <string.h>
class Account;

class Transaction {

	 Account *m_source;
	 Account *m_destination;

public:
	Transaction(Account *s, Account *d, double amount, const char* date);
	Transaction(const Transaction &t);

	void setSource( Account *sor);
	void setDes( Account *des);
	void setAmount(const double amount);
	void setDate(const char* date);

	Account* getSource() const;
	Account* getDes() const;
	double getAmount() const;
	char* getDate() const;

};





#endif // ! TRANSACTION_H

