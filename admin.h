#include <iostream>
using namespace std;
#ifndef ITEMS_H
#define ITEMS_H
class admin
{
private:

	string username;
	string password;
	bool state;
public:
	admin()
	{
		password = "admin123";
		username = "admin";
	}
	void passchange(string s)
	{
		setpassword(s);
		cout << "Your password has changes successfully\n";
	}
	void setusername(string a)
	{
		username = a;
	}
	void setpassword(string b)
	{
		password = b;
	}
	bool checkingpassword(string a)
	{

		if (password == a)
		{

			state = true;
			return true;
		}
		else 
			return false;

	}

	bool chechState()
	{
		return state;
	}
};

#endif