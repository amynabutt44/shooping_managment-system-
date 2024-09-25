
#include <iostream>
#include <fstream>
#include<string>

#include"Items.h"
#include "admin.h"
//admin::/*admin(Items& t) :User(), products(&t)
//{
//	cout << " default constructor called" << endl;
//	password = "admin123";
//	username = "admin";
//
//}*/

//void admin::readingpasswords()
//{
//	ifstream myfile;
//	myfile.open("pasword.txt");
//	cout << "file is open" << endl;
//	if (myfile)
//	{
//
//		getline(myfile, username, ',');
//		getline(myfile, password, ',');
//
//	}
//	else
//		cout << "Error !! file doesnot exist" << endl;
//}
//admin::admin(Items& t) :User(), products(&t)
//{
//	password = "admin123";
//	username = "admin";
//}


void admin::setusername(string a)
{
	username = a;
}
void admin::setpassword(string b)
{
	password = b;
}
bool admin::checkingpassword(string a)
{

	if (password == a)
	{

		return true;
	}
	else /*if (password != a)*/
		return false;

}