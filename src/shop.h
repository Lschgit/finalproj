#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>


class shop
{
private:
    std::vector<std::string> petType;
    //will have more stuff here later
public:
    shop();
    void insertPetType(std::string input);
    std::string checkPetTypes(std::string input);
};

#endif // SHOP_H
