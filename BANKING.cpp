#include <iostream>
#include <string>
#define RED "\033[1m\033[31m" /* Bold Red */
#define GREEN "\033[1m\033[32m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"

using namespace std;

const int MAX_TRANSACTIONS = 10;

class BankAccount
{
private:
    string accno;
    string password;
    double balance;
    string transactions[MAX_TRANSACTIONS];
    int transactionCount;

public:
    BankAccount() : balance(0.0), transactionCount(0) {}

    void signUp(const string &uname, const string &pwd)
    {
        accno = uname;
        password = pwd;
        cout << "-----------------------------------------\n";

        cout << "Account created successfully!\n";
        cout << "-----------------------------------------\n";
    }

    bool login(const string &uname, const string &pwd)
    {
        if (accno == uname && password == pwd)
        {
            cout << "-----------------------------------------\n";

            cout << "Login successful!\n";
            cout << "-----------------------------------------\n";

            return true;
        }
        else
        {
            cout << "-----------------------------------------\n";

            cout << "Invalid account no or password. Login failed!\n";
            cout << "-----------------------------------------\n";

            return false;
        }
    }

    double checkBalance()
    {
        return balance;
    }

    void addBalance(double amount)
    {
        balance += amount;
        addTransaction("Added $" + to_string(amount) + " to the account.");
    }

    bool withdrawBalance(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            addTransaction("Withdrawn $" + to_string(amount) + " from the account.");

            return true;
        }
        else
        {
            return false;
        }
    }

    void showTransactionHistory()
    {
        cout<<GREEN;
        cout << "-----------------------------------------\n";
        cout << "Transaction History:\n";
        for (int i = 0; i < transactionCount; ++i)
        {
            cout << transactions[i] << endl;
        }
        cout << "-----------------------------------------\n";
    }

private:
    void addTransaction(const string &transaction)
    {
        if (transactionCount < MAX_TRANSACTIONS)
        {
            transactions[transactionCount++] = transaction;
        }
        else
        {
            for (int i = 0; i < MAX_TRANSACTIONS - 1; ++i)
            {
                transactions[i] = transactions[i + 1];
            }
            transactions[MAX_TRANSACTIONS - 1] = transaction;
        }
    }
};

int main()
{
    BankAccount account;

    // Sign up
    string accno, password;
    cout<<"-----------YOU HAVE TO CREATE ACCOUNT FIRST---------"<<endl;
    cout << "Enter Account Number : ";
    cin >> accno;
    cout << "Enter password: ";
    cin >> password;
    account.signUp(accno, password);

    // Login
    cout<<"\n \n ----------------------------LOGIN PAGE ---------------------------\n";
    string loginaccno, loginPassword;
    cout << "Enter Account Number to login: ";
    cin >> loginaccno;
    cout << "Enter password to login: ";
    cin >> loginPassword;
    if (account.login(loginaccno, loginPassword))
    {
        // Logged in successfully, perform banking operations
        char choice;
        do
        {
            cout<<RED;
            cout << "\n ------------------------Welcome To Banking System---------------------- \n";
            cout<<"<----CHOOSE (1-5)---->\n";
            cout << "1. Check Balance\n";
            cout << "2. Add Balance\n";
            cout << "3. Withdraw Balance\n";
            cout << "4. Transaction History\n";
            cout << "5. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case '1':
            {
                double balance = account.checkBalance();
                cout << GREEN;
                            cout
                     << "-----------------------------------------\n";
                cout << "Current Balance: $" << balance << endl;
                cout << "-----------------------------------------\n";
                break;
            }
            case '2':
            {
                double amount;
                cout << "Enter amount to add: $";
                cin >> amount;
                account.addBalance(amount);
                cout << GREEN;
                cout << "-----------------------------------------\n";
                cout << amount << "$ Amount added successfully." << endl;
                cout << "-----------------------------------------\n";

                break;
            }
            case '3':
            {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (account.withdrawBalance(amount))
                {
                    cout << GREEN;

                    cout << "-----------------------------------------\n";
                    cout << amount << "$ Amount withdrawn successfully." << endl;
                    cout << "-----------------------------------------\n";
                }
                else
                {
                    cout << RED;
                    cout << "-----------------------------------------\n";
                    cout << "Insufficient balance." << endl;
                    cout << "-----------------------------------------\n";
                }
                break;
            }
            case '4':
            {
                account.showTransactionHistory();
                break;
            }
            case '5':
            {
                cout << MAGENTA;

                cout << "-----------------------------------------\n";

                cout << "Logged out successfully." << endl;
                cout << "-----------------------------------------\n";

                break;
            }
            default:
            {
                cout<<BLUE;

                cout << "-----------------------------------------\n";
                cout << "Invalid choice. Please try again." << endl;
                cout << "-----------------------------------------\n";
            }
            }
        } while (choice != '5');
    }

    return 0;
}