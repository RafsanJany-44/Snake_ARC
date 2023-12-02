#include <iostream>

class BankTransaction {
private:
    double balance;

public:
    // Constructor to initialize the balance
    BankTransaction(double initialBalance = 0.0) : balance(initialBalance) {}

    // Method to perform a deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: $" << balance << std::endl;
        } else {
            std::cerr << "Error: Invalid deposit amount\n";
        }
    }

    // Method to perform a withdrawal
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;
        } else {
            std::cerr << "Error: Invalid withdrawal amount or insufficient funds\n";
        }
    }

    // Method to get the current balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Create an instance of the BankTransaction class
    BankTransaction account(1000.0);  // Initial balance of $1000.0

    // Perform transactions
    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(900.0);  // This withdrawal will fail due to insufficient funds

    // Display the final balance
    std::cout << "Final Balance: $" << account.getBalance() << std::endl;

    return 0;
}
