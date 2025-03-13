#include "BankAccount.h"

BankAccount::BankAccount() : _balance(0) {};
BankAccount::BankAccount(double balance)
{
	setBalance(balance);
};
BankAccount::BankAccount(const BankAccount& other) : _balance(other._balance) {};
BankAccount::BankAccount(BankAccount&& other) noexcept : _balance(other._balance)
{
	other._balance = 0;
}

void BankAccount::setBalance(double balance)
{
	if (balance < 0)
	{
		return;
	}

	_balance = balance;
}

double BankAccount::getBalance() const
{
	return _balance;
}

void BankAccount::ReplenishBalance(double money)
{
	if (money <= 0)
	{
		return;
	}

	_balance += money;

}

double BankAccount::Withdraw(double money)
{
	if (_balance - money < 0 || money <= 0)
	{
		return -1;
	}

	_balance -= money;

	return money;
}

BankAccount::~BankAccount()
{
	_balance = 0;
}
