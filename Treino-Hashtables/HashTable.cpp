#include "HashTable.h"

bool HashTable :: isEmpty()
{
    int sum = 0;
    for(int i = 0; i < table_size; i++)
    {
        sum = sum + table[i].size();
    }

    if(!sum)
        return true;
    else
        return false;
}

int HashTable :: hashFunction(std::string name)
{
    int size = name.length();
    int key = 0;
    for(int i = 0; i < size; i++)
    {
        int A = i * name.at(i);
        int B = name.at(i) * name.at(i);
        key = (key + A + B) % table_size; 
    }
    return key;
}

bool HashTable :: insertUser(Person User)
{
    auto Users = getUserList();
    for(auto x : Users)
    {
        if(User.id == x.id)
            return false;
    }

    int key = hashFunction(User.name);
    table[key].push_back(User); 

    return true;
}

void HashTable :: removeUser(Person User)
{
    if(isThereUser(User))
    {
        int key = hashFunction(User.name);
        table[key].remove(User);
    }
    return;
}

bool HashTable:: isThereUser(Person User)
{
    int key = hashFunction(User.name);

    for(auto User_In_Key_List = table[key].begin(); User_In_Key_List != table[key].end(); User_In_Key_List++)
    {
        Person User_Now = *User_In_Key_List;
        if(User == User_Now)
            return true;
    }

    return false;
}

void HashTable :: printTable()
{
    std::list<Person> Users_list;
    for(auto the_List : table)
    {
        for(auto Iterador : the_List)
        {
            Users_list.push_front(Iterador);
        }
    }

    Users_list.sort();

    for(auto x_user : Users_list)
    {
        std::cout << "ID: "<< x_user.id << " - Name: " << x_user.name << " - Age: " << x_user.age << std::endl; 
    }

}

std::list<Person> HashTable :: getUserList()
{
    std::list<Person> Users_list;
    for(auto the_List : table)
    {
        for(auto Iterador : the_List)
        {
            Users_list.push_front(Iterador);
        }
    }

    Users_list.sort();
            
    return Users_list;
} 