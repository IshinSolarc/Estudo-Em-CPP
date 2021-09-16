#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Person{
    public:
        string name;
        int age;
        int id;
        Person(string _name, int _age, int _id)
        {
            name = _name;
            age = _age;
            id = _id;
        }

        bool operator==(Person UserB)
        {
            if(UserB.name == name && UserB.age == age && UserB.id == id)
                return true;
            else
                return false;
        }
};

class HashTable{
    private:

    static const int table_size = 50;
    list <Person> table[table_size];

    public:
        bool isEmpty()
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

        int hashFunction(string name)
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

        void insertUser(Person User)
        {
            int key = hashFunction(User.name);
            table[key].push_back(User); 
        }

        void removeUser(Person User)
        {
            if(isThereUser(User))
            {
                int key = hashFunction(User.name);
                table[key].remove(User);
            }
            return;
        }

        bool isThereUser(Person User)
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

};

int main(int argc, char ** argv)
{
    Person Ronaldo("Ronaldo", 5, 20);
    HashTable Minha_Mesa;

    Minha_Mesa.insertUser(Ronaldo);

    cout << Minha_Mesa.isThereUser(Ronaldo) << endl;

    Minha_Mesa.removeUser(Ronaldo);

    cout << Minha_Mesa.isThereUser(Ronaldo) << endl;


    return 0;
}
