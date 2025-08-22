
#include <iostream>
#include <vector>
#include<string>
#include "MyLib.h"

using namespace std;


// enums and structres needed
enum enUserOptions
{
	AddContact = 1,
	RemoveContact = 2,
	SearchContact = 3,
	ShowAllContacts = 4
};

struct stContact
{
	string ContactName;
	string PhoneNumber1;
	string PhoneNumber2;
	string country;

};

vector<stContact> Contacts;


//main program functions 

void AppHeader()
{
	cout << "\n\n";
	cout << "\t\t\t\t--------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\tWelcome to Contact Book\n\n";
	cout << "\t\t\t\t--------------------------------------------------------\n\n\n";
}

enUserOptions ShowOptionsToUser()
{
	string message = "What do you want to do ? [1] Add Contact  [2] Remove Contact  [3] Search Contact [4] Show All";

	int input = ReadNumberInRange(1,4, message);

	return enUserOptions(input);

}

stContact CreatNewContact()
{
	stContact Contact;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Please enter the full name\n";
	getline(cin, Contact.ContactName);

	cout << "Please enter the phone Number\n";
	getline(cin, Contact.PhoneNumber1);

	cout << "Please enter the second phone Number (optional)\n";
	getline(cin, Contact.PhoneNumber1);

	cout << "Please enter the country\n";
	getline(cin, Contact.country);

	return Contact;
}

void AddNewContact()
{
	stContact Contact = CreatNewContact();
	Contacts.push_back(Contact);

}



int main()
{
	AppHeader();
	ShowOptionsToUser();
	AddNewContact();
}


