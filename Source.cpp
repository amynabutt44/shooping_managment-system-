#include <iostream>
#include <string>
#include "admin.h"
#include <cstring>
#include "Customer.h"
using namespace std;

bool validateNum(string s)
{
	bool found = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
		{
			found= false;
			break;
		}
	}
	return found;
}

int main()
{
	Items i1;
	admin a;
	Customer c(i1);
	int opForPer;
	int opForShop;
	cout << "============================================================================\n";
	cout << "\t\t--------  WELCOME  --------\n";
	cout << "============================================================================\n";
	//cout << "Here you can buy Branded Perfumes and Branded Watches of great quality\n";
	cout << "PLEASE PRESS THE FOLLOWING OPTIONS FOR FURTHER ACTIVITIES\n";
	cout << "        ******* 1. CUSTOMER *******\n";
	cout << "        ******* 2. ADIMN    ********\n";
	cin >> opForPer;
	while (opForPer < 1 || opForPer>2)
	{
		cout << "Error! Please Enter a valid option of your personality\n";
		cin >> opForPer;
	}
	if (opForPer == 1)
	{
		cout << "________________________________________________________\n";
		cout << " ***********(PERSONAL INFORMATION)***********\n";
		cout << "________________________________________________________\n";
		cout << "\t______(NAME)______\n";
		cin.ignore();
		getline(cin, c.name);
		cout << "\t______(PHONE NO.)______\n";
		getline(cin, c.phoneNo);
		if (!validateNum(c.phoneNo))
		{
			cout << "Enter a valid phone number\n";
			getline(cin, c.name);
		}
		cout << "\t______(EMAIL)______\n";
		getline(cin, c.email);
		cout << "\t\t AVAILABILITIES\n";
		c.callOfDisplayProducts();
		cout << "Do You want to shop anything or not?\n";
		do
		{
			c.callOfTaskForCustomer();
			do
			{
				cout << "Enter an option for the procedure\n";
				cin >> opForShop;
			} while (opForShop < 1 || opForShop>6);
			cin.ignore();
			switch (opForShop)
			{
			case 1:
				c.callForInsert();
				break;
			case 2:
				c.callForRemove();
				break;
			case 3:
				c.callForSearch();
				break;
			case 4:
				c.callForPurchased();
				break;
			case 5:
				c.callForInvoice();
				break;
			}
		}
		while (opForShop != 6);
	}
	else if (opForPer == 2)
	{
		int ad=0;
		int usermore=0;
		string name;
		string pass;
		int opForAd;
		cout << "Enter the user name:\n";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the password\n";
		getline(cin, pass);
		if (a.checkingpassword(pass))
		{
			cout << "Congratulations! you are login successfully\n";
			cout << "Press the following options for next procedure\n" << endl;
			do
			{
				i1.taskForAd();
				do
				{
					cout << "Enter an option for the procedure\n";
					cin >> opForAd;
				} while (opForAd < 1 || opForAd>5);
				cin.ignore();
				switch (opForAd)
				{
				case 1:
					cout << "1. Add in perfumes\n";
					cout << "2. Add in Watches\n ";
					cin >> ad;
					if (ad == 1)
					{
						i1.addproducts();
					}
					else if (ad == 2)
					{
						i1.addproduct2();
					}
					break;
				case 2:
					cout << "1. Delete in perfumes\n";
					cout << "2. Delete in Watches\n ";
					cin >> ad;
					if (ad == 1)
					{
						i1.deleteproduct();
					}
					else if (ad == 2)
					{
						i1.deleteproduct2();
					}
					break;
				case 3:
					i1.displayPe();
					i1.displayWa();
					break;
				/*case 4:
					string s;
					cout << "Enter a new password\n";
					cin.ignore();
					getline(cin, s);
					a.passchange(s);
					break;*/
				}
			} while (opForAd != 4);
			
		}
		else
		{
			cout << "Your password is wrong !Sorry you cant access the data:)\n";
		}
	}
	  return 0;
}




