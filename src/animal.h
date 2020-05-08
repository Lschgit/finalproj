#ifndef ANIMAL_H
#define ANIMAL_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class animal
{
private:
    std::string animalName;
    std::string personalityType;
    std::string animalType;
    std::string animalBreed;
    long animalId;
    double animalPrice;
    int animalAge;

    //will have more stuff here later
public:
    animal();
    void setName(std::string animalName);
    std::string getName() const;
    void setPersonality(std::string personalityType);
    std::string getPersonality() const;
    void setType(std::string animalType);
    std::string getType() const;
    void setId(long animalId);
    long getId() const;
    void setPrice(double animalPrice);
    double getPrice();
    void setAge(int animalAge);
    int getAge();
    void setBreed(std::string animalBreed);
    std::string getBreed() const;

};

#endif // ANIMAL_H
