#include "Customer.h"

void Customer::copyString(char*& dest, const char* src)
{
    delete[] dest;
    if (src)
    {
        dest = new char[strlen(src) + 1];
        strcpy_s(dest, strlen(src) + 1, src);
    }
    else
    {
        dest = new char[20];
        strcpy_s(dest, 20, "Unknown");
    }
}

Customer::Customer()
{
    _name = new char[20];
    _surname = new char[20];
    strcpy_s(_name, 20, "Unknown");
    strcpy_s(_surname, 20, "Unknown");
    account.setBalance(0);
}

Customer::Customer(const char* name, const char* surname, double balance)
{
    _name = nullptr;
    _surname = nullptr;
    setName(name);
    setSurname(surname);
    account.setBalance(balance);
}

Customer::Customer(const char* name, double balance)
{
    _name = nullptr;
    _surname = nullptr;
    setName(name);
    setSurname("Unknown");
    account.setBalance(balance);
}

Customer::Customer(const Customer& other)
{
    _name = nullptr;
    _surname = nullptr;
    copyString(_name, other._name);
    copyString(_surname, other._surname);
    account.setBalance(other.account.getBalance());
}

Customer::Customer(Customer&& other) noexcept
{
    _name = other._name;
    _surname = other._surname;
    account.setBalance(other.account.getBalance());
    other._name = nullptr;
    other._surname = nullptr;
    other.account.setBalance(0);
}

Customer::~Customer()
{
    delete[] _name;
    delete[] _surname;
}

const char* Customer::getName() const { return _name; }
const char* Customer::getSurname() const { return _surname; }

void Customer::setName(const char* name) { copyString(_name, name); }
void Customer::setSurname(const char* surname) { copyString(_surname, surname); }

void Customer::TransactionWrite(const char* filename, const char* action, double money)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "a");
    if (err != 0 || file == nullptr)
    {
        perror("Error opening file");
        return;
    }

    time_t now = time(nullptr);
    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &now);
    timeStr[strlen(timeStr) - 1] = '\0';  // Убираем \n из конца строки

    fprintf(file, "%s: %.2f, Balance: %.2f, Date: %s\n", action, money, account.getBalance(), timeStr);

    fclose(file);
}

void Customer::BalanceReplenish(double money)
{
    account.ReplenishBalance(money);
    TransactionWrite("transactions.txt", "Deposit", money);
}

double Customer::WithdrawMoney(double money)
{
    if (account.Withdraw(money) == -1 || money <= 0)
        return -1;

    TransactionWrite("transactions.txt", "Withdraw", money);
    return money;
}

double Customer::CurrentBalance()
{
    return account.getBalance();
}

char* Customer::NameAndSurname()
{
    char* fullName = new char[strlen(_name) + strlen(_surname) + 2];
    strcpy_s(fullName, strlen(_name) + 1, _name);
    strcat_s(fullName, strlen(_name) + 2, " ");
    strcat_s(fullName, strlen(_name) + strlen(_surname) + 2, _surname);
    return fullName;
}

void Customer::ChangeName(const char* name)
{
    setName(name);
}

void Customer::ChangeSurname(const char* surname)
{
    setSurname(surname);
}

double Customer::TransitMoney(const char* filename, double money, Customer& other)
{
    if (WithdrawMoney(money) == -1)
        return -1;

    other.BalanceReplenish(money);
    TransactionWrite(filename, "Transfer", money);
    return money;
}

void Customer::FullInfo()
{
    std::cout << "Name: " << _name << "\nSurname: " << _surname
        << "\nBalance: " << account.getBalance() << "\n";
}

bool Customer::CheckBalance(double money)
{
    return account.getBalance() >= money;
}
