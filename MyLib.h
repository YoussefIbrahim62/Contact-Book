#pragma once
#include <iostream>
#include<array>
#include<string>

using namespace std;

int ValidateNumber()
{
	int Number;

	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nPlease enter a valid number\n";
		cin >> Number;
	}

	return Number;
}

int ReadNumberInRange(int From, int To,string message)
{
	int input = 0;
	do
	{
		cout << message << endl;
		input = ValidateNumber();

	} while (input < From || input > To);

	return input;

}