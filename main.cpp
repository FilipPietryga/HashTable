#include <iostream>
#include "HashTable.h"

using namespace ht;

int main() {
    HashTable hashTable;
    hashTable.insert("Filip", 531069997);
    hashTable.insert("Andrzej", 696969696);
    hashTable.insert("Stefan", 321215252);
    hashTable.insert("Sraka", 898989898);
    long value = hashTable.find("Sraka");
    std::cout << "The filip's phone number, found in the hash table is " << value << " :)" << std::endl;
    return 0;
}