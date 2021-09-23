#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Person.h"
#include <list>

class HashTable{
    private:
    static const int table_size = 101;
    std::list <Person> table[table_size];

    public:

        bool isEmpty();

        int hashFunction(std::string name);

        bool insertUser(Person User);

        void removeUser(Person User);

        bool isThereUser(Person User);

        void printTable();

        std::list<Person> getUserList();
};

#endif