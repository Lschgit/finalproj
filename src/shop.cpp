#include "shop.h"

shop::shop()
{

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

long long shop::getId() const {
    return shopId;
}

void shop::setId(long shopId) {
    this->shopId = shopId;
}
