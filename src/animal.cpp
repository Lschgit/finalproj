#include "animal.h"

animal::animal()
{

}


void animal::setName(std::string animalName){
    this->animalName = animalName;

}


std::string animal::getName() const{
    return animalName;
}

void animal::setPersonality(std::string personalityType){
    this->personalityType = personalityType;
}
std::string animal::getPersonality() const{
    return personalityType;
}

void animal::setType(std::string animalType){
    this->animalType = animalType;
}
std::string animal::getType() const{
    return animalType;
}

long animal::getId() const {
    return animalId;
}

void animal::setId(long animalId) {
    this->animalId = animalId;
}
void animal::setPrice(double animalPrice){
    this->animalPrice = animalPrice;
}
double animal::getPrice(){
    return animalPrice;
}

void animal::setAge(int animalAge){
    this->animalAge = animalAge;
}

int animal::getAge(){
    return animalAge;
}

void animal::setBreed(std::string animalBreed){
    this->animalBreed = animalBreed;
}

std::string animal::getBreed() const{
    return animalBreed;
}


