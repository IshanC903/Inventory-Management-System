//Ishan Chaurasia
//101011068
//BIT2400 Assignment 2
//Friday 25, 2018

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product
{
	int productID;
	string productName;
	double productPrice;
};
struct Customer
{
	int customerID;
	string customerFullName;
	string customerAddress;
};
struct Order
{
	int orderID;
	string orderDescrip;
	int customerID;
	int productID;
};

Product	addProduct()
{
	Product createNew;
	int id;
	string name;
	double price;

	//system("CLS");
	cout << endl;

	cout << "Adding a new Product:" << endl;
	cout << "Enter Product ID: ";
	cin >> id;
	cout << "Enter Product Name: ";
	cin >> name;
	cout << "Enter Product Price: $";
	cin >> price;

	createNew.productID = id;
	createNew.productName = name;
	createNew.productPrice = price;

	cout << endl << "A new Product has been added successfully!" << endl << endl;
	//system("PAUSE");

	return createNew;
}

void viewProduct(vector<Product>&storedProducts, int size)
{

	//system("CLS");
	cout << endl;

	cout << "Listing following Products:" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "*Product " << i + 1 << "*" << endl;
		cout << "Product ID: " << storedProducts[i].productID << endl;
		cout << "Product Name: " << storedProducts[i].productName << endl;
		cout << "Product Price: $" << storedProducts[i].productPrice << endl << endl;
	}
	//system("PAUSE");
}

Customer addCustomer()
{
	Customer createNew;
	int id;
	string name;
	string address;

	cout << endl;
	cout << "Adding a new Customer:" << endl;
	cout << "Enter Customer ID: ";
	cin >> id;
	cout << "Enter Customer Name: ";
	cin.ignore(256, '\n');
	getline(cin, name);
	cout << "Enter Customer Address: ";
	getline(cin, address);

	createNew.customerID = id;
	createNew.customerFullName = name;
	createNew.customerAddress = address;

	cout << endl << "A new Customer has been added successfully!" << endl << endl;

	return createNew;
}

void viewCustomer(vector<Customer>&storedCustomers, int size)
{
	cout << endl << "Listing following Customers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "*Customer " << i + 1 << "*" << endl;
		cout << "Customer ID: " << storedCustomers[i].customerID << endl;
		cout << "Customer Name: " << storedCustomers[i].customerFullName << endl;
		cout << "Customer Address: " << storedCustomers[i].customerAddress << endl << endl;
	}
}

Order addOrder(vector<Order>&storedOrders, vector<Product>&storedProducts, vector<Customer>&storedCustomer)
{
	Order createNew;
	int odrid;
	string description;
	int custid;
	int prodid;

	cout << endl << "Adding a new Order:" << endl;
	cout << "Enter Order ID: ";
	cin >> odrid;
	cout << "Enter Order Description: ";
	cin.ignore(256, '\n');
	getline(cin, description);
	cout << "Which Customer made this Order?" << endl;
	viewCustomer(storedCustomer, storedCustomer.size());
	cout << "Enter Customer Number: #";
	cin >> custid;
	cout << endl << "Which Product was part of this Order?" << endl;
	viewProduct(storedProducts, storedProducts.size());
	cout << "Enter Product Number: #";
	cin >> prodid;
	cout << endl;

	createNew.orderID = odrid;
	createNew.orderDescrip = description;
	createNew.customerID = storedCustomer[custid - 1].customerID;
	createNew.productID = storedProducts[prodid - 1].productID;

	return createNew;
}

void viewOrder(vector<Order>&storedOrders, vector<Product>&storedProducts, vector<Customer>&storedCustomer, int size)
{
	cout << endl << "Listing following Orders:" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "*Order " << i + 1 << "*" << endl;
		cout << "Order ID: " << storedOrders[i].orderID << endl;
		cout << "Order Description: " << storedOrders[i].orderDescrip << endl;
		cout << "Customer ID: " << storedOrders[i].customerID << endl;
		cout << "Product ID: " << storedOrders[i].productID << endl;
	}
	cout << endl;
}

void menuProduct(vector<Product>&storedProducts)
{
	string choice;
	bool runMenu = true;
	//system("CLS");
	cout << endl;
	while (runMenu)
	{
		cout << "*Products sub-menu*" << endl;
		cout << "Press A to add a Product" << endl;
		cout << "Press V to view all Products" << endl;
		cout << "Press D to delete all Products" << endl;
		cout << "Press B to go back to main-menu" << endl;
		cout << "Please enter your input: ";
		cin >> choice;

		if (choice == "A" || choice == "a")
		{
			cout << endl << "User entered A" << endl;
			storedProducts.push_back(addProduct());
		}
		else if (choice == "V" || choice == "v")
		{
			cout << endl << "User entered V" << endl;
			viewProduct(storedProducts, storedProducts.size());
		}
		else if (choice == "D" || choice == "d")
		{
			cout << endl << "User entered D" << endl;
			storedProducts.clear();
			cout << endl << "All Products deleted successfully!" << endl << endl;
		}
		else if (choice == "B" || choice == "b")
		{
			cout << endl << "User entered B" << endl;
			runMenu = false;
		}
		else
		{
			cout << endl << "Error! Option Not Available. Please try again." << endl << endl;
		}
	}
}

void menuCustomer(vector<Customer>&storedCustomers)
{
	string choice;
	bool runMenu = true;
	//system("CLS");
	cout << endl;

	while (runMenu)
	{
		cout << "*Customer sub-menu*" << endl;
		cout << "Press A to add a Customer" << endl;
		cout << "Press V to view all Customers" << endl;
		cout << "Press D to delete all Customers" << endl;
		cout << "Press B to go back to main-menu" << endl;
		cout << "Please enter your input: ";
		cin >> choice;

		if (choice == "A" || choice == "a")
		{
			cout << endl << "User entered A" << endl;
			storedCustomers.push_back(addCustomer());
		}
		else if (choice == "V" || choice == "v")
		{
			cout << endl << "User entered V" << endl;
			viewCustomer(storedCustomers, storedCustomers.size());
		}
		else if (choice == "D" || choice == "d")
		{
			cout << endl << "User entered D" << endl << endl;
			storedCustomers.clear();
			cout << "All Customers deleted successfully!" << endl << endl;
		}
		else if (choice == "B" || choice == "b")
		{
			cout << endl << "User entered B" << endl;
			runMenu = false;
		}
		else
		{
			cout << endl << "Error! Option Not Available. Please try again." << endl << endl;
		}
	}
}

void menuOrder(vector<Order>&storedOrders, vector<Product>&storedProducts, vector<Customer>&storedCustomers)
{
	string choice;
	bool runMenu = true;
	//system("CLS");
	cout << endl;

	while (runMenu)
	{
		cout << "*Order sub-menu*" << endl;
		cout << "Press A to add a Order" << endl;
		cout << "Press V to view all Orders" << endl;
		cout << "Press D to delete all Orders" << endl;
		cout << "Press B to go back to main-menu" << endl;
		cout << "Please enter your input: ";
		cin >> choice;

		if (choice == "A" || choice == "a")
		{
			cout << endl << "User entered A" << endl;
			storedOrders.push_back(addOrder(storedOrders, storedProducts, storedCustomers));
		}
		else if (choice == "V" || choice == "v")
		{
			cout << endl << "User entered V" << endl;
			viewOrder(storedOrders, storedProducts, storedCustomers, storedOrders.size());
		}
		else if (choice == "D" || choice == "d")
		{
			cout << endl << "User entered D" << endl;
			storedOrders.clear();
			cout << "All Orders deleted successfully!" << endl << endl;
		}
		else if (choice == "B" || choice == "b")
		{
			cout << endl << "User entered B" << endl;
			runMenu = false;
		}
		else
		{
			cout << endl << "Error! Option Not Available. Please try again." << endl << endl;
		}
	}
}

string mainMenu()
{
	string choice;

	cout << endl << "*Main-menu*" << endl;
	cout << "Press P to open Products sub-menu" << endl;
	cout << "Press C to open Customers sub-menu" << endl;
	cout << "Press O to open Orders sub-menu" << endl;
	cout << "Press E to exit from Inventory Management System" << endl;
	cout << "Please enter your input: ";
	cin >> choice;

	return choice;
}

int main()
{
	string userChoice;
	bool runProgram = true;

	vector<Product> storedProducts;
	vector<Customer> storedCustomers;
	vector<Order> storedOrders;

	cout << "*****************************" << endl;
	cout << "*Inventory Management System*" << endl;
	cout << "*****************************" << endl;

	while (runProgram)
	{
		//system("CLS");
		userChoice = mainMenu();

		if (userChoice == "P" || userChoice == "p")
		{
			cout << endl << "User entered P" << endl;
			menuProduct(storedProducts);
		}
		else if (userChoice == "C" || userChoice == "c")
		{
			cout << endl << "User entered C" << endl;
			menuCustomer(storedCustomers);
		}
		else if (userChoice == "O" || userChoice == "o")
		{
			cout << endl << "User entered O" << endl;
			menuOrder(storedOrders, storedProducts, storedCustomers);
		}
		else if (userChoice == "E" || userChoice == "e")
		{
			cout << endl << "User entered E" << endl;
			runProgram = false;
		}
		else 
		{
			cout << endl << "Error! Option Not Available. Please try again." << endl << endl;
		}
	}

	system("pause");
	return NULL;
}