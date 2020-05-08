#include <iostream>
#include <vector>
#include <QDebug>
#include <fstream>
#include "client.h"
#include "shop.h"
#include "animal.h"
#include "cat.h"
#include "dog.h"
#include <limits>

#include <QCoreApplication>
#include <fstream>
#include <QDebug>

#include <iomanip>

using namespace std;

    shop myShop(0);

    /*
     *
     * SHOP DECLARATION
     *
     *
     */

    std::fstream& goToLine(std::fstream& file, unsigned int num){//goes to a chosen line in the text file
        file.seekg(std::ios::beg);
        for(int i=0; i < num - 1; ++i){
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        return file;
    }

void openFile(string FILE_NAME){//opens file
    fstream file;
    ifstream fin(FILE_NAME);

    if (fin.is_open()) {//checks if the file can be opened
        cout << "File opened.";
    }else{
        throw "Error: File not found";
    }
}

void setShopName(){//gets a random name from the jsonplaceholder website's users

    const string FILE_NAME = "../../finalproj/src/shopstuff.txt";

     try {
        cout << "Opening file..." << endl;
        openFile(FILE_NAME);
     } catch (const char* exStr) {
        cout << exStr << endl;
     }


    try {
        cout << endl << "Trying to connect to server..." << endl;
        Client client;

        int postId = rand() % 10 + 1;
        unique_ptr<User> user = client.request(postId);
        myShop.setName(user->name);




    } catch (const char* exStr) {

        cout << exStr << endl;

    }
}

void setShopPetTypes(){//the types of pets the shop sells
    myShop.insertPetType("Dog");
    myShop.insertPetType("Cat");
}

void setAnimalName(animal &tempAnimal){//picks a random name from the text file and gives to the pet, name list from -> https://www.petplace.com/article/dogs/pet-care/top-1200-pet-names/
    string line;
    const string FILE_NAME = "../../finalproj/src/shopstuff.txt";
    fstream myfile (FILE_NAME);
    const int FILELENGTH = 1201;
    int randomLine = rand() % FILELENGTH + 1;
    if (myfile.is_open()){
        goToLine(myfile, randomLine);
        string tempLine;
        myfile >> tempLine;
        tempAnimal.setName(tempLine);
    }

}

void setAnimalPersonality(animal &tempAnimal){//sets the animal's personaly to a randomly chosen type
    int randomInt = rand() % 5;
    string personalityType[] = {"Outgoing", "Shy", "Playful", "Aggressive", "Neutral"};
    tempAnimal.setPersonality(personalityType[randomInt]);
}

void setAnimalPrice(animal &tempAnimal){//gives the animal a random price, from 1 to 501 dollars.
    double randomDoub = rand() % 50000 + 100;
    randomDoub /= 100;
    tempAnimal.setPrice(randomDoub);
}

void setAnimalAge(animal &tempAnimal){//sets the animal's age to a random number between 1 and 16
    int randomInt = rand() % 15 + 1;
    tempAnimal.setAge(randomInt);
}

void setCatBreed(cat &tempAnimal){//sets the cat breed to a randomly chosen breed
    string breedType[] = {"Abyssinian","American Shorthair","Bengal","Bombay","Egyptian Mau","Himalayan","Maine Coon",
                          "Manx","Oriental","Persian","Russian Blue","Siamese","Turkish Van"};
    int randomInt = rand() % breedType->length();
    tempAnimal.setBreed(breedType[randomInt]);
    }

void setDogBreed(dog &tempAnimal){//sets the dog breed to a randomly chosen breed
    string breedType[] = {"Airedale Terrier","Akita","American Bulldog","American Cocker Spaniel","American Foxhound","American Staffordshire Terrier","Australian Cattle Dog",
                         "Australian Shepherd","Basset Hound","Beagle","Belgian Shepherd Dog","Black and Tan Coonhound","Border Collie","Boston Terrier","Bull Terrier",
                         "Chihuahua","Chow Chow","Collie","Dachshund","Dalmatian","Doberman Pinscher","English Bulldog","English Pointer","German Shepherd","Golden Retriever",
                         "Great Dane","Great Pyrenees","Greyhound","Jack-russell Terrier","Labrador Retriever","Leopard Dog","Maltese","Mastiff","Mixed","Pomeranian","Poodle",
                         "Pug","Rat Terrier","Rottweiler","Shih-tzu","Siberian Husky","Yorkshire Terrier"};
    int randomInt = rand() % breedType->length();
    tempAnimal.setBreed(breedType[randomInt]);
    }


void setAnimalDetails(animal &tempAnimal){//sets all the animal details
    setAnimalName(tempAnimal);
    setAnimalPersonality(tempAnimal);
    setAnimalPrice(tempAnimal);
    setAnimalAge(tempAnimal);
}

void setShopAnimals(){//generates a random amount of dogs(4 to 20) and cats(3 to 17).
    int numberofDogs = rand() % 16 + 4;
    int numberofCats = rand() % 14 + 3;

    for(int i = 0; i < numberofDogs; i++){//generates all the dogs and sets all of their attributes, then inserts them into the shop's catalog
        dog tempDog;
        tempDog.setId(i);
        tempDog.setType("Dog");
        setAnimalDetails(tempDog);
        setDogBreed(tempDog);
        myShop.insertAnimal(tempDog);
    }

    for(int i = 0; i < numberofCats; i++){//generates all the cats and sets all of their attributes, then inserts them into the shop's catalog
        cat tempCat;
        tempCat.setId(i);
        tempCat.setType("Cat");
        setAnimalDetails(tempCat);
        setCatBreed(tempCat);
        myShop.insertAnimal(tempCat);
    }

}

void printAnimals(int i){//prints an animal's attributes based on the input
    std::vector<animal> animalVector = myShop.getAllAnimals();
        cout << "Animal # " << i + 1 << ": " << animalVector[i].getType() << endl;
        cout << "Name: " << animalVector[i].getName() << endl;
        cout << "Breed: " << animalVector[i].getBreed() << endl;
        cout << "Personality: " << animalVector[i].getPersonality() << endl;
        cout << "Age: " << animalVector[i].getAge() << endl;
        cout << "Price: $" << animalVector[i].getPrice() << endl;
        cout << endl;
}

void setShopDetails(int id){//sets all the shop details
    setShopName();
    setShopPetTypes();
    setShopAnimals();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned) time(0));
    setShopDetails(0);
    double balance = rand() % 500 + 800;
    int tempInt = 0;
    std::vector<animal> boughtAnimalsVector;
    std::vector<std::string> petTypes = myShop.getPetTypes();

    cout << "Your balance is: $" << balance << endl;
    cout << "Welcome to " << myShop.getName() <<"'s pet shop!" << endl << endl;
    cout << "Currently the types of animals we sell are: ";
    for(int i = 0; i < petTypes.size(); i++){//loops through all the pet types
        cout << petTypes[i];
        if(i + 1 < petTypes.size()){
            cout << ", ";
        }
    }
    cout << endl;


    while(tempInt == 0){
        cout << "Enter a number: " << endl;
        cout << "1. View all Dogs" << endl;
        cout << "2. View all Cats" << endl;
        cout << "3. Generate new pets" << endl;
        cout << "4. Buy a pet" << endl;
        cout << "5. View purchased pets" << endl;
        cout << "6. Exit Application" << endl;
        cin >> tempInt;

        std::vector<animal> animalVector = myShop.getAllAnimals();
        switch(tempInt){
        case 1:
             for(int i = 0; i < animalVector.size(); i++){//loops through all the dogs and prints them
                 if(animalVector[i].getType() == "Dog"){
                     printAnimals(i);
                 }
             }
             tempInt = 0;
             break;
        case 2:
             for(int i = 0; i < animalVector.size(); i++){//loops through all the cats and prints them
                 if(animalVector[i].getType() == "Cat"){
                     printAnimals(i);
                 }
             }
             tempInt = 0;
             break;
        case 3://deletes all the shop's animals, then generates new ones
            myShop.clearAnimals();
            setShopAnimals();
            tempInt = 0;
            cout << "The shop now has a new selection of animals!" << endl;
            break;
        case 4://buys an animal
            int numbInput;
            cout << "Please enter the Animal # you want: ";
            cin >> numbInput;
            numbInput--;
            if(balance >= animalVector[numbInput].getPrice()){
            balance -= animalVector[numbInput].getPrice();
            cout << animalVector[numbInput].getName() << " has been bought! Your balance is now $" << balance << endl;
            boughtAnimalsVector.push_back(myShop.getAnimal(numbInput));
            myShop.buyAnimal(numbInput);
            }else{
                cout << "Animal too expensive, please try again." << endl;
            }
            tempInt = 0;
            break;
        case 5:
            for(int i = 0; i < boughtAnimalsVector.size(); i++){//loops through the animals purchased vector
                cout << "Name: " << boughtAnimalsVector[i].getName() << " the " << boughtAnimalsVector[i].getType() << endl;
                cout << "Breed: " << boughtAnimalsVector[i].getBreed() << endl;
                cout << "Personality: " << boughtAnimalsVector[i].getPersonality() << endl;
                cout << "Age: " << boughtAnimalsVector[i].getAge() << endl;
                cout << "Price at purchase: $" << boughtAnimalsVector[i].getPrice() << endl;
                cout << endl;
            }
            tempInt = 0;
            break;
        case 6://exits the application
            return 0;
            break;
        default :
           cout << "Invalid selection, please try again." << endl;
           tempInt = 0;
        }

    }

}
