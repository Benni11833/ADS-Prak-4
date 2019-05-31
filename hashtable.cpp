#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {
	collisionCount = elements = 0;
	this->size = size;
	hashTable->resize(size, -1);
}

HashTable::~HashTable()
{
	hashTable->~vector();
}

int HashTable::hashValue(int item) {
	
	int index = -1; //dummy initializtation
	int i{1};
	index = item % size;
	while(hashTable->at(index) == -1){
		index = ((item % size + i*i)%size);
		++i;
		++collisionCount;
	}

	return index;
}

int HashTable::insert(int item) {
	
	hashTable->at(hashValue(item)) = item;
	++elements;

	return 0; //dummy return
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
