#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include "animal.h"

class shop
{
private:
    std::vector<std::string> petType;
    std::vector<animal> animals = {};
    long shopId;
    std::string shopName;
    //will have more stuff here later
public:
    shop(long shopId);
    void insertPetType(std::string input);//aka setPetType
    std::string checkPetTypes(std::string input);
    std::vector<std::string> getPetTypes();
    void insertAnimal(animal animalInput);
    void buyAnimal(int input);
    void clearAnimals();
    animal getAnimal(long animalId);
    std::vector<animal> getAllAnimals();
    long long getId() const;
    void setId(long shopId);
    std::string getName() const;
    void setName(std::string shopName);
};

#endif // SHOP_H
