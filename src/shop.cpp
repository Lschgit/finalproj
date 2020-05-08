#include "shop.h"

shop::shop(long shopId)
{
    this->shopId = shopId;
}





void shop::insertPetType(std::string input){//inserts pet type into the shop's list of pet types
    petType.push_back(input);
}

std::string shop::checkPetTypes(std::string input){//checks if the input matches any elements in the vector
    for(int i = 0; i < petType.size(); i++){
        if(petType.at(i) == input){
            i = petType.size();
            return input;
        }
    }
    return "0";
}

std::vector<std::string> shop::getPetTypes(){
    return petType;
}

void shop::insertAnimal(animal animalInput){
    animals.push_back(animalInput);
}

void shop::buyAnimal(int input){
    animals.erase(animals.begin() + input);

}

void shop::clearAnimals(){
    animals.clear();
}

animal shop::getAnimal(long animalId){
    return animals.at(animalId);
}

std::vector<animal> shop::getAllAnimals(){
    return animals;
}

long long shop::getId() const {
    return shopId;
}

void shop::setId(long shopId) {
    this->shopId = shopId;
}

std::string shop::getName() const {
    return shopName;
}

void shop::setName(std::string shopName) {
    this->shopName = shopName;
}


