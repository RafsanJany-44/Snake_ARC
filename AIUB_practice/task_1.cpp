#include <iostream>

class TemperatureConverter {
public:
    // Constructor
    TemperatureConverter() {}

    // Method to convert Celsius to Fahrenheit
    double celsiusToFahrenheit(double celsius) {
        return (celsius * 9 / 5) + 32;
    }

    // Method to convert Fahrenheit to Celsius
    double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }
};

int main() {
    TemperatureConverter converter;

    // Example: Convert Celsius to Fahrenheit
    double celsiusTemperature = 25.0;
    double fahrenheitResult = converter.celsiusToFahrenheit(celsiusTemperature);
    std::cout << celsiusTemperature << " Celsius is equal to " << fahrenheitResult << " Fahrenheit\n";

    // Example: Convert Fahrenheit to Celsius
    double fahrenheitTemperature = 77.0;
    double celsiusResult = converter.fahrenheitToCelsius(fahrenheitTemperature);
    std::cout << fahrenheitTemperature << " Fahrenheit is equal to " << celsiusResult << " Celsius\n";

    return 0;
}