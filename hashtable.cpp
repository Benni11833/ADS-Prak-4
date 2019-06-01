#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {
	collisionCount = elements = 0;
	hashTable = new vector<int>;
	hashTable->resize(size, -1);
	this->size = size;
}

HashTable::~HashTable()
{
	delete hashTable;
}

int HashTable::hashValue(int item) {
	
	int index = -1; //dummy initializtation
	/*int i{1};
	index = item % size;
	while(hashTable->at(index) != -1){
		index = ((item % size + i*i)%size);
		++i;
		++collisionCount;
	}*/
	int i{0};
	while(hashTable->at(((item % size + i*i)%size)) != -1){
		++i;
		++collisionCount;
	}
	return ((item % size + i*i)%size);
}

int HashTable::insert(int item) {
	int hashVal = hashValue(item);
	hashTable->at(hashVal) = item;
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

void HashTable::print()const{
	std::cout << "HashTable->size(): " << size << std::endl;
	for(int i=0; i < size; i++)
		std::cout << i << ": " << hashTable->at(i) << std::endl;
}