#ifndef USER_H
#define USER_H

#include <iostream>
#include "Items.h"
#include "User.h"
using namespace std;

class Customer :public User
{
	Items* products;
public:
	Customer(Items&t) :User(), products(&t)
	{
	}

	Customer(string n, string p, string e, Items& t) :User(n, p, e)
	{
		products = &t;
	}
	
	void callOfTaskForCustomer()
	{
		products->taskForCust();
	}
	
	void callOfDisplayProducts()
	{
		products->display();
	}
	
	void callForInsert()
	{
		products->insert();
	}

	void callForRemove()
	{
		products->remove();
	}

	void callForSearch()
	{
		products->search();
	}

	void callForPurchased()
	{
		products->displayPurchased();
	}

	void callForInvoice()
	{
		cout << "================================================================\n";
		cout << "\t\t*******************INVOICE****************\n";
		cout << "==================================================================\n";
		cout << "\n\t\tCUSTOMER'S INFORMATION\n";
		cout << "\tNAME:\t\t" << name << "\n";
		cout << "\tPHONE NO:\t\t" << phoneNo << "\n";
		cout << "\tEMAIL :\t\t" << email << "\n\n";
		products->invoice();
	}

	
};
#endif // !USER_H