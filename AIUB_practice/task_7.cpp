#include <iostream>
#include <string>

class Employee {
private:
    std::string employeeName;
    int employeeID;
    double salary;

public:
    // Constructor
    Employee(const std::string& name, int id, double initialSalary)
        : employeeName(name), employeeID(id), salary(initialSalary) {}

    // Method to give a salary raise
    void giveSalaryRaise(double percentage) {
        if (percentage > 0) {
            double raiseAmount = salary * (percentage / 100.0);
            salary += raiseAmount;
            std::cout << "Salary raise of " << percentage << "% given. New salary: $" << salary << std::endl;
        } else {
            std::cerr << "Error: Invalid percentage for salary raise\n";
        }
    }

    // Method to display employee information
    void displayEmployeeInfo() const {
        std::cout << "Employee ID: " << employeeID << "\n";
        std::cout << "Employee Name: " << employeeName << "\n";
        std::cout << "Salary: $" << salary << "\n";
    }
};

int main() {
    // Create an instance of the Employee class
    Employee emp("John Doe", 12345, 50000.0);

    // Display employee information
    emp.displayEmployeeInfo();

    // Give a salary raise of 10%
    emp.giveSalaryRaise(10.0);

    // Display updated employee information
    emp.displayEmployeeInfo();

    return 0;
}
