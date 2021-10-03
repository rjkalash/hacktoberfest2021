#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Bank
{
private:
    int balance;
    int amount;
    int withdraw;
    int transfer;
    char name[100];
    char reason[100];
    char address[100];
    char aadharNo[100];
    char accountType[100];

public:
    void openAccount();
    void closeAccount();
    void depositAmount();
    void withdrawAmount();
    void displayAccount();
};

void Bank::openAccount()
{
    cout << "Enter Your Name For Bank Account : " << endl;
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter Your Address For Bank Account : " << endl;
    cin.ignore();
    cin.getline(address, 100);
    cout << "Enter Your Aadhar Number For Bank Account : " << endl;
    cin.ignore();
    cin.getline(aadharNo, 100);
    cout << "Enter Your Account Type (Savings Or Current) For Bank Account : " << endl;
    cin >> accountType;
    cout << "Enter The Balance Amount You Want To Keep For Bank Account : " << endl;
    cin >> balance;
}

void Bank::closeAccount()
{
    cout << "Enter The Reason Why You Want To Close Your Bank Account?" << endl;
    cin >> reason;
    cout << "Your Balance Amount " << balance << " Will Be Transferred To Other Specified Account" << endl;
}

void Bank::displayAccount()
{
    cout << "Your Name For Bank Account : " << name << endl;
    cout << "Your Address For Bank Account : " << address << endl;
    cout << "Your Aadhar Number For Bank Account : " << aadharNo << endl;
    cout << "Your Account Type For Bank Account : " << accountType << endl;
    cout << "Balance Amount In Bank Account : " << balance << endl;
}

void Bank::depositAmount()
{
    cout << "Enter The Amount You Want To Deposit In Your Account : " << endl;
    cin >> amount;
    cout << "Initial Balance Amount Is : " << balance << endl;
    balance += amount;
    cout << "Amount Added Successfully In Account" << endl;
    cout << "Renewed Amount Balance In Account Is " << balance << endl;
}

void Bank::withdrawAmount()
{
    cout << "Enter The Amount You Want To Withdraw : " << endl;
    cin >> withdraw;
    cout << "Initial Balance Amount Is : " << balance << endl;
    balance -= withdraw;
    cout << "Amount Is Withdrawn Easily : " << endl;
    cout << "Renewed Amount Balance In Account Is " << balance << endl;
}

int main()
{
    int ch;
    char choice;
    Bank b;
    do
    {
        cout << "\n****************** Welcome To Bank Management Sytem ******************" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Close Account" << endl;
        cout << "3. Display Account Details" << endl;
        cout << "4. Deposit Amount" << endl;
        cout << "5. Withdraw Amount" << endl;
        cout << "6. Exit From Bank" << endl;
        cout << "Enter Your Choice Out Of Below Given " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.openAccount();
            break;
        case 2:
            b.closeAccount();
            break;
        case 3:
            b.displayAccount();
            break;
        case 4:
            b.depositAmount();
            break;
        case 5:
            b.withdrawAmount();
            break;
        case 6:
            cout << "Exited From Program!!" << endl;
            break;
        default:
            cout << "You Entered Wrong Choice. Try Again!" << endl;
        }
        cout << "Do You Want To Continue? If Yes Press (Y/y)" << endl;
        cout << "If No Press (N/n)" << endl;
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            cout << "Exited From Program!!" << endl;
            exit(0);
        }
    } while (choice == 'y' || choice == 'Y');
    return 0;
}