#include "Account.h"

Account::Account()
{
	this->transactionCount = 0;
	this->m_transactionList = nullptr;
	this->personsAccount = nullptr;
	this->personAccountCount = 0;
	this->numberAccount = 0;
	this->balance = 0;

}
Account::Account(Person** persons, int countOfPersons, double balance)
{
	this->transactionCount = 0;
	this->m_transactionList = nullptr;
	setPersons(persons, countOfPersons);
	this->balance = balance;

}
Account::Account(const Person& person, int countOfPersons, double balance)
{
	this->transactionCount = 0;
	this->m_transactionList = nullptr;
	personsAccount = new Person * [countOfPersons];
	personsAccount[0] = new Person(person);
	setPersons(personsAccount, countOfPersons);
	this->balance = balance;
}
Account::Account(const Account& a)
{
	this->transactionCount = a.transactionCount;
	setTransaction(a.m_transactionList, a.transactionCount);
	setPersons(a.personsAccount, a.personAccountCount);
	this->numberAccount = a.numberAccount;
	this->balance = a.balance;
}

void Account::setPersons(Person** persons, int countOfPersons)
{
	double tmp = 0;
	this->personAccountCount = countOfPersons;
	//delete[] personsAccount;
	personsAccount = new Person * [countOfPersons];
	for (int i = 0; i < countOfPersons; i++)
	{
		personsAccount[i] = persons[i];
		tmp += persons[i]->getId();

	}
	this->numberAccount = tmp;
}
void Account::setTotalPersons(int totalPersons)
{
	this->personAccountCount = totalPersons;
}
void Account::setAccountNumber(int number)
{
	this->numberAccount = number;
}
void Account::setBalance(double balance)
{
	this->balance = balance;
}
void Account::setTransaction(Transaction** newTransaction, int count)
{
	if (newTransaction != nullptr)
	{
		this->transactionCount = count;
		delete[] m_transactionList;
		m_transactionList = new Transaction * [count];
		for (int i = 0; i < count; i++)
		{
			m_transactionList[i] = newTransaction[i];
		}
	}
	this->transactionCount = count;
}
void Account::setNumTransaction(int number)
{
	this->transactionCount = number;
}
Person** Account::getPersons() const
{
	return this->personsAccount;
}
int Account::getTotalPersons()const
{
	return this->personAccountCount;
}
int Account::getAccountNumber()
{
	return this->numberAccount;

}
double Account::getBalance() const
{
	return this->balance;
}
Transaction** Account::getTransaction()
{
	return this->m_transactionList;
}
int Account::getNumOfTransaction()
{
	return this->transactionCount;
}

void Account::withdraw(double amount, const char* date)
{
	if (amount < 0)
	{

		addTransaction(Transaction(this, this, amount, date));
	}
	else
	{
		addTransaction(Transaction(this, this, (-1) * amount, date));
	}
}

void Account::deposit(double amount, const char* date)
{

	addTransaction(Transaction(this, this, amount, date));

}

bool Account::addPerson(const Person& newPerson, double	amount)
{
	if (&newPerson != nullptr)
	{
		if (this->getTotalPersons() == 0)
		{
			Person** tmp = new Person * [1];
			tmp[0] = new Person(newPerson);
			setPersons(tmp, 1);
			this->setBalance(amount);
			return true;
		}
		else
		{
			Person** newArray = new Person * [personAccountCount + 1];
			for (int i = 0; i < personAccountCount; i++)
			{
				newArray[i] = personsAccount[i];
			}
			newArray[personAccountCount] = new Person(newPerson);

			setPersons(newArray, personAccountCount + 1);

			this->balance = this->balance + amount;

			return true;
		}

	}
	return false;

}
bool Account::deletePerson(const Person& oldPerson, int index)
{
	if (&oldPerson != NULL)
	{
		//if (this->getTotalPersons() == 1)
		//{
			//personsAccount = nullptr;
			//return true;
		//}

		//else
		//{

		Person** tmp = new Person * [this->getTotalPersons() - 1];
		int i, k = 0;
		for (i = 0; i < this->getTotalPersons(); i++)
		{
			if (i != index)
			{
				tmp[k] = this->getPersons()[i];
				k++;
			}

		}
		//delete[] this->personsAccount;
		this->setPersons(tmp, this->getTotalPersons() - 1);
		return true;
		//}
	}
	return false;
}

bool Account::addTransaction(const Transaction& newTransaction)
{
	bool flag = false;
	if (&newTransaction != NULL)
	{
		if (newTransaction.getSource() != NULL && newTransaction.getDes() != NULL)
		{
			//same account
			if (newTransaction.getSource()->getAccountNumber() == newTransaction.getDes()->getAccountNumber())
			{
				//case nuul
				if (newTransaction.getSource()->getTransaction() == NULL)
				{
					Transaction** tmp0 = new Transaction * [1];
					tmp0[0] = new Transaction(newTransaction);
					newTransaction.getSource()->setTransaction(tmp0, 1);
					double tmp_balance = newTransaction.getSource()->getBalance() + tmp0[0]->getAmount();
					newTransaction.getSource()->setBalance(tmp_balance);

					delete[]tmp0;
					flag = true;
				}
				//case not null
				else
				{
					int num_trans = newTransaction.getSource()->getNumOfTransaction();
					Transaction** tmp1 = new Transaction * [num_trans + 1];
					int i;
					for (i = 0; i < num_trans; i++)
					{
						tmp1[i] = newTransaction.getSource()->getTransaction()[i];
					}
					tmp1[i] = new Transaction(newTransaction);
					double tmp_balance1 = newTransaction.getSource()->getBalance() + tmp1[i]->getAmount();
					newTransaction.getSource()->setTransaction(tmp1, num_trans + 1);
					newTransaction.getSource()->setBalance(tmp_balance1);
					//for(i=0;i<num_trans+1;i++)
				//	{
					//	delete tmp1[i];
					//}
					//delete[]tmp1;
					flag = true;
				}
			}
			//differend account


			else
			{
				//source null
				if (newTransaction.getSource()->getTransaction() == NULL)
				{
					Transaction** tmp2 = new Transaction * [1];
					tmp2[0] = new Transaction(newTransaction);
					newTransaction.getSource()->setTransaction(tmp2, 1);
					double tmp_balance2 = newTransaction.getSource()->getBalance() - tmp2[0]->getAmount();
					newTransaction.getSource()->setBalance(tmp_balance2);
					delete[] tmp2;
					flag = true;
				}
				//source not null
				else
				{
					int num_trans3 = newTransaction.getSource()->getNumOfTransaction();
					Transaction** tmp3 = new Transaction * [num_trans3];
					int i;
					for (i = 0; i < num_trans3; i++)
					{
						tmp3[i] = newTransaction.getSource()->getTransaction()[i];
					}
					tmp3[i] = new Transaction(newTransaction);
					double tmp_balance31 = newTransaction.getSource()->getBalance() - tmp3[i]->getAmount();
					newTransaction.getSource()->setTransaction(tmp3, num_trans3 + 1);
					newTransaction.getSource()->setBalance(tmp_balance31);
					flag = true;
				}
				//des==nul
				if (newTransaction.getDes()->getTransaction() == NULL)
				{
					Transaction** tmp4 = new Transaction * [1];
					tmp4[0] = new Transaction(newTransaction);
					newTransaction.getDes()->setTransaction(tmp4, 1);
					double tmp_balance4 = newTransaction.getDes()->getBalance() + tmp4[0]->getAmount();
					newTransaction.getDes()->setBalance(tmp_balance4);
					delete[]tmp4;
					flag = true;
				}
				//des not null
				else
				{
					int num_trans5 = newTransaction.getDes()->getNumOfTransaction();
					Transaction** tmp5 = new Transaction * [num_trans5];
					int i;
					for (i = 0; i < num_trans5; i++)
					{
						tmp5[i] = newTransaction.getDes()->getTransaction()[i];
					}
					tmp5[i] = new Transaction(newTransaction);
					double tmp_balance5 = newTransaction.getDes()->getBalance() + tmp5[i]->getAmount();

					newTransaction.getDes()->setTransaction(tmp5, num_trans5 + 1);
					newTransaction.getDes()->setBalance(tmp_balance5);
					flag = true;

				}
			}


		}
	}

	if (flag)
		return true;
	else return false;
}

Account::~Account()
{

	for (int i = 0; i < personAccountCount; i++)
	{
		personsAccount[i]->~Person();
	}
	delete[]personsAccount;
	delete[]m_transactionList;
	this->balance = 0;


	//if (personsAccount != NULL)

		//	for (int i = 0; i < personAccountCount; i++)
		///	{
			//	delete personsAccount[i];
		//	}
		//	delete[]personsAccount;
		//}
		//if (transactionCount != NULL)
		//{
		//	for (int i = 0; i < transactionCount; i++)
		//	{
		//		delete m_transactionList[i];
		//	}
		//	delete[] m_transactionList;
		//}


		//delete[] m_transactionList;

}




