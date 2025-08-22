
#include <iostream>
#include<array>
#include<string>
#include "MyLib.h"

using namespace std;

enum enUserOptions
{
	AddContact = 1,
	RemoveContact = 2,
	SearchContact = 3
};

enum enMaleOrFemale
{
	Male = 1,
	Female = 2
};

struct stContact
{
	string ContactName;
	string PhoneNumber1;
	string PhoneNumber2;
	enMaleOrFemale Sex;
	string country;

};

void AppHeader()
{
	cout << "\n\n";
	cout << "\t\t\t\t--------------------------------------------------------\n\n";
	cout << "\t\t\t\t\t\tWelcome to Contact Book\n\n";
	cout << "\t\t\t\t--------------------------------------------------------\n\n\n";
}

enUserOptions ShowOptionsToUser()
{
	string message = "What do you want to do ? [1] Add Contact  [2] Remove Contact  [3] Search Contact";

	int input = ReadNumberInRange(1,3, message);

	return enUserOptions(input);

}




int main()
{
	AppHeader();
	ShowOptionsToUser();
}


