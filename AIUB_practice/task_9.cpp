#include <iostream>
#include <string>

class Animal {
private:
    std::string species;

public:
    // Constructor
    Animal(const std::string& animalSpecies) : species(animalSpecies) {}

    // Method to make the animal sound
    void makeSound() const {
        std::cout << "The " << species << " makes a sound.\n";
    }
};

int main() {
    // Create instances of the Animal class
    Animal dog("Dog");
    Animal cat("Cat");
    Animal elephant("Elephant");

    // Make sounds of the animals
    dog.makeSound();
    cat.makeSound();
    elephant.makeSound();

    return 0;
}
