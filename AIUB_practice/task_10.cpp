#include <iostream>
#include <cstdlib>
#include <ctime>

class Dice {
public:
    // Constructor to seed the random number generator
    Dice() {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    // Method to simulate rolling a six-sided die
    int roll() const {
        // Generate a random number between 1 and 6
        return (std::rand() % 6) + 1;
    }
};

int main() {
    // Create an instance of the Dice class
    Dice sixSidedDie;

    // Simulate rolling the die and print the result
    for (int i = 0; i < 5; ++i) {
        int result = sixSidedDie.roll();
        std::cout << "Roll #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
