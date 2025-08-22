#pragma once
#include <iostream>
#include<array>
#include<string>

using namespace std;

int ReadNumberInRange(int From, int To,string message)
{
	int input = 0;
	do
	{
		cout << message << endl;
		cin >> input;

	} while (input < From || input > To);

	return input;

}