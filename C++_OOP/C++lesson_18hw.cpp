#include <iostream>
#include "Customer.h"

void showTransactions(const char* filename)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == nullptr)
    {
        std::cout << "No transactions recorded yet.\n";
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        std::cout << line;
    }

    fclose(file);
}

void menu(Customer& customer)
{
    int choice;
    do
    {
        std::cout << "\n1. Withdraw Money\n2. Deposit Money\n3. View Balance\n4. Transfer Money";
        std::cout << "\n5.Change Name\n6.Change Surname\n7. View Name and Surname\n8.View full information\n9.View Transactions\n0.Exit\n";
        std::cin >> choice;

        double amount;
        char newName[50];
        switch (choice)
        {
        case 1:
            std::cout << "Enter amount: ";
            std::cin >> amount;
            if (customer.WithdrawMoney(amount) == -1)
            {
                std::cout << "Insufficient funds" << "\n";
            };
            break;
        case 2:
            std::cout << "Enter amount: ";
            std::cin >> amount;
            customer.BalanceReplenish(amount);
            break;
        case 3:
            std::cout << "Balance: " << customer.CurrentBalance() << "\n";
            break;
        case 4:
        {
            Customer recipient("John", "Doe", 0);
            std::cout << "Enter amount to transfer: ";
            std::cin >> amount;
            if (customer.TransitMoney("transactions.txt", amount, recipient) == -1)
            {
                std::cout << "Insufficient funds" << "\n";
            };
            break;
        }
        case 5:
            std::cout << "Enter new name: ";
            std::cin >> newName;
            customer.ChangeName(newName);
            break;
        case 6:
            std::cout << "Enter new surname: ";
            std::cin >> newName;
            customer.ChangeSurname(newName);
            break;
        case 7:
            std::cout << customer.NameAndSurname() << "\n";
            break;
        case 8:
            customer.FullInfo();
            break;
        case 9:
            showTransactions("transactions.txt");
            break;
        dafault:
            continue;
        }
    } while (choice != 0);
}

int main()
{
    Customer customer("Alice", "Smith", 1000);
    menu(customer);
    return 0;
}
