#include <iostream>

class Calculator {
public:
    // Method to add two numbers
    double add(double a, double b) {
        return a + b;
    }

    // Method to subtract two numbers
    double subtract(double a, double b) {
        return a - b;
    }

    // Method to multiply two numbers
    double multiply(double a, double b) {
        return a * b;
    }

    // Method to divide two numbers (handles division by zero)
    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            std::cerr << "Error: Division by zero\n";
            return 0.0; // You can handle the error differently based on your needs
        }
    }
};

int main() {
    // Create an instance of the Calculator class
    Calculator calculator;

    // Example arithmetic operations
    double num1 = 10.0, num2 = 5.0;

    std::cout << num1 << " + " << num2 << " = " << calculator.add(num1, num2) << std::endl;
    std::cout << num1 << " - " << num2 << " = " << calculator.subtract(num1, num2) << std::endl;
    std::cout << num1 << " * " << num2 << " = " << calculator.multiply(num1, num2) << std::endl;

    // Example division with error handling
    double result = calculator.divide(num1, num2);
    if (!std::cerr) {
        std::cout << num1 << " / " << num2 << " = " << result << std::endl;
    }

    return 0;
}
