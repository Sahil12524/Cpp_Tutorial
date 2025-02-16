/*
    This program only demonstrates the basic function of an ATM machine and is nowhere near to a real
    ATM machine.
    This program is not related to security and various complex operations.
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>

struct UserData
{
    int acNumber;
    int acPin;
    std::string usrName;
    long double balance;
};

// Function Prototypes
UserData usrData();
UserData *isLogin();
void Exit();
void showMainMenu(UserData &user);
void bankingMenu(UserData &user);
void fetchBalance(const UserData &user);
void depositMoney(UserData &user);
void WithdrawMoney(UserData &user);
void clearScreen();

int main()
{
    clearScreen();
    UserData user = usrData(); // Initialize user data once
    showMainMenu(user);
    return 0;
}

UserData usrData()
{
    return {78945132, 1234, "Sahil", 1638400.0};
}

UserData *isLogin()
{
    static UserData user = usrData(); // Maintain persistent user data
    clearScreen();
    std::cout << "********* Login *********\n";
    int inputAcNumber, inputAcPin;

    while (true)
    {
        std::cout << "\nEnter Account Number: ";
        std::cin >> inputAcNumber;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! Please enter numbers only.\n";
            continue;
        }

        std::cout << "Enter PIN: ";
        std::cin >> inputAcPin;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! Please enter numbers only.\n";
            continue;
        }

        if (inputAcNumber == user.acNumber && inputAcPin == user.acPin)
        {
            std::cout << "\nLogin successful! Welcome, " << user.usrName << "!\n";
            return &user;
        }
        else
        {
            std::cout << "\nLogin failed. Invalid credentials. Try again.\n";
        }
    }
}

void Exit()
{
    std::cout << "\nGoodbye!\n";
}

void showMainMenu(UserData &user)
{
    unsigned short int optn;
    bool login = false;

    while (true)
    {
        std::cout << "********* Maze Bank *********\n";
        std::cout << "\nWelcome to the ATM, please choose login to begin with!\n";
        std::cout << "1. Login\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter the option: ";
        std::cin >> optn;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! Please enter 1 or 0.\n";
            continue;
        }

        switch (optn)
        {
        case 0:
            Exit();
            return;
        case 1:
            if (login)
            {
                std::cout << "\nAlready logged in.\n";
                bankingMenu(user);
            }
            else
            {
                UserData *loggedInUser = isLogin();
                if (loggedInUser)
                {
                    login = true;
                    bankingMenu(*loggedInUser);
                }
            }
            break;
        default:
            std::cerr << "\nNo such option found!\n";
            break;
        }
    }
}

void bankingMenu(UserData &user)
{
    unsigned short int optn;
    while (true)
    {
        std::cout << "********* Banking Menu *********\n";
        std::cout << "\n1. Fetch Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "0. Main Menu\n";
        std::cout << "Enter the option: ";
        std::cin >> optn;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }

        switch (optn)
        {
        case 0:
            return;
        case 1:
            fetchBalance(user);
            break;
        case 2:
            depositMoney(user);
            break;
        case 3:
            WithdrawMoney(user);
            break;
        default:
            std::cerr << "\nNo such option found!\n";
            break;
        }
    }
}

void fetchBalance(const UserData &user)
{
    std::cout << "\nYour Balance: Rs." << std::fixed << std::setprecision(2) << user.balance << "\n";
}

void depositMoney(UserData &user)
{
    long double amount = 0;
    while (true)
    {
        std::cout << "Enter amount to deposit: Rs.";
        std::cin >> amount;

        if (std::cin.fail() || amount <= 0)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cerr << "\nEnter a valid positive amount!\n";
        }
        else
        {
            break;
        }
    }

    user.balance += amount;
    std::cout << "\nDeposit successful!\n";
    fetchBalance(user);
}

void WithdrawMoney(UserData &user)
{
    long double amount = 0;
    while (true)
    {
        std::cout << "Enter amount to withdraw: Rs.";
        std::cin >> amount;

        if (std::cin.fail() || amount <= 0)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cerr << "\nEnter a valid positive amount!\n";
        }
        else if (user.balance < amount)
        {
            std::cerr << "\nInsufficient balance. Try again.\n";
        }
        else
        {
            break;
        }
    }

    user.balance -= amount;
    std::cout << "\nWithdrawal successful!\n";
    fetchBalance(user);
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
