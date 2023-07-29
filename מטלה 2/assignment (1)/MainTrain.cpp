#include "Bank.h"
#include <iostream>
using namespace std;

int main() //Train
{
	Bank bank("The First International Bank of Israel Ltd​", 31);
	Account account;
	Person lior("Lior Li", 20145876);
	Person liam("Liam Winter", 2048741);
	int countNumberOfAccount , countNumberOfUsers = account.getTotalPersons();
	double currentA, currentB, currentC;

	/*****************************A**************************************/
	if(&bank == NULL)
		cout<<"Error in creating a bank object(-4)" << endl;

	/*****************************B**************************************/
	if( account.addPerson(Person("Amit Choen", 30292827),10000) == false)
		cout << "Error in adding a new Person to an account(-4)" << endl;
	if(account.addPerson(lior, 5000) == false)
		cout << "Error in adding a Person to the account(-4)" << endl;
	if (countNumberOfUsers == account.getTotalPersons())
		cout << "Error in number Of Users(-5)" << endl;
	if (account.getPersons() == NULL)
		cout << "Error in get **person to the account(-4)" << endl;

	/*****************************C**************************************/	
	if(bank.addAccount(account) ==false)
		cout << "Error in adding an account to the bank(-4)" << endl;
	
	countNumberOfAccount = bank.getNumberOfAccount();

	if (countNumberOfAccount != 1)
		cout << "Error in updating the a count of account in the bank(-4)" << endl;

	if (bank.addAccount(Account(Person("Dor Levi",32145672),1,10)) == false)
		cout << "Error in adding a new account to the bank (-4)" << endl;
	
	countNumberOfAccount = bank.getNumberOfAccount(); 

	if (countNumberOfAccount != 2)
		cout << "Error in updating the a count of account in the bank(-4)" << endl;

	/*****************************D**************************************/
	currentA = bank.getAccount()[0]->getBalance();
	currentB = bank.getAccount()[1]->getBalance();
	
	bank.addAccount(lior, 200);

	if (bank.addPerson(Person("Karin Yon",22415624),2,1005) == false)
		cout << "Error in adding a new person to an exsiting account(-4)" << endl;
	
	if(bank.getAccount()[0]->addTransaction(Transaction(bank.getAccount()[0],bank.getAccount()[1],500,"12-04-18"))== false)
		cout << "Error in adding a new transaction to the account (-4)" << endl;

	if (bank.getAccount()[0]->getNumOfTransaction() ==  0)
		cout << "Error in numer of transaction (-4)" << endl;

	if (bank.getAccount()[0]->getBalance() == currentA)
		cout << "Error in update the balance of the account (-4)" << endl;

	if (bank.getAccount()[1]->getBalance() == currentB)
		cout << "Error in update the balance of the other account (-4)" << currentA <<  endl;
	
	currentC = bank.getAccount()[2]->getBalance();
	bank.getAccount()[2]->deposit(555, "11-04-18");

	if(bank.getAccount()[2]->getBalance()  == currentC) 
		cout << "Error in deposit to the account (-4)" << endl;

	Transaction t(bank.getAccount()[0], bank.getAccount()[2], 500, "12-04-18");

	if (bank.getAccount()[0]->addTransaction(t) == false)
		cout << "Error in adding a new transaction to the account (-4)" << endl;
	
	if (bank.getAccount()[0]->getNumOfTransaction() !=2 )
		cout << "Error in numer of transaction (-4)"   << endl;
	
	if (bank.getAccount()[2]->getNumOfTransaction() !=2)
		cout << "Error in numer of transaction (-4)" << endl;

	/*****************************E**************************************/
	countNumberOfAccount = bank.getNumberOfAccount();
	countNumberOfUsers = account.getTotalPersons();
	
	if (account.deletePerson(lior, 1) == false)
		cout << "Error in deleting a person (-4)" << endl;
	
	if (countNumberOfAccount != bank.getNumberOfAccount())
		cout << "Error in updating nubmer of account in the bank(-4)" << endl;
	
	if (countNumberOfUsers == account.getTotalPersons())
		cout << "Error in updating nubmer of persons in the account(-4)" << endl;

	if (bank.deletePerson(liam) != false)
		cout << "Error in deleting a person (-4)" << endl;

	if (bank.addAccount(Account(liam, 1, 9955)) == false)
		cout << "Error in adding a new account to the bank (-4)" << endl;

	if (bank.addAccount(account) == false)
		cout << "Error in adding an account to the bank(-4)" << endl;

	countNumberOfAccount = bank.getNumberOfAccount();

	if (bank.deletePerson(liam) == false)
		cout << "Error in deleting a person (-4)" << endl;

	if (countNumberOfAccount == bank.getNumberOfAccount())
		cout << "Error in updating nubmer of account in the bank(-4)" << endl;

	cout << "done" << endl;
	return 0;
}