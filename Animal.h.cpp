#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

class Animal {
protected:
 std::string name;
int age;
 std::string species;

public:
    Animal(std::string name, int age, std::string species)
        :name(name), age(age), species(species) {}

    virtual ~Animal() {}

    virtual void makeSound() const = 0;
    virtual void displayInfo() const = 0;

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSpecies() const { return species; }
};

#endif