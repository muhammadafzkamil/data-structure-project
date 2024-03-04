#include "User.h"

User::User(std::string name, std::string email, std::string password)
{
	this->name = name;
	this->email = email;
	this->password = password;
}

User::User()
{
	this->name = "";
	this->email = "";
	this->password = "";
}

User* User::signup(std::string name, std::string email, std::string password)
{
	return new User(name, email, password); 
}

bool User::signin(string email, string password)
{
	return this->email == email && this->password == password;
}

void User::changeInfo(string name, string email, string password)
{
	this->name = name;
	this->email = email;
	this->password = password;
}

void User::display()
{
	cout << "Name: " << name << endl
		<< "Email: " << email << endl
		<< "Password: " << password << endl;
}