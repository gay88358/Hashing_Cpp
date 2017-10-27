#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
class Hash {
public:
    Hash();
    int hash(string key);
    void addItem(string const &name, string const &drink);
    int numberOfItemsInIndex(int const &index);
    void addItemByIndex(int const &index, string const &name, string const &drink);
    void printTable();
    void printItemInIndex(int const &index);
    void findDrink(string const &name);
    bool removeItem(string const &name);
private:
    const string TABLE_EMPTY = "empty";
    static const int _tableSize = 10;
    struct item {
        string name;
        string drink;
        item* next;
    };
    item* _hashTable[_tableSize];
};

#endif