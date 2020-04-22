#include <iostream>
#include <vector>
#include <QDebug>
#include <fstream>
#include "client.h"

#include <QCoreApplication>
#include <fstream>
#include <QDebug>

#include <iomanip>

using namespace std;

void openFile(string FILE_NAME){
    fstream file;
    ifstream fin(FILE_NAME);

    if (fin.is_open()) {//checks if the file can be opened
        file.open(FILE_NAME, ios::out);
        file << "testtext";
    }else{
        throw "Error: File not found";
    }
}

int main(int argc, char *argv[])
{

    const string FILE_NAME = "../../finalproj/src/shopstuff.txt";

     try {
        cout << "Opening file..." << endl;
        openFile(FILE_NAME);
     } catch (const char* exStr) {
        cout << exStr << endl;
     }


    QApplication a(argc, argv);


    try {
        cout << endl << "Trying to connect to server..." << endl;
        Client client;

        int postId = 2;
        unique_ptr<User> user = client.request(postId);
        cout << user->name << endl;

    } catch (const char* exStr) {

        cout << exStr << endl;

    }



}
