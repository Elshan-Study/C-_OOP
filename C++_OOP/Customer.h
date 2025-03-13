#pragma once
#include "BankAccount.h"
#include <string.h>
#include <iostream>
#include <ctime>

class Customer
{
private:
    char* _name;
    char* _surname;
    BankAccount account;

    void copyString(char*& dest, const char* src);

public:
    Customer();
    Customer(const char* name, const char* surname, double balance);
    explicit Customer(const char* name, double balance);
    Customer(const Customer& other);
    Customer(Customer&& other) noexcept;
    ~Customer();

    const char* getName() const;
    const char* getSurname() const;

    void setName(const char* name);
    void setSurname(const char* surname);

    void TransactionWrite(const char* filename, const char* action, double money);
    void BalanceReplenish(double money);
    double WithdrawMoney(double money);
    double CurrentBalance();
    char* NameAndSurname();
    void ChangeName(const char* name);
    void ChangeSurname(const char* surname);
    double TransitMoney(const char* filename, double money, Customer& other);
    void FullInfo();
    bool CheckBalance(double money);
};
