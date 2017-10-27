#include "../include/hash.h"

Hash::Hash() {
    for (int i = 0; i < this->_tableSize; i++) {
        this->_hashTable[i] = new item;
        this->_hashTable[i]->name = TABLE_EMPTY;
        this->_hashTable[i]->drink = TABLE_EMPTY;
        this->_hashTable[i]->next = NULL;
    }
}

int Hash::numberOfItemsInIndex(int const &index) {
    int count = 0;
    if (this->_hashTable[index]->name == TABLE_EMPTY) return count;
    count++;
    
    item *ptr = this->_hashTable[index];
    while (ptr->next != NULL) {
        ptr = ptr->next;
        count++;        
    }
    return count;
}

void Hash::printItemInIndex(int const &index) {
    item* ptr = this->_hashTable[index];
    if (ptr->name == TABLE_EMPTY) {
        cout << "index = " << index << " is empty" << endl;
    }
    else {
        cout << "index = " << index << " contains the following item\n";
        while (ptr != NULL) {
            cout << "-----------------\n";
            cout << ptr->name << endl; 
            cout << ptr->drink << endl; 
            cout << (ptr->next == NULL) << endl;
            cout << "-----------------\n";
            ptr = ptr->next;
        }
    }
}

void Hash::printTable() {
    int number;
    for (int i = 0; i < this->_tableSize; i++) {
        number = numberOfItemsInIndex(i);
        cout << "-----------------\n";
        cout << "index =  " << i << endl;
        cout << this->_hashTable[i]->name << endl; 
        cout << this->_hashTable[i]->drink << endl; 
        cout << "# of items = " << number << endl; 
        cout << "-----------------\n";
    }
}

void Hash::addItemByIndex(int const &index, string const &name, string const &drink) {
    if (this->_hashTable[index]->name == TABLE_EMPTY) { // bucket no item
        this->_hashTable[index]->name = name;
        this->_hashTable[index]->drink = drink;
    } else { // must find the end of the table[index]
        item *ptr = this->_hashTable[index];
        item *newIten = new item;
        newIten->name = name;
        newIten->drink = drink;
        newIten->next = NULL;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newIten;
    }
}

void Hash::addItem(string const &name, string const &drink) {
    int index = hash(name);
    if (this->_hashTable[index]->name == TABLE_EMPTY) { // bucket no item
        this->_hashTable[index]->name = name;
        this->_hashTable[index]->drink = drink;
    } else { // must find the end of the table[index]
        item *ptr = this->_hashTable[index];
        item *newIten = new item;
        newIten->name = name;
        newIten->drink = drink;
        newIten->next = NULL;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newIten;
    }
}

int Hash::hash(string key) {
    int hash = 0;
    int index = key.length();
    for (int i = 0; i < index; i++) {
        hash += (int)key[i] * 17;
    }
    index = hash % this->_tableSize;
    return index;
}

void Hash::findDrink(string const &name) {
    int index= hash(name);
    item *ptr = this->_hashTable[index];
    string targetDrink;
    bool isFindOut = false;
    while (ptr != NULL) {
        if (ptr->name == name) {
            isFindOut = true;
            targetDrink = ptr->drink;
        }
        ptr = ptr->next;
    }
    if (isFindOut) {
        cout << "Favorite drink is " << targetDrink << endl;
    } else {
        cout << name << "'s info was not found out!" << endl;
    }
}


bool Hash::removeItem(string const &name) {
    int index = hash(name);
    bool isSuccess = false;
    // case 0 - bucket is empty
    if (this->_hashTable[index]->name == TABLE_EMPTY && this->_hashTable[index]->drink == TABLE_EMPTY) {
        cout << name << " was not found in the Hash Table" << endl;
    }
    // case 1 - only 1 item in bucket
    else if (this->_hashTable[index]->name == name && this->_hashTable[index]->next == NULL) {
        this->_hashTable[index]->name = this->_hashTable[index]->drink = TABLE_EMPTY;
        cout << name << " was removed from hash table" << endl;
        isSuccess = true;
    }
    // case 2 - target located in first bucket, but there are more items in bucket
    else if (this->_hashTable[index]->name == name) {
        cout << "case 2" << endl;
        item *deletePtr = this->_hashTable[index];
        this->_hashTable[index] = this->_hashTable[index]->next;
        delete deletePtr;
        cout << name << " was removed from hash table" << endl;
        isSuccess = true;        
    }
    // case 3 - bucket contain item, but first item is not match
    // case 3.1 - no match
    // case 3.2 - match is found  
    else {
        cout << "case 3" << endl;
        item *current = this->_hashTable[index];        
        item *previous = NULL;
        while (current != NULL) {
            if (current->name == name) {
                cout << "success" << endl;                        
                previous->next = current->next;
                delete current;
                isSuccess = true;
                break;
            } else {
                previous = current;
                current = current->next;    
            }
        }        
        if (current == NULL) {
            cout << name << " was not found in the Hash Table" << endl;            
        } 
    }
    return isSuccess;
}