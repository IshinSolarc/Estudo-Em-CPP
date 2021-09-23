#ifndef PERSON_H
#define PERSON_H

#include <iostream>
class Person{
    public:
        std::string name;
        int age;
        int id;
        Person(std::string _name, int _age, int _id);

        bool operator==(Person UserB);

        bool operator < (Person UserB);
};

#endif