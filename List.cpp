#include "List.h"

#include <iostream>
#include <string>
#include "Recipe.h"
#include "AVLTree.h"

using namespace std;

template <class T>
Node<T>::Node(T& data, string label)
{
	next = 0;
	this->data = data;
	this->label = label;
}

template <class T>
Node<T>::Node()
{
	// this->next = 0;
	// this->data = 0;
	this->label = "";
}

template <class T>
List<T>::List()
{
	head = tail = 0;
	count = 0;
}

template <class T>
void List<T>::append(T& value, std::string label)
{
	Node<T>* node = new Node<T>(value, label);
	if (!count)
		head = tail = node;
	else
	{
		tail->next = node;
		tail = node;
	}

	count++;
}

template <class T>
void List<T>::display()
{

}

template <class T>
List<T>::~List()
{
	Node<T>* current = head;
	while (current)
	{
		Node<T>* next = current->next;
		delete current;
		current = next;
	}

	current = head = tail = 0;
	count = 0;
}

template <class T>
void List<T>::clear()
{
	this->~List();
}
template <class T>
Node<T>* List<T>::find(string label)
{
	if (!head)
		return 0;

	Node<T>* current = head;
	while (current && current->label != label)
		current = current->next;

	return current && current->label == label ? current : 0;
}

template class Node<int>;
template class Node<double>;
template class Node<string>;
template class Node<Recipe*>;
template class Node<AVLTree>;
template class Node<AVLTree*>;
template class Node<List<AVLTree*>>;
template class Node<List<AVLTree>>;

template class List<int>;
template class List<double>;
template class List<string>;
template class List<Recipe*>;
template class List<AVLTree>;
template class List<AVLTree*>;
template class List<List<AVLTree*>>;
template class List<List<AVLTree>>;