#include <iostream>
#include <string>
using namespace std;

class User
{
public:
	string name;
	string phoneNo;
	string email;
	User()
	{
		name = "";
		phoneNo = "";
		email = "";
	}
	User(string n, string p, string e)
	{
		name = n;
		phoneNo = p;
		email = e;
	}
};