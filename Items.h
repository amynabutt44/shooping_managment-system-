#include <iostream>
#include <memory>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Items
{
private:
	string cart[10];
	int size;
	int size2;
	int temp;
	double sum;
public:
	string* name;
	string* code;
	int* price;
	string* name2;
	string* code2;
	int* price2;
	int sizeOfCart;

	//constructor
	Items()
	{
		sizeOfCart = 0;
		for (int i = 0; i < 10; i++)
		{
			cart[i] = "";
		}
		temp = 0;
		sum = 0;
		size = 10;
		size2 = 10;
		readingfromfile();
		readingfromfile2();
	}

	void readingfromfile()
	{
		int k = 0;
		ifstream myfile;
		myfile.open("products.txt");
		if (myfile)
		{
			//cout << "My file is opened\n";
			//myfile >> n;
			//n = numberofproducts;
			name = new string[10];
			code = new string[10];
			price = new int[10];
	
			while (k < size)
			{
				getline(myfile, name[k], ',');
				getline(myfile, code[k], ',');
				myfile >> price[k];
				k++;
			}

		}
		else
		{
			cout << "Error !! file doesnot exist" << endl;
		}
	}

	void readingfromfile2()
	{
		int k = 0;
		ifstream myfile;
		myfile.open("watches.txt");
		if (myfile)
		{
			//cout << "My file is opened\n";
			//myfile >> n;
			//n = numberofproducts;
			name2 = new string[10];
			code2 = new string[10];
			price2 = new int[10];

			while (k < size)
			{
				getline(myfile, name2[k], ',');
				getline(myfile, code2[k], ',');
				myfile >> price2[k];
				/*cout << "\nItems name:" << name[k] << "\n";
				cout << "Item code:" << code[k] << "\n";
				cout << "Price:" << price[k];*/
				k++;
			}

		}
		else
		{
			cout << "Error !! file doesnot exist" << endl;
		}
	}

	//destructor
	~Items()
	{
		//cout << "Destructor\n";
		if (name)
			delete[] name;
			name = nullptr;
		if (name2)
			delete[] name2;
			name2 = nullptr;
		if (price)
			delete[] price;
			price = nullptr;
		if (price2)
			delete[] price2;
			price2 = nullptr;
		if (code)
			delete[] code;
			code = nullptr;
		if (code2)
			delete[] code2;
			code2 = nullptr;
		cout << "Thank you :)\n";
		cout << "Your procedure is completed\n";
	}

	void taskForCust()
	{
		cout << "================================================================\n\n";
		cout << "***********Press the options to continue the procedure***********\n";
		cout << "____________________________________________________________________\n";
		cout << "         1. To insert products in cart\n";
		cout << "         2. To remove the products from the cart\n";
		cout << "         3. To search the products in the manu\n";
		cout << "         4. To view the products in cart\n";
		cout << "         5. To view the invoice of the products\n";
		cout << "         6. To discontinue the shopping\n";
		cout << "=================================================================\n\n";
	}

	void taskForAd()
	{
		cout << "================================================================\n\n";
		cout << "Press the options to continue the procedure\n";
		cout << "1. To add the new products\n";
		cout << "2. To delete the products\n";
		cout << "3. To display the updates in products\n ";
		cout << "4. To exit the the procedure\n";
		cout << "==================================================================\n\n";
	}
	
	void display()
	{
		cout << "____________________________________________________________________________\n";
		cout << "        **********PERFUMES**********\t\t**********WATCHES*********\n";
		cout << "____________________________________________________________________________\n";
		cout << "\n" << setw(14) << "Name";
		cout << setw(8) << "Code";
		cout<< setw(8)<<"Price";
		cout << "\t\t" << setw(14) << "Name";
		cout << setw(8) << "Code";
		cout << setw(8) << "Price\n";
		cout << "____________________________________________________________________________\n";
		for (int i=0; i < size; i++)
		{
			cout << setw(14) << name[i];
			cout << setw(8) << code[i];
			cout<< setw(8) << price[i] << "\t\t";
			cout << setw(14) << name2[i];
			cout << setw(8) << code2[i];
			cout << setw(8) << price2[i] << "\n";
		}
		cout << "____________________________________________________________________________\n";
	}

	void displayWa()
	{
		cout << "____________________________________________________________________________\n";
		cout << "        **********WATCHES*********\n";
		cout << "____________________________________________________________________________\n";
		cout  << setw(14) << "Name";
		cout << setw(8) << "Code";
		cout << setw(8) << "Price\n";
		cout << "____________________________________________________________________________\n";
		for (int i = 0; i < size2; i++)
		{
			cout << setw(14) << name2[i];
			cout << setw(8) << code2[i];
			cout << setw(8) << price2[i] << "\n";
		}
		cout << "____________________________________________________________________________\n";

	}

	void displayPe()
	{
		cout << "____________________________________________________________________________\n";
		cout << "        **********PERFUMES*********\n";
		cout << "____________________________________________________________________________\n";
		cout << "\n" << setw(14) << "Name";
		cout << setw(8) << "Code";
		cout << setw(8) << "Price\n";
		cout << "____________________________________________________________________________\n";
		for (int i = 0; i < size; i++)
		{
			cout << setw(14) << name[i];
			cout << setw(8) << code[i];
			cout << setw(8) << price[i] << "\n";
		}
		cout << "____________________________________________________________________________\n";

	}
	
	void insert()
	{
		
		int i = 0;
		char ch;
		cout << "Do you want to insert then press y otherwise n\n";
		cin >> ch;
		if (temp > 0)
		{
			i = temp;
        }
		while (ch == 'y'||ch=='Y')
		{
			if (temp == 10)
			{
				cout << "Cart is full you can not select items in this cart\n";
				break;
			}
			else
			{
				cout << "Enter the name of product:\n";
				cin.ignore();
				getline(cin, cart[i]);
				for (int j = 0; j < size; j++)
				{
					if (cart[i] != name[j] && cart[i]!=name2[j])
					{
						if (j == size - 1)
						{
							i--;
							cout << "Not found ...!\n";
							break;
						}
					}
					else
					{
						if (cart[i] == name[j])
							sum += price[j];
						else if (cart[i] == name2[j])
							sum += price2[j];
						temp++;
						break;
					}
				}
			}
			cout << "Do You Want to insert anything next? \n";
			cin >> ch;
			i++;
		}
	}

	void remove()
	{
		if (temp == 0)
		{
			cout << "Your cart is empty \n";
		}
		else if (temp <= 10)
		{
			string rmvp;
			int found = 0;
			cout << "Enter the name of product you want to remove\n";
			cin >> rmvp;
			for (int i = 0; i < temp ; i++)
			{
				if(cart[i] == rmvp)
				{
					for (int c = 0; c < size; c++)
				    {
						if (cart[i] == name[c])
						{
							sum -= price[c];
							break;
						}
						else if (cart[i] == name2[c])
						{
							sum -= price2[c];
							break;
						}
					}
					for (int j = i; j < (temp - 1); j++)
					{
						if (temp == 1)
						{
							cart[j] = "";
						}
						else
						{
							cart[j] = cart[j + 1];
						}
					}
					found++;
					i--;
					temp--;
					//break;
				}
	      	}
			if (found == 0)
			{
				cout << "Not found\n";
			}

		}
	}

	void search()
	{
		int found = 0;
		if (temp == 0)
		{
			cout << "Your cart is empty\n";
			cout << "Insert first in the cart\n";
		}
		else
		{
			string search;
			int j;
			cout << "Enter the name of products you want to search in the cart\n";
			cin >> search;
			for (int i = 0; i < temp; i++)
			{
				if (cart[i] == search)
				{
					for (j = 0; j < size; j++)
					{
						if (cart[i] == name[j])
						{
							found++;
							cout << "The " << cart[i] << " is found at " << i+1 << " number in cart \n";
							cout << "CODE :" << code[j] << " \t\t Price :" << price[j] << "\n";
							j = size;
						}
						else if (cart[i] == name2[j])
						{
							found++;
							cout << "The " << cart[i] << " is found at " << i + 1 << " number in cart \n";
							cout << "CODE :" << code2[j] << " \t\t Price :" << price2[j] << "\n";
							j = size;
						}
					}
					
					if (j == size)
						break;
				}
			}
			if (found == 0)
			{
				cout << "Not Found...\n";
			}
		}
    }

	void displayPurchased()
	{
		if (temp == 0)
		{
			cout << "Your Cart is empty\n";
		}
		else
		{
			cout << setw(14) << "\t\t********PRODUCTS********\n" ;
			cout << "____________________________________________\n";
			for (int i = 0; i < temp; i++)
			{
				cout << "\t\t\t"<<cart[i] << "\n";
			}
			cout << "______________________________________________\n";
		}
	}

	void invoice()
	{
		if (temp == 0)
		{
			cout << "Sorry! your cart is empty \n";
			cout << "Insert some products in the cart\n";
		}
		else
		{
			cout << "________________________________________________________________\n";
			cout << setw(14) << "NAME" << setw(8) << "CODE" << setw(8) << "PRICE\n";
			cout << "_________________________________________________________________\n";
			for(int i=0;i<temp;i++)
			for (int j = 0; j < size; j++)
			{
				if (cart[i] == name[j])
				{
					cout << setw(14) << name[j] << setw(8) << code[j] << setw(8) << price[j] << "\n";
				}
				else if(cart[i]==name2[j])
				{
					cout << setw(14) << name2[j] << setw(8) << code2[j] << setw(8) << price2[j] << "\n";
				}
			}

			cout << "__________________________________________________________________\n";
			cout << "TOTAL PRICE \t" << sum << " Rs.\n";
			cout << "TAX :  13% of the Total Price\n";
			cout << "Total Bill\t:\t" << (0.13 * sum)+sum << " Rs.\n";
			cout << "___________________________________________________________________\n";
			cout << "\t\t\t ***THANK YOU FOR SHOPING HERE***:)";
			cout << "\n____________________________________________________________________\n";
		}
	}
	
	void addproducts()
	{
		int n;
		int j = 0;
		cout << "How many new products u want to add" << endl;
		cin >> n;
		int sizetemp = n + size;
		string* tempname = new string[sizetemp + 1];
		string* tempcode = new string[sizetemp + 1];
		int* tempprice = new int[sizetemp + 1];
		for (int i = 0; i < 10; i++)
		{
			tempcode[i] = code[i];
			tempname[i] = name[i];
			tempprice[i] = price[i];
			j++;
		}
		int i = 1;
		cin.ignore();
		for (j; j < sizetemp; j++)
		{
			cout << "Enter the name of product no:"<<i<<"\n";
			getline(cin, tempname[j]);
			cout << "Enter the price of the product\n";
			cin >> tempprice[j];
			while (tempprice[j] < 0)
			{
				cout << "Sorry! your price can not be evaluated \n";
				cout << "Please Enter a valid price\n";
				cin >> tempprice[j];
			}
			cout << "Enter the code of the product\n";
			cin.ignore();
			getline(cin, tempcode[j]);
			i++;
		}
		if(price)
			delete[] price;
		if(name)
			delete[] name;
		if(code)
			delete[] code;
		price = tempprice;
		name = tempname;
		code = tempcode;
		size = sizetemp;

	}
	
	void addproduct2()
	{
		int n;
		int j = 0;
		cout << "How many new products u want to add in watches collection?" << endl;
		cin >> n;
		int sizetemp = n + size2;
		string* tempname = new string[sizetemp];
		string* tempcode = new string[sizetemp];
		int* tempprice = new int[sizetemp];
		for (int i = 0; i < size2; i++)
		{

			tempcode[i] = code2[i];
			tempname[i] = name2[i];
			tempprice[i] = price2[i];
			j++;
		}
		int i = 1;
		cin.ignore();
		for ( j; j < sizetemp; j++)
		{
			cout << "Enter the name of product no:"<<i<<"\n";
			getline(cin, tempname[j]);
			cout << "Enter the price of the product:\n";
			cin >> tempprice[j];
			while (tempprice[j] < 0)
			{
				cout << "Sorry! your price can not be evaluated \n";
				cout << "Please Enter a valid price\n";
				cin >> tempprice[j];
			}
			cout << "Enter the code of the product\n";
			cin.ignore();
			getline(cin, tempcode[j]);
			i++;
		}
		if(price2)
			delete[] price2;
		if(name2)
			delete[] name2;
		if(code2)
			delete[] code2;
		price2 = tempprice;
		name2 = tempname;
		code2 = tempcode;
		size2 = sizetemp;

	}

	void deleteproduct2()
	{
		string namee;
		string* tempname;
		string* tempcode;
		int* tempprice;
		int tempsize;
		int x = 0;
		tempname = new string[size2 - 1];
		tempcode = new string[size2 - 1];
		tempprice = new int[size2 - 1];
		tempsize = size2 - 1;
		int count = 0;
		int j = 0;

		cout << "Enter the code of the product you want to delete" << endl;
		cin.ignore();
		getline(cin, namee);
		for (int i = 0; i < size2; i++)
		{
			if (code2[i] == namee)
			{
				x = 1;
				break;
			}
			else
			{
				x++;
			}
		}
		if (x == 1)
		{
			for (int i = 0; i < size2; i++)
			{
				if (code2[i] != namee)
				{
					tempname[j] = name2[i];
					tempcode[j] = code2[i];
					tempprice[j] = price2[i];
					j++;
				}
			}
			delete[]name2;
			delete[]code2;
			delete[]price2;
			name2 = tempname;
			price2 = tempprice;
			code2= tempcode;
			size2 = tempsize;
		}
		else if (x != 1)
		{
			cout << "Sorry! Product of such code does not exist..." << endl;
		}
	}

	void deleteproduct()
	{
		string namee;
		string* tempname;
		string* tempcode;
		int* tempprice;
		int tempsize;
		int x = 0;
		tempname = new string[size - 1];
		tempcode = new string[size - 1];
		tempprice = new int[size - 1];
		tempsize = size - 1;
		int count = 0;
		int j = 0;

		cout << "Enter the code of the product you want to delete" << endl;
		cin.ignore();
		getline(cin, namee);
		for (int i = 0; i < size; i++)
		{
			if (code[i] == namee)
			{
				x =1;
				break;
			}
			else
			{
				x++;
			}
		}
		if (x == 1)
		{
			for (int i = 0; i < size; i++)
			{
				if (code[i] != namee)
				{
					tempname[j] = name[i];
					tempcode[j] = code[i];
					tempprice[j] = price[i];
					j++;
				}
			}
			delete[]name;
			delete[]code;
			delete[]price;
			name = tempname;
			price = tempprice;
			code = tempcode;
			size = tempsize;
		}
		else if(x!=1)
		{
			cout << "Sorry! Product of such code does not exist..." << endl;
		}
	}
	
};


