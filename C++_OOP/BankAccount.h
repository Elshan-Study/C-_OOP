#pragma once
class BankAccount
{
private:
	double _balance;
public:
	BankAccount();
	explicit BankAccount(double balance);
	BankAccount(const BankAccount& other);
	BankAccount(BankAccount&& other) noexcept;

	void setBalance(double balance);
	double getBalance() const;
	void ReplenishBalance(double money);
	double Withdraw(double money);
	~BankAccount();
};

