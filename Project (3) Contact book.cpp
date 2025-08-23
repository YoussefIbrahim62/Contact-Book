
#include <iostream>
#include <vector>
#include<string>
#include <iomanip>
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

vector<stContact> Contacts = 
{
	{"Joe Ibrahim", "01016548516", "-", "Egypt"},
	{"Azza ", "900500300", "-", "Syria"},
	{"Ibrahim", "900500300", "123456789", "Egypt"},
	{"John", "900500300", "123456789", "USA"},
	{"Emily", "900500300", "987654321", "UK"},
	{"Zed", "900500300", "123456789", "Canda"},
	{"Ahmed", "900500300", "987654321", "Egypt"},

};

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
	string message = "\n\nWhat do you want to do ? [1] Add Contact  [2] Remove Contact  [3] Search Contact [4] Show All";

	int input = ReadNumberInRange(1,4, message);

	return enUserOptions(input);

}

stContact CreatNewContact()
{
	stContact Contact;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n\nPlease enter the full name: ";
	getline(cin, Contact.ContactName);

	cout << "Please enter the phone Number: ";
	getline(cin, Contact.PhoneNumber1);

	cout << "Please enter the second phone Number (optional): ";
	getline(cin, Contact.PhoneNumber2);

	cout << "Please enter the country: ";
	getline(cin, Contact.country);

	return Contact;
}

void AddNewContact()
{
	stContact Contact = CreatNewContact();
	Contacts.push_back(Contact);
}

void RemoveAContact()
{
	string Name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Please enter the contact name that you want to remove\n";
	getline(cin, Name);

	for (size_t i = 0; i < Contacts.size(); i++)
	{
		if (Contacts[i].ContactName == Name)
		{
			Contacts.erase(Contacts.begin() + i);
			cout << "Contact removed successfully!\n";
		}
	}
}

int IsContactExisted(string contactName)
{
	int counter = 0;

	for (stContact i : Contacts)
	{
		if (i.ContactName == contactName)
		{
			return counter;
		}
		counter++;
	} 
	return -1;
}

void showAContact(stContact Contact)
{

	cout << left << setw(24) << Contact.ContactName << "|" << setw(13) << Contact.PhoneNumber1 << "|" << setw(13) << Contact.PhoneNumber2 << "|" << setw(13) << Contact.country << "|\n";

}

void showAllContacts()
{
	cout << "------------------------|-------------|-------------|-------------|\n";
	cout << "          Name          |   Phone 1   |   Phone 2   |   Country   |\n";
	cout << "------------------------|-------------|-------------|-------------|\n";

	for (stContact contact : Contacts)
	{
		showAContact(contact);
	}

	cout << "------------------------|-------------|-------------|-------------|\n";
}


void SearchForAContactByName()
{
	string Name;

	cout << "Please enter the contact name\n";
	cin.ignore();
	getline(cin, Name);

	int ConatctIndex = IsContactExisted(Name);

	if (ConatctIndex == -1)
		cout << " Contact is NOT found :(\n\n";
	else
	{
		cout << "------------------------|-------------|-------------|-------------|\n";
		cout << "          Name          |   Phone 1   |   Phone 2   |   Country   |\n";
		cout << "------------------------|-------------|-------------|-------------|\n";

		showAContact(Contacts[ConatctIndex]);

		cout << "------------------------|-------------|-------------|-------------|\n";
	}

}


void ApplyOptions(enUserOptions Options)
{
	switch (Options)
	{
	case enUserOptions::AddContact:
		AddNewContact();
		break;
	case enUserOptions::RemoveContact:
		RemoveAContact();
		break;
	case enUserOptions::ShowAllContacts:
		showAllContacts();
		break;
	case enUserOptions::SearchContact:
		SearchForAContactByName();
		break;
	}
}


void StartProgram()
{
	AppHeader();

	int input = 0;
	do
	{
		ApplyOptions(ShowOptionsToUser());

		input = ReadNumberInRange(1, 2, "\n\n\nAre you done? [1] Yes,  [2] No");



	} while (input != 1);

}


int main()
{

	StartProgram();


}


