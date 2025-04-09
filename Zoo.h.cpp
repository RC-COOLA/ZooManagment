#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include <iostream>
#include <fstream>

class Zoo {
private:
Animal** animals;
int numAnimals;
    int maxAnimals;

void resize() {
      maxAnimals *= 2;
Animal** newArray = new Animal*[maxAnimals];
for (int i = 0; i < numAnimals; ++i) {
newArray[i] = animals[i];
    }
    delete[] animals;
    animals = newArray;
    }

public:
 Zoo() : numAnimals(0), maxAnimals(5) {
animals = new Animal*[maxAnimals];
    }

    ~Zoo() {
    for (int i = 0; i < numAnimals; ++i) {
     delete animals[i];
        }
    delete[] animals;
    }

    void addAnimal(Animal* animal) {
        if (numAnimals == maxAnimals) {
  resize();
    }
     animals[numAnimals++] = animal;
    }

void removeAnimal(const std::string& name) {
for (int i = 0; i < numAnimals; ++i) {
  if (animals[i]->getName() == name) {
     delete animals[i];
    for (int j = i; j < numAnimals - 1; ++j) {
     animals[j] = animals[j + 1];
                }
        --numAnimals;
    std::cout << name << " has been removed from the zoo." << std::endl;
    return;
     }
 }
     std::cout << "Animal not found!" << std::endl;
 }

    void displayAllAnimals() const {
        if (numAnimals == 0) {
         std::cout << "No animals in the zoo." << std::endl;
        } else {
        for (int i = 0; i < numAnimals; ++i) {
         animals[i]->displayInfo();
            }
        }
    }

    void saveToFile(const std::string& filename) const {
std::ofstream outFile(filename);
     if (outFile.is_open()) {
        for (int i = 0; i < numAnimals; ++i) {
        outFile << animals[i]->getName() << " "
        << animals[i]->getAge() << " "
        << animals[i]->getSpecies() << std::endl;
            }
         outFile.close();
        std::cout << "Zoo data saved to " << filename << std::endl;
        } else {
    std::cout << "Failed to open file." << std::endl;
        }
    }

    void loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
        if (inFile.is_open()) {
     std::string name, species;
    int age;
    while (inFile >> name >> age >> species) {
         if (species == "Mammal") {
            addAnimal(new Mammal(name, age, species));
         } else if (species == "Bird") {
         addAnimal(new Bird(name, age, species));
        } else if (species == "Reptile") {
        addAnimal(new Reptile(name, age, species));
            }
            }
         inFile.close();
            std::cout << "Zoo data loaded from " << filename << std::endl;
        } else {
            std::cout << "Failed to open file." << std::endl;
        }
    }
};

#endif