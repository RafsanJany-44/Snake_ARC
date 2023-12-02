#include <iostream>
#include <string>

class Product {
private:
    std::string productName;
    double price;
    int quantity;

public:
    // Constructor
    Product(const std::string& name, double productPrice, int productQuantity)
        : productName(name), price(productPrice), quantity(productQuantity) {}

    // Method to calculate the total value of the product in the inventory
    double calculateTotalValue() const {
        return price * static_cast<double>(quantity);
    }

    // Method to display product information
    void displayProductInfo() const {
        std::cout << "Product Name: " << productName << "\n";
        std::cout << "Price per unit: $" << price << "\n";
        std::cout << "Quantity in inventory: " << quantity << "\n";
        std::cout << "Total Value: $" << calculateTotalValue() << "\n";
    }
};

int main() {
    // Create an instance of the Product class
    Product laptop("Laptop", 1200.0, 5);

    // Display product information and total value
    laptop.displayProductInfo();

    return 0;
}
