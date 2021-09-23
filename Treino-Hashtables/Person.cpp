#include "Person.h"

Person :: Person(std::string _name, int _age, int _id)
{
    name = _name;
    age = _age;
    id = _id;
}

bool Person :: operator==(Person UserB)
{
    if(UserB.name == name && UserB.age == age && UserB.id == id)
        return true;
    else
        return false;
 }

bool Person :: operator < (Person UserB)
{
    if(id < UserB.id)
        return true;
    else
        return false;
}