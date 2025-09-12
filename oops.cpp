#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int acctNo;
    string owner;
    double balance;
    static double interestRate;

public:
    // Default + parameterized constructor
    BankAccount(int acc = 0, string own = "", double bal = 0.0) {
        acctNo = acc;
        owner = own;
        balance = bal;
    }

    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }

    bool withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            return true;
        }
        return false;
    }

    void applyAnnualInterest() {
        balance += balance * interestRate;
    }

    double getBalance() const { return balance; }

    void printAccount() const {
        cout << "AcctNo: " << acctNo
             << " | Owner: " << owner
             << " | Balance: " << balance << endl;
    }

    static void setInterestRate(double r) { interestRate = r; }
    static double getInterestRate() { return interestRate; }

    friend bool transfer(BankAccount &from, BankAccount &to, double amt);
};

// Define static variable
double BankAccount::interestRate = 0.05;

// Friend transfer
bool transfer(BankAccount &from, BankAccount &to, double amt) {
    if (from.withdraw(amt)) {
        to.deposit(amt);
        return true;
    }
    return false;
}

int main() {
    int N;
    cout << "Enter number of accounts: ";
    cin >> N;

    // Array of objects (size decided at runtime in C++11+)
    BankAccount accounts[N];

    // Fill account details using loop
    for (int i = 0; i < N; i++) {
        int accNo;
        string owner;
        double balance;

        cout << "\nEnter details for account " << (i+1) << ":\n";
        cout << "Account No: ";
        cin >> accNo;
        cout << "Owner: ";
        cin >> owner;
        cout << "Balance: ";
        cin >> balance;

        // Reinitialize object with new values
        accounts[i] = BankAccount(accNo, owner, balance);
    }

    cout << "\n--- Account Summary ---\n";
    double total = 0;
    for (int i = 0; i < N; i++) {
        accounts[i].printAccount();
        total += accounts[i].getBalance();
    }
    cout << "Total Balance: " << total << endl;

    // Example transfer
    if (N >= 2) {
        cout << "\nTransferring 500 from Account[0] -> Account[1]\n";
        transfer(accounts[0], accounts[1], 500);
    }

    cout << "\n--- After Transfer ---\n";
    total = 0;
    for (int i = 0; i < N; i++) {
        accounts[i].printAccount();
        total += accounts[i].getBalance();
    }
    cout << "Total Balance: " << total << endl;

    return 0;
}
