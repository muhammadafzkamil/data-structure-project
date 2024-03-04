#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include "List.h"
#include "Recipe.h"


using namespace std;


class HashTable
{
public:
	HashTable(int);
	~HashTable();
	void put(string, Recipe*);
	Recipe* get(string);
	bool contains(string);

	int count;

private:
	int hashKey(string);

	List<Recipe*>** maps;
	int capacity;
};

#endif
