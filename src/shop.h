#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>


class shop
{
private:
    std::vector<std::string> petType;
    long shopId;
    std::string shopName;
    //will have more stuff here later
public:
    shop();
    void insertPetType(std::string input);
    std::string checkPetTypes(std::string input);
    long long getId() const;
    void setId(long shopId);
};

#endif // SHOP_H
