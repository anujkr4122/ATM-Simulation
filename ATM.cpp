#include <iostream>
#include <fstream>
using namespace std;

int balance = 10000;
int pin = 1234;

void loadData()
{
    ifstream file("atm.txt");

    if(file)
    {
        file >> pin >> balance;
    }

    file.close();
}

void saveData()
{
    ofstream file("atm.txt");

    file << pin << " " << balance;

    file.close();
}

void balanceEnquiry()
{
    cout << "\nCurrent Balance : Rs. " << balance << endl;
}

void deposit()
{
    int amount;

    cout << "\nEnter Deposit Amount : ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid Amount!\n";
        return;
    }

    balance += amount;

    cout << "Deposit Successful.\n";
    cout << "Updated Balance : Rs. " << balance << endl;

    saveData();
}

void withdraw()
{
    int amount;

    cout << "\nEnter Withdraw Amount : ";
    cin >> amount;

    if(amount > balance)
    {
        cout << "Insufficient Balance!\n";
    }
    else if(amount <= 0)
    {
        cout << "Invalid Amount!\n";
    }
    else
    {
        balance -= amount;

        cout << "Please Collect Your Cash.\n";
        cout << "Remaining Balance : Rs. " << balance << endl;

        saveData();
    }
}

void changePin()
{
    int oldPin, newPin;

    cout << "\nEnter Current PIN : ";
    cin >> oldPin;

    if(oldPin == pin)
    {
        cout << "Enter New PIN : ";
        cin >> newPin;

        if(newPin >= 1000 && newPin <= 9999)
        {
            pin = newPin;
            saveData();

            cout << "PIN Changed Successfully.\n";
        }
        else
        {
            cout << "PIN must be 4 digits.\n";
        }
    }
    else
    {
        cout << "Incorrect Current PIN!\n";
    }
}

int main()
{
    loadData();

    int enteredPin;

    cout << "==============================\n";
    cout << "       ATM SIMULATION\n";
    cout << "==============================\n";

    cout << "Enter ATM PIN : ";
    cin >> enteredPin;

    if(enteredPin != pin)
    {
        cout << "Invalid PIN!\n";
        return 0;
    }

    int choice;

    do
    {
        cout << "\n========== ATM MENU ==========\n";
        cout << "1. Balance Enquiry\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                balanceEnquiry();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                changePin();
                break;

            case 5:
                cout << "\nThank You for Using Our ATM.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}