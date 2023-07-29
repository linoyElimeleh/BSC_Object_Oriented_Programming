
#include "Bank.h"
#include "Account.h"

Bank::Bank()
{
	this->name = nullptr;
	this->code = 0;
	this->arrayAccount = nullptr;
	this->arrayAccountCount = 0;
	this->balance = 0;
}
Bank::Bank(const char* name, const int code) :arrayAccount(nullptr)
{
	if (name != NULL)
	{
		this->name = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name) + 1; i++)
		{
			this->name[i] = name[i];
		}
	}
	//strcpy(this->name, name);
	this->code = code;

	this->arrayAccountCount = 0;
	this->balance = 0;
}

void Bank::setBankName(const char* bank)
{
	if (bank != NULL)
	{
		delete this->name;
		this->name = new char[strlen(bank) + 1];
		for (int i = 0; i < strlen(bank) + 1; i++)
		{
			this->name[i] = bank[i];
		}
	}

	//strcpy(this->name, name);
}

void Bank::setAccount(Account** account, int numbeOfAccounts)
{
	if (account != nullptr)
	{
		this->balance = 0;
		this->arrayAccount = new Account * [numbeOfAccounts];
		for (int i = 0; i < numbeOfAccounts; i++)
		{
			this->arrayAccount[i] = account[i];
			//this->arrayAccount[i] = new Account(*account[i]);
			balance += account[i]->getBalance();
		}
		setNumberOfAccount(numbeOfAccounts);

	}
	else
		setNumberOfAccount(0);

}

void Bank::setNumberOfAccount(int numbeOfAccounts)
{
	this->arrayAccountCount = numbeOfAccounts;
}

void Bank::setTotal(double total)
{
	this->balance = total;
}
void Bank::setCode(const int code)
{
	this->code = code;
}

char* Bank::getBankName() const
{
	return this->name;
}


Account** Bank::getAccount()
{
	return arrayAccount;
}
int Bank::getNumberOfAccount()
{
	return this->arrayAccountCount;
}
double Bank::getTotal()
{
	return this->balance;
}
int Bank::getCode() const
{
	return this->code;
}
bool Bank::addAccount(const Account& account)
{
	if (&account != NULL)
	{
		Account** newListOfAccounts = new Account * [arrayAccountCount + 1];
		if (newListOfAccounts == NULL)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < arrayAccountCount; i++)
			{
				newListOfAccounts[i] = arrayAccount[i];
			}
			newListOfAccounts[arrayAccountCount] = new Account(account);
			arrayAccount = new Account * [arrayAccountCount + 1];
			if (arrayAccount != NULL)
			{
				arrayAccount = newListOfAccounts;
				this->balance = account.getBalance() + this->balance;
				arrayAccountCount += 1;
				return true;
			}
			else
			{
				return false;
			}
			this->balance += account.getBalance();
		}
	}




}
bool Bank::addAccount(const Person& per, double amount)
{
	if (&per != NULL)
	{
		Person** p = new Person * [1];
		p[0] = new Person(per);

		if (addAccount(Account(p, 1, amount)))
			return true;
	}

	return false;
}

bool Bank::addPerson(const Person& newPerson, int index, double amount)
{
	if (&newPerson != NULL)
	{
		if (this->arrayAccount[index]->addPerson(newPerson, amount));
		{
			this->setTotal(this->getTotal() + amount);
			return true;

		}

		//setAccount(getAccount(), getNumberOfAccount());
	}

	return false;


}
bool Bank::deleteAccount(Account* account, int index)
{
	try
	{
		int k = 0;
		Account** tmp = new Account * [arrayAccountCount - 1];
		for (int i = 0; i < this->arrayAccountCount; i++)
		{
			if (i != index)
			{

				tmp[k] = arrayAccount[i];
				k++;
			}
		}
		delete this->arrayAccount[index];
		setAccount(tmp, arrayAccountCount - 1);
		return true;

	}
	catch (...)
	{
		return false;
	}

}

bool Bank::deletePerson(const Person& p)
{
	bool flag = false;
	if (&p != nullptr)
	{
		int tmpId = p.getId();
		int total_persons;
		for (int i = 0; i < this->getNumberOfAccount(); i++)
		{
			total_persons = this->getAccount()[i]->getTotalPersons();
			for (int j = 0; j < total_persons; j++)
			{
				char* name = this->getAccount()[i]->getPersons()[j]->getName();
				int old_id = this->getAccount()[i]->getPersons()[j]->getId();
				if (old_id == tmpId)
				{
					if (total_persons == 1)
					{
						this->balance -= this->getAccount()[i]->getBalance();
						arrayAccount[i]->deletePerson(p, j);
						//todo
						deleteAccount(this->getAccount()[i], i);
						flag = true;
					}
					else
					{
						arrayAccount[i]->deletePerson(p, j);
						flag = true;
					}
				}
			}
		}
	}
	if (flag)
		return true;

	else
		return false;

}
Bank::~Bank()
{
	if (name != nullptr)
	{
		delete name;
	}
	if (arrayAccount != nullptr)
	{
		for (int i = 0; i < arrayAccountCount; i++)
		{
			delete arrayAccount[i];
		}
		delete[]arrayAccount;

	}
}
