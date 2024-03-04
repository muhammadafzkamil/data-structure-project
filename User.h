#pragma once
#ifndef USER
#define USER

#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	string name;
	string email;
	string password;

	User();
	User(string, string, string);
	static User* signup(string, string, string);
	bool signin(string, string);
	void changeInfo(string, string, string);
	void display();
};

#endif // USER