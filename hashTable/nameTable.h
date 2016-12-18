#ifndef NAME_TABLE_H
#define NAME_TABLE_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

#define MAX_SIZE 100

struct Person {
public:
    std::string name;
    bool male;
    int id;

    Person(std::string _name, bool _male, int _id) :\
        name(_name), male(_male), id(_id) {}
};

class table {
public:
    table();

    ~table();

    bool insert(Person *person);

    bool erase(std::string name);

    int search(std::string names);

    void showTable();

    Person* getAPerson(int order);

    static int nameToInt(std::string &names);  // transform names to hash number

    int getSize();

private:
    Person *hashTable[MAX_SIZE];
    int size;
};

#endif

