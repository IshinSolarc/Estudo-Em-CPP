#include <iostream>
#include <list>
#include <fstream>
#include <istream>
#include <sstream>
#include <iomanip>

#include "Person.h"
#include "HashTable.h"

void initTableData(HashTable& Mytable)
{
    std::ifstream dataFile;
    dataFile.open("data.bin");
    if(!dataFile.is_open())
        return;
    
    std::string name;
    int age;
    int id;
    while(true)
    {
        std::getline(dataFile, name);

        if(dataFile >> std::quoted(name) >> age >> id)
            Mytable.insertUser(Person(name, age, id));
        else
            break;
    }
}

void attTableFile(HashTable& Mytable)
{
    std::ofstream dataFile;
    dataFile.open("data.bin");
    dataFile.clear();

    std::list<Person> Users = Mytable.getUserList();

    for(auto X : Users)
    {
        dataFile << "\"" << X.name << "\"" << " " << X.age << " " << X.id << std::endl;
    }
}

void toInsertNewUser(HashTable& Mytable)
{
    system("cls || clear");
    std::string name;
    int age;
    int id;

    std::cout << "Insert new user's name: ";
    std::cin.sync();
    std::getline(std::cin,name);

    std::cout << "Insert new user's age: ";
    std::cin >> age;

    std::cout << "Insert new user's id: ";
    std::cin >> id;

    bool result = Mytable.insertUser(Person(name, age, id));

    if(result)
        std::cout << std::endl << "User inserted successfully" << std::endl;
    else
        std::cout << std::endl << "Failed to insert user - ID in use" << std::endl;
    
    attTableFile(Mytable);
    system("pause");
}

void toDeleteUser(HashTable& Mytable)
{
    system("cls || clear");
    std::list<Person> Users = Mytable.getUserList();
    int i = 1;
    for(auto X_user : Users)
    {

        std::cout << i << " - ID: " << X_user.id << " - Name: " << X_user.name << " - ID: " << X_user.id << std::endl;
        i++; 
    }
    int choice;
    std::cout << "Which user do you choose: ";
    std::cin >> choice;

    auto Iterador = Users.begin();

    std::advance(Iterador, choice-1);
    try
    {
        Mytable.removeUser(*Iterador);
    }
    catch(const std::exception& Failed)
    {
        return;
    }

    std::cout << std::endl << "User deleted successfully" << std::endl;
    attTableFile(Mytable);
    system("pause");
}

int main(int argc, char ** argv)
{
    HashTable MyTable;
    initTableData(MyTable);
    
    while(true)
    {
        system("cls || clear");
        std::cout << "Welcome To Ishin DB" << std::endl << std::endl;

        std::cout << "1 - Insert new user" << std::endl;
        std::cout << "2 - Delete a user" << std::endl;
        std::cout << "3 - See user list" << std::endl;
        std::cout << "0 - Quit the program" << std::endl;
        std::cout << "Make your choice: " << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice)
        {
            case 0:
                {
                    return 0;
                }break;

            case 1:
                {
                    toInsertNewUser(MyTable);
                }break;

            case 2:
                {
                    toDeleteUser(MyTable);
                }break;
            case 3:
                {
                    system("cls || clear");
                    MyTable.printTable();
                    system("pause");
                }break;
        }

    }


    return 0;
}