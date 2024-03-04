#include "HashTable.h"
#include <iostream>
#include <cmath>
#include "Recipe.h"

using namespace std;


HashTable::HashTable(int capacity)
{
	this->count = 0;
	this->capacity = capacity;
	maps = new List<Recipe*> *[capacity];
	for (int i = 0; i < capacity; i++)
		maps[i] = new List<Recipe*>();
}

HashTable::~HashTable()
{
	for (int i = 0; i < capacity; i++)
	{
		delete maps[i];
		maps[i] = NULL;
	}

	delete[] maps;
	maps = NULL;
}


void HashTable::put(string key, Recipe* value)
{
	if (key == "")
		return;

	int hashedKey = hashKey(key);
	Node<Recipe*>* node = maps[hashedKey]->find(to_string(hashedKey));
	if (node)
	{
		node->data = value;
		count++;
	}
	else
		maps[hashedKey]->append(value, to_string(hashedKey));
}

int HashTable::hashKey(string key)
{
	int hashedKey = 0;
	for (int i = 0; i < key.size(); i++)
		hashedKey += (key[i] * pow(10, i));

	return hashedKey % capacity;
}

Recipe* HashTable::get(string key)
{
	if (key == "")
		return NULL;

	int hashedKey = hashKey(key);
	Node<Recipe*>* node = maps[hashedKey]->find(to_string(hashedKey));

	return node->data;
}

bool HashTable::contains(string key)
{
	if (key == "")
		return false;

	int hashedKey = hashKey(key);
	Node<Recipe*>* node = maps[hashedKey]->find(to_string(hashedKey));

	return node ? true : false;
}
