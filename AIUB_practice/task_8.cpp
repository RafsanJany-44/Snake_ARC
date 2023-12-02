#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    // Constructor
    Car(const std::string& carMake, const std::string& carModel, int carYear)
        : make(carMake), model(carModel), year(carYear) {}

    // Method to display details of the car
    void displayCarDetails() const {
        std::cout << "Make: " << make << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
    }
};

int main() {
    // Create an instance of the Car class
    Car myCar("Toyota", "Camry", 2022);

    // Display details of the car
    myCar.displayCarDetails();

    return 0;
}
