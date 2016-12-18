#ifndef NAME_TABLE_CPP
#define NAME_TABLE_CPP

#include "nameTable.h"

table::table() : size(0) {
    for (int i = 0; i < MAX_SIZE; ++i)
        hashTable[i] = NULL;
}

table::~table() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (hashTable[i] != NULL) {
            delete hashTable[i];
        }
    }
}

bool table::insert(Person *person) {
    if (this->size > MAX_SIZE) return false;
    int position = nameToInt(person->name);
    while (hashTable[position] != NULL) {
        ++position;
        if (position >= MAX_SIZE) position %= MAX_SIZE;
    }
    hashTable[position] = person;
    ++size;
    return true;
}

bool table::erase(std::string name) {
    int position = search(name);
    if (position == -1) {
        return false;
    } else {
        delete hashTable[position];
        hashTable[position] = NULL;
        --size;
        return true;
    }
}

int table::search(std::string name) {
    int position = nameToInt(name);
    int initPosition = position;  // to break no-end loop

    while (hashTable[position] != NULL && hashTable[position]->name != name) {
        ++position;
        if (position >= MAX_SIZE) position %= MAX_SIZE;
        if (position == initPosition) return -1;
    }
    if (hashTable[position] == NULL) return -1;
    return position;
}


int table::nameToInt(std::string &name) {
    int position = 0;
    for (int i = 0; i < name.size(); ++i) {
        position += name[i] - 'a';
    }
    position %= MAX_SIZE;
    return position;
}

void table::showTable() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (hashTable[i] != NULL) {
            std::cout << std::setw(4) << std::left << i
                      << std::setw(15) << std::left << hashTable[i]->name << "  "
                      << hashTable[i]->male << "  "
                      << hashTable[i]->id << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }
}

Person* table::getAPerson(int order) { return hashTable[order]; }


int table::getSize() { return this->size; }


#endif
