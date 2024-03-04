#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
public:
	std::string label;
	T data;
	Node<T>* next;

	Node(T&, std::string = "");
	Node();
};

template <class T>
class List
{
public:
	List();
	~List();

	Node<T>* head;
	Node<T>* tail;
	int count;

	void append(T&, std::string = "");
	Node<T>* find(std::string);
	void clear();
	void display();
};



#endif

